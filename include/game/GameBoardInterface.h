/*
 * GameBoardProxy.h
 *
 *  Created on: Nov 8, 2021
 *      Author: tomislav
 */

#ifndef INCLUDE_GAME_GAMEBOARDINTERFACE_H_
#define INCLUDE_GAME_GAMEBOARDINTERFACE_H_

#include <vector>
#include "game/defines/ChessStructs.h"

struct BoardPos;

class GameBoardInterface
{
public:
	virtual ~GameBoardInterface() = default;

	virtual void onPieceGrabbed(const BoardPos& p_boardPos,
					const std::vector<TileData>& p_moveTiles) = 0;
	virtual void onPieceUngrabbed() = 0;

	virtual bool isMoveAllowed(const BoardPos& p_pos) const = 0;
};


#endif /* INCLUDE_GAME_GAMEBOARDINTERFACE_H_ */
