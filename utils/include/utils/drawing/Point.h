/*
 * Point.h
 *
 *  Created on: Oct 10, 2021
 *      Author: tomislav
 */

#ifndef UTILS_DRAWING_POINT_H_
#define UTILS_DRAWING_POINT_H_

#include <cstdint>

#include "Point.h"

struct Point
{
	Point() = default;
	Point(int32_t p_x, int32_t p_y);

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;

	int32_t x = 0;
	int32_t y = 0;

	static const Point ZERO;
	static const Point UNDEFINED;
};


#endif /* UTILS_DRAWING_POINT_H_ */
