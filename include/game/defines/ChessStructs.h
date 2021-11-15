/*
 * ChessStructs.h
 *
 *  Created on: Nov 12, 2021
 *      Author: tomislav
 */

#ifndef INCLUDE_GAME_DEFINES_CHESSSTRUCTS_H_
#define INCLUDE_GAME_DEFINES_CHESSSTRUCTS_H_

#include "game/utils/BoardPos.h"
#include "game/defines/ChessDefines.h"

#include <vector>

struct TileData
{
	BoardPos boardPos;
	TileType tileType = TileType::MOVE;
};

using MoveDirection = std::vector<BoardPos>;

#endif /* INCLUDE_GAME_DEFINES_CHESSSTRUCTS_H_ */
