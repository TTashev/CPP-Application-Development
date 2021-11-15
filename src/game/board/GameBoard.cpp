/*
 * GameBoard.cpp
 *
 *  Created on: Nov 6, 2021
 *      Author: tomislav
 */

#include "game/board/GameBoard.h"
#include "game/utils/BoardUtils.h"

#include <cstdlib>
#include <iostream>

int32_t GameBoard::init(int32_t p_boardRsrcId, int32_t p_targetRsrcId,
		 	 	 	 	 int32_t p_moveTilesRsrcId, int32_t p_blinkTimerId)
{
	_boardImg.create(p_boardRsrcId);
	_targetImg.create(p_targetRsrcId);
	_targetImg.hide();

	_blinkTimerId = p_blinkTimerId;

	if(EXIT_SUCCESS != _moveSelector.init(p_moveTilesRsrcId))
	{
		std::cerr << "Error, move selector init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void GameBoard::draw()
{
	_boardImg.draw();
	_targetImg.draw();
	_moveSelector.draw();
}

void GameBoard::onPieceGrabbed(const BoardPos& p_boardPos, const std::vector<TileData>& moveTiles)
{
	_currentMoveTiles = moveTiles;
	_moveSelector.markTiles(_currentMoveTiles);

	_targetImg.show();
	_targetImg.setPosition(BoardUtils::getAbsPos(p_boardPos));

	startTimer(1000, _blinkTimerId, TimerType::PULSE);
}

void GameBoard::onPieceUngrabbed()
{
	_moveSelector.unmarkTiles();

	_currentMoveTiles.clear();
	_targetImg.hide();

	if(isActiveTimerId(_blinkTimerId))
	{
		stopTimer(_blinkTimerId);
	}
}

bool GameBoard::isMoveAllowed(const BoardPos& p_pos) const
{
	for (const auto& moveTile : _currentMoveTiles)
	{
		if(moveTile.boardPos == p_pos)
		{
			if(moveTile.tileType == TileType::MOVE ||
			   moveTile.tileType == TileType::TAKE)
			{
				return true;
			}
		}
	}

	return false;
}

void GameBoard::onTimeout(int32_t p_timerId)
{
	if(_blinkTimerId == p_timerId)
	{
		if(_targetImg.isVisible())
		{
			_targetImg.hide();
		}
		else
		{
			_targetImg.show();
		}
	}
	else
	{
		std::cerr << "Error, GameBoard received unsupported timer Id: " << p_timerId << std::endl;
	}
}
