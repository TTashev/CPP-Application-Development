/*
 * Rook.h
 *
 *  Created on: Nov 12, 2021
 *      Author: tomislav
 */

#ifndef INCLUDE_GAME_PIECES_TYPES_ROOK_H_
#define INCLUDE_GAME_PIECES_TYPES_ROOK_H_

#include "game/pieces/types/ChessPiece.h"

class Rook : public ChessPiece
{
public:
	std::vector<TileData> getMoveTiles(const std::array<PlayerPieces,
									Defines::PLAYERS_COUNT>& activePieces) const;

private:
	std::vector<MoveDirection> getBoardMoves() const;
};

#endif /* INCLUDE_GAME_PIECES_TYPES_ROOK_H_ */
