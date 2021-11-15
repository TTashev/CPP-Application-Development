/*
 * InputEvent.h
 *
 *  Created on: Oct 14, 2021
 *      Author: tomislav
 */

#ifndef SDL_UTILS_INPUTEVENT_H_
#define SDL_UTILS_INPUTEVENT_H_

#include "utils/input/EventDefines.h"
#include "utils/drawing/Point.h"

union SDL_Event;

class InputEvent
{
public:
	InputEvent() {};
	~InputEvent() {};

	int32_t init();
	void deinit();

	/* returns if OS event is pending */
	bool pollEvent();
	bool checkForExitRequest() const;

	/* Holds event position on the screen */
	Point pos = Point::UNDEFINED;
	/* See EventDefines.h for more information */
	int32_t key = Keyboard::KEY_UNKNOWN;
	uint8_t mouseButton = Mouse::UNKNOWN;
	TouchEvent type = TouchEvent::UNKNOWN;

private:
	void setEventTypeInternal();
private:

	/** Holds the OS communication event system */
	SDL_Event *_sdlEvent = nullptr;
};

#endif /* SDL_UTILS_INPUTEVENT_H_ */
