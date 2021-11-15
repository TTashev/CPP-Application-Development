/*
 * MoveSelector.h
 *
 *  Created on: Nov 13, 2021
 *      Author: tomislav
 */

#ifndef INCLUDE_GAME_BOARD_MOVESELECTOR_H_
#define INCLUDE_GAME_BOARD_MOVESELECTOR_H_

#include "game/defines/ChessStructs.h"
#include "managers/drawing/Image.h"

class MoveSelector
{
public:
	int32_t init(int32_t rsrcId);
	void draw();
	void markTiles(const std::vector<TileData>& markedTiles);
	void unmarkTiles();

private:
	enum InternalDefines
	{
		MAX_ACTIVE_TILES = 28
	};
	std::array<Image, MAX_ACTIVE_TILES> _tileImgs;
	size_t _activeTiles { 0 };
};

#endif /* INCLUDE_GAME_BOARD_MOVESELECTOR_H_ */
