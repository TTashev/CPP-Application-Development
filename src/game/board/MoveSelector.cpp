/*
 * MoveSelector.cpp
 *
 *  Created on: Nov 13, 2021
 *      Author: tomislav
 */

#include "game/board/MoveSelector.h"
#include "game/utils/BoardUtils.h"
#include <iostream>

int32_t MoveSelector::init(int32_t rsrcId)
{
	for (auto& img : _tileImgs)
	{
		img.create(rsrcId);
	}

	return EXIT_SUCCESS;
}

void MoveSelector::draw()
{
	for (size_t i = 0; i < _activeTiles; ++i)
	{
		_tileImgs[i].draw();
	}
}

void MoveSelector::markTiles(const std::vector<TileData> &markedTiles)
{
	_activeTiles = markedTiles.size();

	for (size_t i = 0; i < _activeTiles; ++i)
	{
		_tileImgs[i].setPosition(BoardUtils::getAbsPos(markedTiles[i].boardPos));
		_tileImgs[i].setFrame(static_cast<int32_t>(markedTiles[i].tileType));
	}
}

void MoveSelector::unmarkTiles()
{
	_activeTiles = 0;
}
