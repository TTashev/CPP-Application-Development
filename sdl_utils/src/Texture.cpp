/*
 * Texture.cpp
 *
 *  Created on: Oct 12, 2021
 *      Author: tomislav
 */

#include "sdl_utils/Texture.h"
#include <iostream>

#include <SDL_surface.h>
#include <SDL_image.h>
#include <SDL_render.h>
#include <SDL_ttf.h>

#include "utils/drawing/Color.h"

static SDL_Renderer* gRenderer = nullptr;

int32_t Texture::createSurfaceFromFile(const std::string& filePath, SDL_Surface*& surface)
{
	surface = IMG_Load(filePath.c_str());

	if(nullptr == surface)
	{
		std::cerr << "IMG_Load() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int32_t Texture::createTextureFromFile(const std::string& filePath, SDL_Texture*& texture)
{
	SDL_Surface* surface = nullptr;
	if(EXIT_SUCCESS != createSurfaceFromFile(filePath, surface))
	{
		std::cerr << "createSurfaceFromFile() failed for filePath: " << filePath << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != createTextureFromSurface(surface, texture))
	{
		std::cerr << "createTextureFromSurface() failed for filePath: " << filePath << std::endl;
		return EXIT_FAILURE;
	}

	freeSurface(surface);

	return EXIT_SUCCESS;
}

int32_t Texture::createTextureFromSurface(SDL_Surface*& surface, SDL_Texture*& texture)
{
	texture = SDL_CreateTextureFromSurface(gRenderer, surface);

	if(nullptr == texture)
	{
		std::cerr << "SDL_CreateTextureFromSurface() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	freeSurface(surface);

	return EXIT_SUCCESS;
}

int32_t Texture::createTextureFromText(const std::string text, const Color& color,
															TTF_Font* font,
															SDL_Texture*& texture,
															int32_t& textWidth,
															int32_t& textHeight)
{
	const SDL_Color* sdlColor = reinterpret_cast<const SDL_Color*>(&color.rgba);

	SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), *sdlColor);

	if(nullptr == textSurface)
	{
		std::cerr << "TTF_RenderText_Blended() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	textWidth = textSurface->w;
	textHeight = textSurface->h;

	if(EXIT_SUCCESS != Texture::createTextureFromSurface(textSurface, texture))
	{
		std::cerr << "createTextureFromSurface() failed for text: " << text << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Texture::freeSurface(SDL_Surface*& surface)
{
	if(surface != nullptr)
	{
		SDL_FreeSurface(surface);
		surface = nullptr;
	}
}

void Texture::freeTexture(SDL_Texture*& texture)
{
	if(texture != nullptr)
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

void Texture::setRenderer(SDL_Renderer* renderer)
{
	gRenderer = renderer;
}

int32_t Texture::setBlendModeTexture(SDL_Texture *texture,BlendMode blendMode)
{
	if(EXIT_SUCCESS != SDL_SetTextureBlendMode(texture,static_cast<SDL_BlendMode>(blendMode)))
	{
		std::cerr << "SDL_SetTextureBlendMode() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int32_t Texture::setAlphaTexture(SDL_Texture *texture, int32_t alpha)
{
	if(ZERO_OPACITY > alpha || alpha > FULL_OPACITY)
	{
		std::cerr << "Error invalid alpha value: " << alpha << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != SDL_SetTextureAlphaMod(texture,static_cast<uint8_t>(alpha)))
	{
		std::cerr << "SDL_SetTextureAlphaMod() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
