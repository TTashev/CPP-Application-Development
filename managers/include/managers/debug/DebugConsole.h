/*
 * DebugConsole.h
 *
 *  Created on: Nov 9, 2021
 *      Author: tomislav
 */

#ifndef MANAGERS_INCLUDE_MANAGERS_DEBUG_DEBUGCONSOLE_H_
#define MANAGERS_INCLUDE_MANAGERS_DEBUG_DEBUGCONSOLE_H_

#include "managers/drawing/Text.h"

class InputEvent;

enum DebugTextsIdx
{
	FPS_TEXT_IDX,
	ACTIVE_TIMER_IDX,
	ACTIVE_WIDGETS_IDX,

	DEBUG_TEXT_COUNT
};

class DebugConsole
{
public:
	int32_t init(int64_t p_maxFrames, int32_t p_fontId);
	void handleEvent(const InputEvent& e);
	void draw();
	bool isActive() const;
	void update(int64_t p_elapsedTimeMicroSeconds, int64_t p_activeTimers);

private:
	Text _debugTexts[DEBUG_TEXT_COUNT];
	int64_t _maxFrames = 0;
	int32_t _updateConunter = 0;
	bool _isActive = false;
};

#endif /* MANAGERS_INCLUDE_MANAGERS_DEBUG_DEBUGCONSOLE_H_ */
