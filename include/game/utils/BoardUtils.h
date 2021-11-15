/*
 * BoardUtils.h
 *
 *  Created on: Nov 6, 2021
 *      Author: tomislav
 */

#ifndef INCLUDE_GAME_UTILS_BOARDUTILS_H_
#define INCLUDE_GAME_UTILS_BOARDUTILS_H_

#include <cstdint>

#include "utils/drawing/Point.h"
#include "game/utils/BoardPos.h"
#include "game/pieces/types/ChessPiece.h"

class BoardUtils
{
public:
	static BoardPos getBoardPos(const Point& p_absPos);
	static Point getAbsPos(const BoardPos& p_boardPos);
	static bool isInsideBoard(const BoardPos& p_boardPos);
	static bool isInsideBoard(const Point& p_absPos);

	static int32_t getOpponentId(int32_t p_activePlayerId);
	static BoardPos getAdjacentPos(Defines::Direction p_dir, const BoardPos& p_currPos);

	static bool doCollideWithPiece(const BoardPos& p_selectedPos,const ChessPiece::PlayerPieces& p_pieces,
																int32_t& p_collisionRelativeId);

	static TileType getTileType(const BoardPos& boardPos, const ChessPiece::PlayerPieces& p_playerPieces,
														  const ChessPiece::PlayerPieces& p_enemyPieces);
};

#endif /* INCLUDE_GAME_UTILS_BOARDUTILS_H_ */
