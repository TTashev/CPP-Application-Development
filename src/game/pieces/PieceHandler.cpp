/*
 * PieceHandler.cpp
 *
 *  Created on: Nov 6, 2021
 *      Author: tomislav
 */

#include "game/pieces/PieceHandler.h"
#include "sdl_utils/InputEvent.h"
#include "game/utils/BoardUtils.h"
#include "game/GameBoardProxy.h"
#include <iostream>


int32_t PieceHandler::init(GameBoardProxy* p_gameBoardProxy, int32_t p_whitePiecesRsrcId,
															 int32_t p_blackPiecesRsrcId,
															 int32_t p_unfinishedPieceFontId)
{
	if(nullptr == p_gameBoardProxy)
	{
		std::cerr << "Error, nullptr provided for gameBoardProxy" << std::endl;
		return EXIT_FAILURE;
	}
	_gameBoardProxy = p_gameBoardProxy;

	if(EXIT_SUCCESS != PieceHandlerPopulator::populatePieceHandler
				(p_whitePiecesRsrcId, p_blackPiecesRsrcId, p_unfinishedPieceFontId, _pieces))
	{
		std::cerr << "Error, PieceHandlerPopulator failed." << std::endl;
		return EXIT_FAILURE;
	}


	return EXIT_SUCCESS;
}

void PieceHandler::draw()
{
	for (auto& playerPieces : _pieces)
	{
		for (auto& piece : playerPieces)
		{
			piece->draw();
		}
	}
}

void PieceHandler::handleEvent(const InputEvent &e)
{
	return _isPieceGrabbed ? handlePieceGrabEvent(e) :
			handlePieceReleaseEvent(e);
}

void PieceHandler::handlePieceGrabEvent(const InputEvent &e)
{
	if(e.type != TouchEvent::TOUCH_RELEASE)
	{
		return;
	}

	_isPieceGrabbed = false;

	if(!BoardUtils::isInsideBoard(e.pos))
	{
		_gameBoardProxy->onPieceUngrabbed();
		return;
	}

	const BoardPos boardPos = BoardUtils::getBoardPos(e.pos);
	if(!_gameBoardProxy->isMoveAllowed(boardPos))
	{
		_gameBoardProxy->onPieceUngrabbed();
		return;
	}

	doMovePiece(boardPos);
}

void PieceHandler::handlePieceReleaseEvent(const InputEvent &e)
{
	if(e.type != TouchEvent::TOUCH_RELEASE)
	{
		return;
	}


	int32_t currentPlayerId = Defines::WHITE_PLAYER_ID;
	for (const auto& playerPieces : _pieces)
	{
		int32_t relativePieceId = 0;
		for (const auto& piece : playerPieces)
		{
			if(piece->containsEvent(e))
			{
				_selectedPieceId = relativePieceId;
				_selectedPiecePlayerId = currentPlayerId;

				_isPieceGrabbed = true;

				const auto moveTile = _pieces[_selectedPiecePlayerId][_selectedPieceId]->getMoveTiles(_pieces);
				_gameBoardProxy->onPieceGrabbed(BoardUtils::getBoardPos(e.pos), moveTile);
				return;
			}

			relativePieceId++;
		}
		currentPlayerId++;
	}
}

void PieceHandler::doMovePiece(const BoardPos& boardPos)
{
	_pieces[_selectedPiecePlayerId][_selectedPieceId]->setBoardPos(boardPos);
	const auto opponentId =
			BoardUtils::getOpponentId(_pieces[_selectedPiecePlayerId][_selectedPieceId]->getPlayerId());

	int32_t collisionIdx = -1;
	if(BoardUtils::doCollideWithPiece(boardPos, _pieces[opponentId], collisionIdx))
	{
		_pieces[collisionIdx].erase(_pieces[opponentId].begin() + collisionIdx);
	}

	_gameBoardProxy->onPieceUngrabbed();
}
