/*
 * Game.h
 *
 *  Created on: Oct 16, 2021
 *      Author: tomislav
 */

#ifndef GAME_GAME_H_
#define GAME_GAME_H_

#include <cstdint>
#include <vector>

#include "config/GameCfg.h"
#include "managers/drawing/Image.h"
#include "game/board/GameBoard.h"
#include "game/pieces/PieceHandler.h"

struct InputEvent;

class Game
{
public:
	int32_t init(const GameCfg& cfg);
	void deinit();
	void draw();
	void handleEvent(const InputEvent& e);

	void process();

private:
	void onButtonPressed(int32_t buttonId);
private:
	GameBoard _gameBoard;
	PieceHandler _piecesHandler;
};

#endif /* GAME_GAME_H_ */
