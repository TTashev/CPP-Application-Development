/*
 * TextContainerCfg.h
 *
 *  Created on: Oct 22, 2021
 *      Author: tomislav
 */

#ifndef SDL_UTILS_CONFIG_TEXTCONTAINERCFG_H_
#define SDL_UTILS_CONFIG_TEXTCONTAINERCFG_H_


#include <cstdint>
#include <unordered_map>

struct FontCfg
{
	std::string location;
	int32_t fontSize = 0;
};

struct TextContainerCfg
{
	std::unordered_map<int32_t, FontCfg> fontConfigs;
};


#endif /* SDL_UTILS_CONFIG_TEXTCONTAINERCFG_H_ */
