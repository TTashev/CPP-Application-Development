/*
 * ImageContainer.cpp
 *
 *  Created on: Oct 20, 2021
 *      Author: tomislav
 */

#include "sdl_utils/containers/ImageContainer.h"
#include "sdl_utils/config/ImageContainerCfg.h"
#include "utils/drawing/DrawParams.h"
#include "sdl_utils/Texture.h"

#include <iostream>

static const Frames EMPTY_FRAMES {Rectangle::ZERO};

int32_t ImageContainer::init(const ImageContainerCfg& cfg)
{
	for(const auto& pair : cfg.imageConfigs)
	{
		const auto& element = pair.second;
		const auto& rsrcId = pair.first;
		if(EXIT_SUCCESS != loadSingleResource(element, rsrcId))
		{
			std::cerr << "createSurfaceFromFile for file: " << element.location << std::endl;
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}

void ImageContainer::deinit()
{
	for(auto& pair : _textures)
	{
		Texture::freeTexture(pair.second);
	}
}

SDL_Texture* ImageContainer::getImageTexture(int32_t rsrcId) const
{
	auto it = _textures.find(rsrcId);
	if(it == _textures.end())
	{
		std::cerr << "Error, invalid rsrcId: " << rsrcId << " requested" << std::endl;
		return nullptr;
	}

	return it->second;
}

const Frames& ImageContainer::getImageFrame(int32_t rsrcId) const
{
	auto it = _textureFrames.find(rsrcId);
	if(it == _textureFrames.end())
	{
		std::cerr << "Error, invalid rsrcId: " << rsrcId << " requested. Returning EMPTY_FRAMES" << std::endl;
		return EMPTY_FRAMES;
	}

	return it->second;
}

int32_t ImageContainer::loadSingleResource(const ImageCfg& imgCfg, int32_t rsrcID)
{
	SDL_Texture * texture = nullptr;
	if(EXIT_SUCCESS != Texture::createTextureFromFile(imgCfg.location, texture))
	{
		std::cerr << "createSurfaceFromFile for file: " << imgCfg.location << std::endl;
		return EXIT_FAILURE;
	}

	_textures[rsrcID] = texture;
	_textureFrames[rsrcID] = imgCfg.frames;


	return EXIT_SUCCESS;
}
