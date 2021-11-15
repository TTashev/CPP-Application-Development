/*
 * UnfinishedPiece.h
 *
 *  Created on: Nov 12, 2021
 *      Author: tomislav
 */

#ifndef INCLUDE_GAME_PIECES_TYPES_UNFINISHEDPIECE_H_
#define INCLUDE_GAME_PIECES_TYPES_UNFINISHEDPIECE_H_

#include "game/pieces/types/ChessPiece.h"
#include "managers/drawing/Text.h"

class UnfinishedPiece: public ChessPiece
{
public:
	int32_t init(const ChessPieceCfg& p_cfg);
	void draw();
	void setBoardPos(const BoardPos& boardPos);

	std::vector<TileData> getMoveTiles(const std::array<PlayerPieces,
									Defines::PLAYERS_COUNT>& activePieces) const;

private:
	Text _notReadyText;
};

#endif /* INCLUDE_GAME_PIECES_TYPES_UNFINISHEDPIECE_H_ */
