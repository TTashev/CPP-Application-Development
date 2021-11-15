/*
 * Game.cpp
 *
 *  Created on: Oct 16, 2021
 *      Author: tomislav
 */

#include "game/Game.h"

#include <iostream>

#include "common/CommonDefines.h"
#include "sdl_utils/InputEvent.h"
#include "game/defines/ChessDefines.h"

int32_t Game::init(const GameCfg& cfg)
{
	if(EXIT_SUCCESS != _gameBoard.init(cfg.chessBoardRsrcId, cfg.targetRsrcId,
									cfg.moveTilesRsrcId, cfg.blinkTargetTimerId))
	{
		std::cerr << "game board init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _piecesHandler.init(&_gameBoard,
						cfg.whitePiecesRsrcId, cfg.blackPiecesRsrcId, cfg.unfinishedPieceFontId))
	{
		std::cerr << "game board init() failed." << std::endl;
		return EXIT_FAILURE;
	}


	return EXIT_SUCCESS;
}

void Game::deinit()
{

}

void Game::draw()
{
	_gameBoard.draw();
	_piecesHandler.draw();
}

void Game::handleEvent(const InputEvent& e)
{
	_piecesHandler.handleEvent(e);
}

void Game::process()
{

}

void Game::onButtonPressed([[maybe_unused]]int32_t buttonId)
{

}
