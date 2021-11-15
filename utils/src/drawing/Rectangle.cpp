/*
 * Rectangle.cpp
 *
 *  Created on: Oct 10, 2021
 *      Author: tomislav
 */

#include "utils/drawing/Rectangle.h"
#include <limits.h>

const Rectangle Rectangle::ZERO(0,0,0,0);
const Rectangle Rectangle::UNDEFINED(INT_MAX, INT_MAX, INT_MAX, INT_MAX);

Rectangle::Rectangle(int32_t p_x, int32_t p_y, int32_t p_w, int32_t p_h) :
		x(p_x), y(p_y), w(p_w), h(p_h)
{

}

bool Rectangle::operator==(const Rectangle& other) const
{
	return (x == other.x) && (y == other.y) && (w == other.w) && (h == other.h);
}

bool Rectangle::operator!=(const Rectangle& other) const
{
	return (x != other.x) && (y != other.y) && (w != other.w) && (h != other.h);
}

bool Rectangle::isPointInside(const Point& point) const
{
	const bool isInsideX = (this->x <= point.x) && (point.x < this->x + this->w);
	const bool isInsideY = (this->y <= point.y) && (point.y < this->y + this->h);

	return isInsideX && isInsideY;
}
