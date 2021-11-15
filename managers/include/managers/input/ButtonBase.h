/*
 * ButtonBase.h
 *
 *  Created on: Nov 2, 2021
 *      Author: tomislav
 */

#ifndef MANAGERS_INCLUDE_MANAGERS_INPUT_BUTTONBASE_H_
#define MANAGERS_INCLUDE_MANAGERS_INPUT_BUTTONBASE_H_

#include "managers/drawing/Image.h"

#include <cstdint>

struct InputEvent;

enum ButtonStates
{
	UNCLICKED, CLICKED, DISABLED
};

class ButtonBase : public Image
{
public:

	virtual ~ButtonBase() = default;

	virtual void handleEvent(const InputEvent& e) = 0;

	virtual void draw();

	void lockInput();
	void unlockInput();

	bool isInputUnlocked() const;

	bool containsEvent(const InputEvent& e);
private:
	Rectangle _boundRect = Rectangle::ZERO;
	bool _isInputUnlocked = true;
};

#endif /* MANAGERS_INCLUDE_MANAGERS_INPUT_BUTTONBASE_H_ */
