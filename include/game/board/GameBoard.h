/*
 * GameBoard.h
 *
 *  Created on: Nov 6, 2021
 *      Author: tomislav
 */

#ifndef INCLUDE_GAME_BOARD_GAMEBOARD_H_
#define INCLUDE_GAME_BOARD_GAMEBOARD_H_

#include <cstdint>

#include "game/GameBoardInterface.h"
#include "managers/drawing/Image.h"
#include "managers/time/TimerClient.h"
#include "game/board/MoveSelector.h"

class GameBoard : public GameBoardInterface, public TimerClient
{
public:
	int32_t init(int32_t p_boardRsrcId, int32_t p_targetRsrcId,
				 int32_t p_moveTilesRsrcId, int32_t p_blinkTimerId);
	void draw();
private:
	void onTimeout(int32_t p_timerId) final;
	void onPieceGrabbed(const BoardPos& p_boardPos, const std::vector<TileData>& p_moveTiles) final;
	void onPieceUngrabbed() final;
	bool isMoveAllowed(const BoardPos& p_pos) const final;
private:
	Image _boardImg;
	Image _targetImg;

	int32_t _blinkTimerId;
	std::vector<TileData> _currentMoveTiles;

	MoveSelector _moveSelector;
};

#endif /* INCLUDE_GAME_BOARD_GAMEBOARD_H_ */
