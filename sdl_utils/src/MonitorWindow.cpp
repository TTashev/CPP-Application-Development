/*
 * MonitorWindow.cpp
 *
 *  Created on: Oct 11, 2021
 *      Author: tomislav
 */

#include "sdl_utils/MonitorWindow.h"

#include <iostream>

#include <SDL_video.h>

int32_t MonitorWindow::init(const MonitorWindowCfg& cfg)
{
	Point windowPos;
	if(cfg.windowPos == Point::UNDEFINED)
	{
		windowPos.x = SDL_WINDOWPOS_UNDEFINED;
		windowPos.y = SDL_WINDOWPOS_UNDEFINED;
	}
	else
	{
		windowPos = cfg.windowPos;
	}

	_window = SDL_CreateWindow(cfg.windowName.c_str(), windowPos.x, windowPos.y, cfg.windowWidth,
			cfg.windowHeight, cfg.windowFlags);
	if(nullptr == _window)
	{
		std::cerr << "SDL_CreateWindow() failed. Reason: " << SDL_GetError() << std::endl;
	}

	return EXIT_SUCCESS;
}

void MonitorWindow::deinit()
{
	if(_window != nullptr)
	{
		SDL_DestroyWindow(_window);
		_window = nullptr;
	}
}

void MonitorWindow::updateWindowSurface()
{
	if(EXIT_SUCCESS != SDL_UpdateWindowSurface(_window))
	{
		std::cerr << "SDL_UpdateWindowSurface() failed. Reason: " << SDL_GetError() << std::endl;
	}
}

SDL_Window* MonitorWindow::getWindow()
{
	return _window;
}
