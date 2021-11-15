/*
 * Image.cpp
 *
 *  Created on: Oct 30, 2021
 *      Author: tomislav
 */

#include "managers/drawing/Image.h"

#include <iostream>

#include "managers/mgr/RsrcMgr.h"

Image::~Image()
{
	if(_isCreated && !_isDestroyed)
	{
		destroy();
	}
}

void Image::create(int32_t p_rsrcId, const Point& p_pos)
{
	if(_isCreated)
	{
		std::cerr << "Error, image with rsrcId: " << p_rsrcId << "already created!" << std::endl;
		return;
	}

	const Frames& frames = gRsrcMgr->getImageFrame(p_rsrcId);
	_maxFrames = static_cast<int32_t>(frames.size());
	const auto& firstFrame = frames.front();
	_drawParams.frameRect = firstFrame;

	_drawParams.rsrcId = p_rsrcId;
	_drawParams.width = _drawParams.frameRect.w;
	_drawParams.height = _drawParams.frameRect.h;
	_drawParams.pos = p_pos;
	_drawParams.widgetType = WidgetType::IMAGE;

	_isCreated = true;
	_isDestroyed = false;
}

void Image::destroy()
{
	if(!_isCreated)
	{
		std::cerr << "Error, image already destroyed!" << std::endl;
		return;
	}
	_isCreated = false;
	_isDestroyed = true;

	Widget::reset();
}

void Image::setFrame(int32_t frameIdx)
{
	if(0 > frameIdx || frameIdx >= _maxFrames)
	{
		std::cerr << "Error, invalid frameId: " << frameIdx
				<< "for rsrcId: " << _drawParams.rsrcId << std::endl;
		return;
	}

	const Frames& frames = gRsrcMgr->getImageFrame(_drawParams.rsrcId);
	_drawParams.frameRect = frames[frameIdx];

	_currFrame = frameIdx;
}

void Image::setNextFrame()
{
	_currFrame++;
	if(_currFrame == _maxFrames)
	{
		_currFrame = 0;
	}

	const Frames& frames = gRsrcMgr->getImageFrame(_drawParams.rsrcId);
	_drawParams.frameRect = frames[_currFrame];
}

void Image::setPrevFrame()
{
	_currFrame--;
	if(_currFrame == -1)
	{
		_currFrame = _maxFrames - 1;
	}

	const Frames& frames = gRsrcMgr->getImageFrame(_drawParams.rsrcId);
	_drawParams.frameRect = frames[_currFrame];
}

int32_t Image::getFrame() const
{
	return _currFrame;
}
