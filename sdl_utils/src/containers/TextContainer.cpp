/*
 * TextContainer.cpp
 *
 *  Created on: Oct 22, 2021
 *      Author: tomislav
 */

#include "sdl_utils/containers/TextContainer.h"

#include <iostream>

#include <SDL_ttf.h>
#include "sdl_utils/Texture.h"

int32_t TextContainer::init(const TextContainerCfg& cfg)
{
	TTF_Font * currentFont = nullptr;

	for(const auto& pair : cfg.fontConfigs)
	{
		const auto key = pair.first;
		const FontCfg& fontCfg = pair.second;
		currentFont = TTF_OpenFont(fontCfg.location.c_str(), fontCfg.fontSize);
		if(nullptr == currentFont)
		{
			std::cerr << "Error TTF_OpenFont failed for font location: "
					<< fontCfg.location << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
		}

		_fonts[key] = currentFont;
	}

	return EXIT_SUCCESS;
}

void TextContainer::deinit()
{
	for(auto& pair : _fonts)
	{
		TTF_CloseFont(pair.second);
	}
}

void TextContainer::createText(const std::string text, const Color& color,
						int32_t fontId, int32_t& textId, int32_t& textWidth,
						int32_t& textHeight)
{
	auto it = _fonts.find(fontId);
	if(it == _fonts.end())
	{
		std::cerr << "Error fontId: " << fontId << "could not be found!" << std::endl;
		return;
	}


	TTF_Font* font = it->second;

	occupyFreeSlotIndex(textId);
	if(EXIT_SUCCESS != Texture::createTextureFromText(text, color, font, _textures[textId], textWidth, textHeight))
	{
		std::cerr << "Error, createTextureFromText() for text: " << text << std::endl;
		Texture::freeTexture(_textures[textId]);
		return;
	}


}

void TextContainer::reloadText(const std::string text, const Color& color,
						int32_t fontId, int32_t textId, int32_t& textWidth,
						int32_t& textHeight)
{
	auto it = _fonts.find(fontId);
	if(it == _fonts.end())
	{
		std::cerr << "Error fontId: " << fontId << "could not be reloaded!" << std::endl;
		return;
	}


	TTF_Font* font = it->second;
	if(EXIT_SUCCESS != Texture::createTextureFromText(text, color, font, _textures[textId], textWidth, textHeight))
	{
		std::cerr << "Error, createTextureFromText() for text: " << text << std::endl;
		Texture::freeTexture(_textures[textId]);
		return;
	}

}

void TextContainer::unloadText(int32_t textId)
{
	if(textId >= static_cast<int32_t>(_textures.size()))
	{
		std::cerr << "Error, trying to unload non-existing textId: " << textId << std::endl;
		return;
	}

	Texture::freeTexture(_textures[textId]);
}

SDL_Texture* TextContainer::getTextTexture(int32_t textId) const
{
	if(0 > textId || textId >= static_cast<int32_t>(_textures.size()))
	{
		std::cerr << "Error, trying to get non-existing textId: " << textId << std::endl;
		return nullptr;
	}

	return _textures[textId];
}

void TextContainer::occupyFreeSlotIndex(int32_t& index)
{
	const int32_t size = static_cast<int32_t>(_textures.size());

	for (int32_t i = 0; i < size; ++i)
	{
		if(_textures[i] == nullptr)
		{
			index = i;
			return;
		}
	}

	_textures.push_back(nullptr);
	index = size;

}

void TextContainer::freeSlotIndex(int32_t index)
{
	Texture::freeTexture(_textures[index]);
}
