/*
 * Point.cpp
 *
 *  Created on: Oct 10, 2021
 *      Author: tomislav
 */

#include "utils/drawing/Point.h"
#include <limits.h>

const Point Point::ZERO(0,0);
const Point Point::UNDEFINED(INT_MAX, INT_MAX);

Point::Point(int32_t p_x, int32_t p_y) : x(p_x), y(p_y)
{

}

bool Point::operator==(const Point& other) const
{
	return (x == other.x) && (y == other.y);
}

bool Point::operator!=(const Point& other) const
{
	return (x != other.x) && (y != other.y);
}
