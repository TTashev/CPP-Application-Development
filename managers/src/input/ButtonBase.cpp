/*
 * ButtonBase.cpp
 *
 *  Created on: Nov 2, 2021
 *      Author: tomislav
 */

#include "managers/input/ButtonBase.h"
#include "sdl_utils/InputEvent.h"

#include <iostream>


void ButtonBase::draw()
{
	Image::draw();
}

void ButtonBase::lockInput()
{
	_isInputUnlocked = false;
	Image::setFrame(DISABLED);
}

void ButtonBase::unlockInput()
{
	_isInputUnlocked = true;
	Image::setFrame(UNCLICKED);
}

bool ButtonBase::isInputUnlocked() const
{
	return _isInputUnlocked;
}

bool ButtonBase::containsEvent(const InputEvent &e)
{
	return Image::containsPoint(e.pos);
}
