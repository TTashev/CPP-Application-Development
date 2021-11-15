/*
 * ChessDefines.h
 *
 *  Created on: Nov 6, 2021
 *      Author: tomislav
 */

#ifndef INCLUDE_GAME_DEFINES_CHESSDEFINES_H_
#define INCLUDE_GAME_DEFINES_CHESSDEFINES_H_

#include <cstdint>
#include <vector>
#include <array>
#include <memory>

namespace Defines
{
	enum PlayerId
	{
		WHITE_PLAYER_ID = 0,
		BLACK_PLAYER_ID,
		PLAYERS_COUNT
	};

	enum Direction
	{
		UP_LEFT,
		UP,
		UP_RIGHT,
		RIGHT,
		DOWN_RIGHT,
		DOWN,
		DOWN_LEFT,
		LEFT,
		DIRECTION_COUNT
	};
}

enum class PieceType : uint8_t
{
	KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, UNKNOWN
};

enum class TileType : uint8_t
{
	MOVE, GUARD, TAKE
};

#endif /* INCLUDE_GAME_DEFINES_CHESSDEFINES_H_ */
