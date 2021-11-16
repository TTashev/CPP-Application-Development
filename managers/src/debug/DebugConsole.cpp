/*
 * DebugConsole.cpp
 *
 *  Created on: Nov 9, 2021
 *      Author: tomislav
 */

#include "managers/debug/DebugConsole.h"
#include "utils/drawing/Color.h"
#include "sdl_utils/InputEvent.h"
#include <iostream>

int32_t DebugConsole::init(int64_t p_maxFrames, int32_t p_fontId)
{
	_maxFrames = p_maxFrames;

	Point textPos = Point(0,20);
	_debugTexts[FPS_TEXT_IDX].create("0", p_fontId, Colors::RED, textPos);

	textPos.y += 40;
	_debugTexts[ACTIVE_TIMER_IDX].create("0", p_fontId, Colors::RED, textPos);

	textPos.y += 40;
	_debugTexts[ACTIVE_WIDGETS_IDX].create("0", p_fontId, Colors::RED, textPos);

	return EXIT_SUCCESS;
}

void DebugConsole::handleEvent(const InputEvent &e)
{
	if(e.type != TouchEvent::KEYBOARD_PRESS)
	{
		return;
	}

	if(e.key == Keyboard::KEY_TILDA)
	{
		_isActive = !_isActive;
	}
}

void DebugConsole::draw()
{
	for (int32_t i = 0; i < DEBUG_TEXT_COUNT; ++i)
	{
		_debugTexts[i].draw();
	}
}

bool DebugConsole::isActive() const
{
	return _isActive;
}

void DebugConsole::update(int64_t p_elapsedTimeMicroSeconds, int64_t p_activeTimers)
{
	constexpr int64_t microSecondsInASecond = 1000000;
	int64_t currentFPS = microSecondsInASecond / p_elapsedTimeMicroSeconds;
	if(currentFPS > _maxFrames)
	{
		currentFPS = _maxFrames;
	}

	std::string textContent = "FPS: ";
	textContent.append(std::to_string(currentFPS));
	_debugTexts[FPS_TEXT_IDX].setText(textContent);

	textContent = "Active Timers: ";
	textContent.append(std::to_string(p_activeTimers));
	_debugTexts[ACTIVE_TIMER_IDX].setText(textContent);
}
