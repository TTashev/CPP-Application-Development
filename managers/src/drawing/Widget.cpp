/*
 * Widget.cpp
 *
 *  Created on: Oct 30, 2021
 *      Author: tomislav
 */

#include "managers/drawing/Widget.h"

#include <iostream>

#include "managers/mgr/DrawMgr.h"


void Widget::draw()
{
	if(_isVisible)
	{
		gDrawMgr->addDrawCmd(_drawParams);
	}
}

void Widget::reset()
{
	_isCreated = false;
	_isDestroyed = true;
	_isVisible = true;
	_isAlphaModulationEnabled = false;

	_drawParams.reset();
}

void Widget::setFlipType(WidgetFlip p_flipType)
{
	_drawParams.flipType = p_flipType;
}

void Widget::setWidth(int32_t p_width)
{
	_drawParams.width = p_width;
}

void Widget::setHeight(int32_t p_height)
{
	_drawParams.height = p_height;
}

void Widget::setRotationCenter(const Point& p_pos)
{
	_drawParams.rotationCenter = p_pos;
}

void Widget::setRotation(double p_angle)
{
	_drawParams.rotationAngle = p_angle;
}

double Widget::getRotation() const
{
	return _drawParams.rotationAngle;
}

void Widget::rotateRight(double p_delta)
{
	_drawParams.rotationAngle += p_delta;

	while(_drawParams.rotationAngle > FULL_ROTATION)
	{
		_drawParams.rotationAngle -= FULL_ROTATION;
	}
}

void Widget::rotateLeft(double p_delta)
{
	_drawParams.rotationAngle -= p_delta;

	while(_drawParams.rotationAngle < 0)
	{
		_drawParams.rotationAngle += FULL_ROTATION;
	}
}

int32_t Widget::getWidth() const
{
	return _drawParams.width;
}

int32_t Widget::getHeight() const
{
	return _drawParams.height;
}

void Widget::setPosition(const Point &p_pos)
{
	_drawParams.pos = p_pos;
}

void Widget::setPosition(int32_t p_x, int32_t p_y)
{
	_drawParams.pos.x = p_x;
	_drawParams.pos.y = p_y;
}

void Widget::setOpacity(int32_t p_opacity)
{
	if(!_isAlphaModulationEnabled)
	{
		std::cerr << "alpha mode was not enabled for rsrcId: " << _drawParams.rsrcId <<
				"opacity will remain the same" << std::endl;
		return;
	}

	if(p_opacity <= 0)
	{
		std::cerr << "cannot set opacity less than zero rsrcId:  " << _drawParams.rsrcId << std::endl;
		return;
	}

	_drawParams.opacity = p_opacity;
	gDrawMgr->setWidgetOpacity(_drawParams, p_opacity);
}

int32_t Widget::getOpacity() const
{
	return _drawParams.opacity;
}

Point Widget::getPosition() const
{
	return _drawParams.pos;
}

void Widget::activateAlphaModulation()
{
	if(_isAlphaModulationEnabled)
	{
		std::cerr << "alpha mode was already enabled for rsrcId: " << _drawParams.rsrcId << std::endl;
		return;
	}

	_isAlphaModulationEnabled = true;
	gDrawMgr->setWidgetBlendMode(_drawParams, BlendMode::BLEND);
}

void Widget::deactivateAlphaModulation()
{
	if(!_isAlphaModulationEnabled)
	{
		std::cerr << "alpha mode was not enabled for rsrcId: " << _drawParams.rsrcId << std::endl;
		return;
	}

	_isAlphaModulationEnabled = false;
	gDrawMgr->setWidgetBlendMode(_drawParams, BlendMode::NONE);
}

void Widget::show()
{
	_isVisible = true;
}

void Widget::hide()
{
	_isVisible = false;
}

void Widget::moveRight(int32_t p_delta)
{
	_drawParams.pos.x += p_delta;
}

void Widget::moveLeft(int32_t p_delta)
{
	_drawParams.pos.x -= p_delta;
}

void Widget::moveUp(int32_t p_delta)
{
	_drawParams.pos.y -= p_delta;
}

void Widget::moveDown(int32_t p_delta)
{
	_drawParams.pos.y += p_delta;
}

bool Widget::containsPoint(const Point& p_pos) const
{
	const Rectangle bound(_drawParams.pos.x, _drawParams.pos.y,
							_drawParams.width, _drawParams.height);

	return bound.isPointInside(p_pos);
}

bool Widget::isVisible() const
{
	return _isVisible;
}
