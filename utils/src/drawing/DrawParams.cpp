/*
 * DrawParams.h
 *
 *  Created on: Oct 20, 2021
 *      Author: tomislav
 */

#include "utils/drawing/DrawParams.h"

void DrawParams::reset()
{
	frameRect = Rectangle::ZERO;

	pos = Point::UNDEFINED;

	rotationAngle = 0.0;

	width = 0;
	height = 0;

	opacity = FULL_OPACITY;

	rsrcId = INVALID_RSRC_ID;

	widgetType = WidgetType::UNKNOWN;
}

