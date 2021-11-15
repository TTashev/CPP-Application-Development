/*
 * Text.cpp
 *
 *  Created on: Oct 30, 2021
 *      Author: tomislav
 */

#include "managers/drawing/Text.h"
#include "managers/mgr/RsrcMgr.h"

#include <iostream>

Text::~Text()
{
//	if(_isCreated && !_isDestroyed)
//	{
//		destroy();
//	}
}

void Text::create(const char *p_text, int32_t p_fontId, const Color &p_color,
		const Point &p_pos)
{
	if(_isCreated)
	{
		std::cerr << "Error, text with fontId: " << p_fontId << "already created!" << std::endl;
		return;
	}


	_drawParams.pos = p_pos;
	_drawParams.widgetType = WidgetType::TEXT;

	_textContent = p_text;
	_color = p_color;
	_fontId = p_fontId;

	gRsrcMgr->createText(p_text, p_color, p_fontId,
			_drawParams.textId, _drawParams.width, _drawParams.height);

	_drawParams.frameRect.x = 0;
	_drawParams.frameRect.y = 0;
	_drawParams.frameRect.w = _drawParams.width;
	_drawParams.frameRect.h = _drawParams.height;

	_isCreated = true;
	_isDestroyed = false;
}

void Text::destroy()
{
	if(_isCreated)
	{
		std::cerr << "Error, text already destroyed!" << std::endl;
		return;
	}

	_isCreated = false;
	_isDestroyed = true;


	if(gRsrcMgr)
	{
		gRsrcMgr->unloadText(_drawParams.textId);
	}

	Widget::reset();
}

void Text::setText(const std::string& p_text)
{
	if(p_text == _textContent)
	{
		return;
	}

	_textContent = p_text;
	gRsrcMgr->reloadText(p_text, _color, _fontId,
			_drawParams.textId, _drawParams.width, _drawParams.height);

	_drawParams.frameRect.w = _drawParams.width;
	_drawParams.frameRect.h = _drawParams.height;
}

void Text::setColor(const Color &p_color)
{
	if(p_color == _color)
	{
		return;
	}

	_color = p_color;
	gRsrcMgr->reloadText(_textContent, _color, _fontId,
			_drawParams.textId, _drawParams.width, _drawParams.height);
}

std::string Text::getTextContent() const
{
	return _textContent;
}
