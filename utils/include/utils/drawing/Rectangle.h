/*
 * Rectangle.h
 *
 *  Created on: Oct 10, 2021
 *      Author: tomislav
 */

#ifndef UTILS_DRAWING_RECTANGLE_H_
#define UTILS_DRAWING_RECTANGLE_H_

#include <cstdint>

#include "utils/drawing/Point.h"

class Rectangle
{
public:
	Rectangle() = default;
	Rectangle(int32_t p_x, int32_t p_y, int32_t p_w, int32_t p_h);

	bool operator==(const Rectangle& other) const;
	bool operator!=(const Rectangle& other) const;

	bool isPointInside(const Point& point) const;

	int32_t x = 0;
	int32_t y = 0;
	int32_t w = 0;
	int32_t h = 0;

	static const Rectangle ZERO;
	static const Rectangle UNDEFINED;
};


#endif /* UTILS_DRAWING_RECTANGLE_H_ */
