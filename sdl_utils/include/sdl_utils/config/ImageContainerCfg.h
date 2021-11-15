/*
 * ImageContainerCfg.h
 *
 *  Created on: Oct 20, 2021
 *      Author: tomislav
 */

#ifndef SDL_UTILS_CONFIG_IMAGECONTAINERCFG_H_
#define SDL_UTILS_CONFIG_IMAGECONTAINERCFG_H_

#include <cstdint>
#include <unordered_map>
#include <vector>
#include "utils/drawing/Rectangle.h"

struct ImageCfg
{
	std::string location;
	std::vector<Rectangle> frames;
};

struct ImageContainerCfg
{
	std::unordered_map<int32_t, ImageCfg> imageConfigs;
};

#endif /* SDL_UTILS_CONFIG_IMAGECONTAINERCFG_H_ */
