/*
 * Image.h
 *
 *  Created on: Oct 30, 2021
 *      Author: tomislav
 */

#ifndef MANAGERS_INCLUDE_MANAGERS_DRAWING_IMAGE_H_
#define MANAGERS_INCLUDE_MANAGERS_DRAWING_IMAGE_H_

#include "managers/drawing/Widget.h"

class Image : public Widget
{
public:
	~Image();

	void create(int32_t p_rsrcId, const Point& p_pos = Point::ZERO);
	void destroy();

	void setFrame(int32_t frameIdx);
	void setNextFrame();
	void setPrevFrame();
	int32_t getFrame() const;

private:
	int32_t _currFrame { 0 };
	int32_t _maxFrames { 0 };
	bool _isDestroyed = false;
};

#endif /* MANAGERS_INCLUDE_MANAGERS_DRAWING_IMAGE_H_ */
