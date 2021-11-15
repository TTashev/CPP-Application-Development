/*
 * Widget.h
 *
 *  Created on: Oct 30, 2021
 *      Author: tomislav
 */

#ifndef MANAGERS_INCLUDE_MANAGERS_DRAWING_WIDGET_H_
#define MANAGERS_INCLUDE_MANAGERS_DRAWING_WIDGET_H_

#include <cstdint>
#include "utils/drawing/DrawParams.h"

class Widget
{
public:
	void draw();
	//setters & getters

	void reset();

	void setFlipType(WidgetFlip p_flipType);

	void setWidth(int32_t p_width);
	void setHeight(int32_t p_height);

	void setRotationCenter(const Point& p_pos);

	void setRotation(double p_angle);
	double getRotation() const;

	void rotateRight(double delta);
	void rotateLeft(double delta);

	int32_t getWidth() const;
	int32_t getHeight() const;

	void setPosition(const Point& p_pos);
	void setPosition(int32_t p_x, int32_t p_y);
	void setOpacity(int32_t p_opacity);

	int32_t getOpacity() const;
	Point getPosition() const;

	void activateAlphaModulation();
	void deactivateAlphaModulation();

	void show();
	void hide();

	void moveRight(int32_t p_delta);
	void moveLeft(int32_t p_delta);
	void moveUp(int32_t p_delta);
	void moveDown(int32_t p_delta);

	bool containsPoint(const Point& p_pos) const;
	bool isVisible() const;
protected:
	DrawParams _drawParams;

	bool _isCreated = false;
	bool _isDestroyed = true;
	bool _isVisible = true;
	bool _isAlphaModulationEnabled = false;
};

#endif /* MANAGERS_INCLUDE_MANAGERS_DRAWING_WIDGET_H_ */
