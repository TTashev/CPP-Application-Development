/*
 * BoardPos.h
 *
 *  Created on: Nov 6, 2021
 *      Author: tomislav
 */

#ifndef INCLUDE_GAME_UTILS_BOARDPOS_H_
#define INCLUDE_GAME_UTILS_BOARDPOS_H_

#include <cstdint>

struct BoardPos
{
	BoardPos(int32_t p_row, int32_t p_col) : row(p_row), col(p_col) {}
	BoardPos() = default;

	bool operator==(const struct BoardPos& other) const
	{
		return row == other.row && col == other.col;
	}

	int32_t row {};
	int32_t col {};
};

#endif /* INCLUDE_GAME_UTILS_BOARDPOS_H_ */
