/*
 * MonitorWindowCfg.h
 *
 *  Created on: Oct 11, 2021
 *      Author: tomislav
 */

#ifndef SDL_UTILS_CONFIG_MONITORWINDOWCFG_H_
#define SDL_UTILS_CONFIG_MONITORWINDOWCFG_H_

#include <cstdint>
#include <string>

#include "utils/drawing/Point.h"

enum E_WINDOW_FLAGS
{
	WINDOW_SHOWN = 4, //SDL_WINDOW_SHOWN
	WINDOW_FULLSCREEN_DESKTOP = 4097 // SDL_WINDOW_FULLSCREEN_DESKTOP
};

struct MonitorWindowCfg
{
	std::string windowName;
	Point 		windowPos = Point::UNDEFINED;
	int32_t 	windowWidth = 0;
	int32_t		windowHeight = 0;
	E_WINDOW_FLAGS 	windowFlags = WINDOW_SHOWN;
};

#endif /* SDL_UTILS_CONFIG_MONITORWINDOWCFG_H_ */
