/*
 * Engine.h
 *
 *  Created on: Oct 14, 2021
 *      Author: tomislav
 */

#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_

#include <cstdint>

#include "game/Game.h"
#include "sdl_utils/InputEvent.h"
#include "managers/mgr/MgrHandler.h"
#include "managers/debug/DebugConsole.h"

struct EngineCfg;

class Engine
{
public:
	int32_t init(const EngineCfg& cfg);
	void deinit();
	void start();

private:
	void mainLoop();
	void drawFrame();
	bool processFrame();
	void handleEvent();

	void limitFPS(int64_t elapsedTimeMicroSeconds);

private:
	InputEvent _event;
	MgrHandler _mgrHandler;

	Game _game;
	DebugConsole _debugConsole;
};

#endif /* ENGINE_ENGINE_H_ */
