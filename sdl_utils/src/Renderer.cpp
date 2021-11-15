/*
 * Renderer.cpp
 *
 *  Created on: Oct 18, 2021
 *      Author: tomislav
 */

#include "sdl_utils/Renderer.h"

#include <cstdlib>
#include <iostream>

#include <SDL_render.h>
#include <SDL_hints.h>

#include "sdl_utils/Texture.h"


int32_t Renderer::init(SDL_Window *window)
{
	if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		std::cerr << "Warning: Linear texture filtering not enabled! "
				"SDL_SetHint() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	constexpr auto unspecifiedDriverID = -1;
	_sdlRenderer = SDL_CreateRenderer(window, unspecifiedDriverID, SDL_RENDERER_ACCELERATED);
	if(nullptr == _sdlRenderer)
	{
		std::cerr << "SDL_CreateRenderer() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != SDL_SetRenderDrawColor(_sdlRenderer, 0, 0, 255, SDL_ALPHA_OPAQUE))
	{
		std::cerr << "SDL_SetRenderDrawColor() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	Texture::setRenderer(_sdlRenderer);

	return EXIT_SUCCESS;
}

void Renderer::deinit()
{
	if(_sdlRenderer != nullptr)
	{
		SDL_DestroyRenderer(_sdlRenderer);
		_sdlRenderer = nullptr;
	}
}

void Renderer::clearScreen()
{
	if(EXIT_SUCCESS != SDL_RenderClear(_sdlRenderer))
	{
		std::cerr << "SDL_RenderClear() failed. Reason: " << SDL_GetError() << std::endl;
	}
}

void Renderer::finishFrame()
{
	SDL_RenderPresent(_sdlRenderer);
}

void Renderer::renderTexture(SDL_Texture *texture, const DrawParams& drawParams)
{
	if(WidgetType::IMAGE == drawParams.widgetType)
	{
		drawImage(drawParams, texture);
	}
	else if(WidgetType::TEXT == drawParams.widgetType)
	{
		drawText(drawParams, texture);
	}
	else
	{
		std::cerr << "Error, received unsupported WidgeType: "
				<< static_cast<int32_t>(drawParams.widgetType) << "for rsrcID: "
				<< drawParams.rsrcId << std::endl;
	}
}

void Renderer::setWidgetBlendMode(SDL_Texture* texture,
		BlendMode blendMode)
{
	if(EXIT_SUCCESS != Texture::setBlendModeTexture(texture, blendMode))
	{
		std::cerr << "setBlendModeTexture failed" << std::endl;
	}
}

void Renderer::setWidgetOpacity(SDL_Texture* texture, int32_t opacity)
{
	if(EXIT_SUCCESS != Texture::setAlphaTexture(texture, opacity))
	{
		std::cerr << "setAlphaTexture failed" << std::endl;
	}
}

void Renderer::drawImage(const DrawParams& drawParams, SDL_Texture *texture)
{

	if(FULL_OPACITY == drawParams.opacity)
	{
		drawTextureInternal(drawParams, texture);
	}
	else
	{
		if(EXIT_SUCCESS != Texture::setAlphaTexture(texture, drawParams.opacity))
		{
			std::cerr << "Texture::setAlphaTexture() failed for rsrcID: " << drawParams.rsrcId << std::endl;
		}

		drawTextureInternal(drawParams, texture);

		if(EXIT_SUCCESS != Texture::setAlphaTexture(texture, FULL_OPACITY))
		{
			std::cerr << "Texture::setAlphaTexture() failed for rsrcID: " << drawParams.rsrcId << std::endl;
		}
	}

}

void Renderer::drawText(const DrawParams& drawParams, SDL_Texture *texture)
{
	drawTextureInternal(drawParams, texture);
}

void Renderer::drawTextureInternal(const DrawParams &drawParams,
		SDL_Texture *texture)
{
	const SDL_Rect destRect = {.x = drawParams.pos.x, .y = drawParams.pos.y,
								.w = drawParams.width, .h = drawParams.height};

	const SDL_Rect* sourceRect = reinterpret_cast<const SDL_Rect*>(&drawParams.frameRect);

	const SDL_Point* center = reinterpret_cast<const SDL_Point*>(&drawParams.rotationCenter);

	const int32_t err = SDL_RenderCopyEx(_sdlRenderer, texture,
				sourceRect, &destRect, drawParams.rotationAngle, center, static_cast<SDL_RendererFlip>(drawParams.flipType));

	if(EXIT_SUCCESS != err)
	{
		std::cerr << "SDL_RenderCopy() failed for rsrcID:" << drawParams.rsrcId
				<< " Reason: " << SDL_GetError() << std::endl;
	}

}
