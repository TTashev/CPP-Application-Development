/*
 * ChessPiece.cpp
 *
 *  Created on: Nov 6, 2021
 *      Author: tomislav
 */

#include "game/pieces/types/ChessPiece.h"
#include "game/utils/BoardUtils.h"
#include "sdl_utils/InputEvent.h"
#include <cstdlib>
#include <iostream>

int32_t ChessPiece::init(const ChessPieceCfg& p_cfg)
{
	if(p_cfg._pieceType == PieceType::UNKNOWN)
	{
		std::cerr << "Error, invalid PieceType provided " <<
							static_cast<int32_t>(p_cfg._pieceType) << std:: endl;
		return EXIT_FAILURE;
	}

	if(p_cfg.rsrcId == INVALID_RSRC_ID)
	{
		std::cerr << "Error, chess piece invalid resource Id provided." << std:: endl;

		return EXIT_FAILURE;
	}

	_boardPos = p_cfg._boardPos;
	_playerId = p_cfg._playerId;
	_pieceType = p_cfg._pieceType;

	_pieceImg.create(p_cfg.rsrcId, BoardUtils::getAbsPos(_boardPos));
	_pieceImg.setFrame(static_cast<int32_t>(_pieceType));

	return EXIT_SUCCESS;
}

void ChessPiece::draw()
{
	_pieceImg.draw();
}

bool ChessPiece::containsEvent(const InputEvent &e) const
{
	return _pieceImg.containsPoint(e.pos);
}

void ChessPiece::setBoardPos(const BoardPos &p_boardPos)
{
	_boardPos = p_boardPos;
	_pieceImg.setPosition(BoardUtils::getAbsPos(_boardPos));
}

BoardPos ChessPiece::getBoardPos() const
{
	return _boardPos;
}

int32_t ChessPiece::getPlayerId() const
{
	return _playerId;
}
