/*
 * Engine.cpp
 *
 *  Created on: Oct 14, 2021
 *      Author: tomislav
 */

#include "engine/Engine.h"

#include <iostream>

#include "engine/config/EngineConfig.h"
#include "managers/mgr/DrawMgr.h"
#include "managers/mgr/TimerMgr.h"

#include "utils/thread/ThreadUtils.h"
#include "utils/time/Time.h"

#include "sdl_utils/Texture.h"
#include "utils/drawing/Color.h"

int32_t Engine::init(const EngineCfg& cfg)
{

	if(EXIT_SUCCESS != _mgrHandler.init(cfg.managerHandlerCfg))
	{
		std::cerr << "_mgrHandler failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _event.init())
	{
		std::cerr << "InputEvent failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _game.init(cfg.gameCfg))
	{
		std::cerr << "Game init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _debugConsole.init(cfg.managerHandlerCfg.drawMgrCfg.MaxFPS, cfg.debugConsoleFontId))
	{
		std::cerr << "_debugConsole init() failed" << std::endl;
		return EXIT_FAILURE;
	}


	gTimerMgr->onInitEnd();

	return EXIT_SUCCESS;
}

void Engine::deinit()
{
	_game.deinit();
	_event.deinit();
	_mgrHandler.deinit();
}

void Engine::start()
{
	mainLoop();
}


void Engine::mainLoop()
{
	Time time;

	while(true)
	{
		time.getElapsed();
		const bool shouldExit = processFrame();
		if(shouldExit)
		{
			break;
		}

		if(_debugConsole.isActive())
		{
			_debugConsole.update(time.getElapsed().toMicroseconds(), gTimerMgr->getActiveTimersCount());
		}

		limitFPS(time.getElapsed().toMicroseconds());
	}
}

void Engine::drawFrame()
{
	gDrawMgr->clearScreen();

	_game.draw();
	if(_debugConsole.isActive())
	{
		_debugConsole.draw();
	}

	gDrawMgr->finishFrame();
}

bool Engine::processFrame()
{
	_mgrHandler.process();

	while(_event.pollEvent())
	{
		if(_event.checkForExitRequest())
		{
			return true;
		}

		handleEvent();
	}

	drawFrame();

	return false;
}

void Engine::handleEvent()
{
	_game.handleEvent(_event);
	_debugConsole.handleEvent(_event);
}

void Engine::limitFPS(int64_t elapsedTimeMicroSeconds)
{
	constexpr int64_t microSecondsInASecond = 1000000;
	const int64_t microSecondsPerFrame = microSecondsInASecond / gDrawMgr->getMaxFrames();
	const int64_t sleepDurationMicroseconds = microSecondsPerFrame - elapsedTimeMicroSeconds;

	if(sleepDurationMicroseconds > 0)
	{
		ThreadUtils::sleepFor(sleepDurationMicroseconds);
	}
}

