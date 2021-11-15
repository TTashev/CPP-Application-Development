/*
 * InputEvent.cpp
 *
 *  Created on: Oct 14, 2021
 *      Author: tomislav
 */

#include "sdl_utils/InputEvent.h"

#include <iostream>
#include <cstring>

#include <SDL_events.h>

int32_t InputEvent::init()
{
	_sdlEvent = new SDL_Event();
	memset(_sdlEvent, 0, sizeof(SDL_Event));
	if(_sdlEvent == nullptr)
	{
		std::cerr << "Bad alloc for SDL_Event()" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void InputEvent::deinit()
{
	if(_sdlEvent != nullptr)
	{
		delete _sdlEvent;
		_sdlEvent = nullptr;
	}
}

bool InputEvent::pollEvent()
{
	// fix to SDL_PollEvent if nessesary
	if(0 ==SDL_PollEvent(_sdlEvent))
	{
		// no events pending
		return false;
	}

	SDL_GetMouseState(&pos.x, &pos.y);
	setEventTypeInternal();

	return true;
}

void InputEvent::setEventTypeInternal()
{
	switch (_sdlEvent->type)
	{
		case EventType::KEYBOARD_PRESS:
			key = _sdlEvent->key.keysym.sym;
			mouseButton = Mouse::UNKNOWN;
			type = TouchEvent::KEYBOARD_PRESS;
		break;

		case EventType::KEYBOARD_RELEASE:
			key = _sdlEvent->key.keysym.sym;
			mouseButton = Mouse::UNKNOWN;
			type = TouchEvent::KEYBOARD_RELEASE;
		break;

			//NOTE: the fall-through is intentional
		case EventType::MOUSE_PRESS:
			key = Keyboard::KEY_UNKNOWN;
			mouseButton = _sdlEvent->button.button;
			type = TouchEvent::TOUCH_PRESS;
		break;

		case EventType::FINGER_PRESS:
			key = Keyboard::KEY_UNKNOWN;
			mouseButton = Mouse::LEFT_BUTTON;
			type = TouchEvent::TOUCH_PRESS;
		break;

		case EventType::MOUSE_RELEASE:
			key = Keyboard::KEY_UNKNOWN;
			mouseButton = _sdlEvent->button.button;
			type = TouchEvent::TOUCH_RELEASE;
		break;

		case EventType::FINGER_RELEASE:
			key = Keyboard::KEY_UNKNOWN;
			mouseButton = Mouse::UNKNOWN;
			type = TouchEvent::TOUCH_PRESS;
		break;

			//X is pressed on the window (or CTRL-C signal is sent)
		case EventType::QUIT:
			key = Keyboard::KEY_UNKNOWN;
			mouseButton = Mouse::UNKNOWN;
			type = TouchEvent::UNKNOWN;
		break;

		default:
			key = Keyboard::KEY_UNKNOWN;
			mouseButton = Mouse::UNKNOWN;
			type = TouchEvent::UNKNOWN;
		break;
	}
}

bool InputEvent::checkForExitRequest() const
{
	return (_sdlEvent->type == EventType::QUIT) ||
			(type == TouchEvent::KEYBOARD_PRESS && Keyboard::KEY_ESCAPE == key);
}

