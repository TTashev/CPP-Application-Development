/*
 * MonitorWindow.h
 *
 *  Created on: Oct 11, 2021
 *      Author: tomislav
 */

#ifndef SDL_UTILS_MONITORWINDOW_H_
#define SDL_UTILS_MONITORWINDOW_H_

#include <cstdint>
#include <string>

#include "utils/drawing/Rectangle.h"
#include "sdl_utils/config/MonitorWindowCfg.h"

struct SDL_Window;
struct SDL_Surface;

class MonitorWindow
{
public:
	MonitorWindow() = default;
	~MonitorWindow() {};

	MonitorWindow(const MonitorWindow& other) = delete;
	MonitorWindow(MonitorWindow&& other) = delete;

	MonitorWindow& operator=(const MonitorWindow& other) = delete;
	MonitorWindow& operator=(MonitorWindow&& other) = delete;

	int32_t init(const MonitorWindowCfg& cfg);

	void deinit();

	void updateWindowSurface();

	SDL_Window* getWindow();

private:
	SDL_Window* _window = nullptr;
	Rectangle _window_rect = Rectangle::ZERO;
};

#endif /* SDL_UTILS_MONITORWINDOW_H_ */
