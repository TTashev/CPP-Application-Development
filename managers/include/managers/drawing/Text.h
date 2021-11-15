/*
 * Text.h
 *
 *  Created on: Oct 30, 2021
 *      Author: tomislav
 */

#ifndef MANAGERS_INCLUDE_MANAGERS_DRAWING_TEXT_H_
#define MANAGERS_INCLUDE_MANAGERS_DRAWING_TEXT_H_

#include "managers/drawing/Widget.h"
#include "utils/drawing/Color.h"
#include <cstdint>
#include <string>

class Text : public Widget
{
public:
	~Text();

	void create(const char *p_text, int32_t p_fontId,
	const Color& p_color, const Point& p_pos = Point::ZERO);

	void destroy();
	void setText(const std::string& p_text);
	void setColor(const Color& p_color);
	std::string getTextContent() const;

private:
	std::string _textContent;
	Color _color = Colors::BLACK;
	int32_t _fontId = INVALID_RSRC_ID;
	bool _isDestroyed = false;
};

#endif /* MANAGERS_INCLUDE_MANAGERS_DRAWING_TEXT_H_ */
