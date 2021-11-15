/*
 * Pawn.h
 *
 *  Created on: Nov 14, 2021
 *      Author: tomislav
 */

#ifndef INCLUDE_GAME_PIECES_TYPES_PAWN_H_
#define INCLUDE_GAME_PIECES_TYPES_PAWN_H_

#include "game/pieces/types/ChessPiece.h"
#include <unordered_map>

class Pawn : public ChessPiece
{
public:
	std::vector<TileData> getMoveTiles(const std::array<PlayerPieces,
									Defines::PLAYERS_COUNT>& activePieces) const;

private:
	std::vector<TileData> getWhiteMoveTiles(const std::array<PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const;
	std::vector<TileData> getBlackMoveTiles(const std::array<PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const;

	std::unordered_map<Defines::Direction,MoveDirection> getWhiteBoardMoves() const;
	std::unordered_map<Defines::Direction,MoveDirection> getBlackBoardMoves() const;

};

#endif /* INCLUDE_GAME_PIECES_TYPES_PAWN_H_ */
