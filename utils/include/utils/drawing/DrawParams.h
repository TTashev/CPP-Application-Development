/*
 * DrawParams.h
 *
 *  Created on: Oct 20, 2021
 *      Author: tomislav
 */

#ifndef UTILS_DRAWING_DRAWPARAMS_H_
#define UTILS_DRAWING_DRAWPARAMS_H_

#include <cstdint>
#include "utils/drawing/Point.h"
#include "utils/drawing/Rectangle.h"

inline constexpr auto INVALID_RSRC_ID = -1;

inline constexpr int32_t FULL_OPACITY = 255;
inline constexpr int32_t ZERO_OPACITY = 0;
inline constexpr int32_t FULL_ROTATION = 360;

enum class BlendMode : uint8_t
{
	NONE 	= 0, //value for SDL_BLEND_NONE
	BLEND 	= 1, //value for SDL_BLEND_BLEND
	ADD		= 2, //value for SDL_BLEND_ADD
	MOD		= 4  //value for SDL_BLEND_MODE
};

enum class WidgetFlip : uint8_t
{
	NONE,
	HORIZONTAL,
	VERTICAL,
	HORIZONTAL_AND_VERTICAL
};

enum class WidgetType : uint8_t
{
	IMAGE,
	TEXT,
	UNKNOWN
};

struct DrawParams
{
	void reset();

	Rectangle frameRect = Rectangle::ZERO;

	//Top left position of texture
	Point pos = Point::UNDEFINED;

	double rotationAngle = 0.0;
	Point rotationCenter = Point::ZERO;

	//Draw dimensions of the texture
	int32_t width = 0;
	int32_t height = 0;

	int32_t opacity = FULL_OPACITY;

	//unique resourceId

	union
	{
		int32_t rsrcId = INVALID_RSRC_ID;
		int32_t textId;
	};

	WidgetType widgetType = WidgetType::UNKNOWN;

	WidgetFlip flipType = WidgetFlip::NONE;
};


#endif /* UTILS_DRAWING_DRAWPARAMS_H_ */
