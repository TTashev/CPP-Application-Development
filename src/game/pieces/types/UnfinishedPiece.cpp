/*
 * UnfinishedPiece.cpp
 *
 *  Created on: Nov 12, 2021
 *      Author: tomislav
 */

#include "game/pieces/types/UnfinishedPiece.h"
#include "game/utils/BoardUtils.h"
#include <iostream>

int32_t UnfinishedPiece::init(const ChessPieceCfg &p_cfg)
{
	if(EXIT_SUCCESS != ChessPiece::init(p_cfg))
	{
		std::cerr << "Error, UnfinishedPiece init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	const auto pieceAbsolutePos = BoardUtils::getAbsPos(_boardPos);
	_notReadyText.create("!", p_cfg._unfinishedPieceFontId, Colors::RED, pieceAbsolutePos);

	return EXIT_SUCCESS;
}

void UnfinishedPiece::draw()
{
	ChessPiece::draw();
	_notReadyText.draw();
}

void UnfinishedPiece::setBoardPos(const BoardPos &boardPos)
{
	ChessPiece::setBoardPos(boardPos);
	const auto pieceAbsolutePos = BoardUtils::getAbsPos(_boardPos);
	_notReadyText.setPosition(pieceAbsolutePos);
}

std::vector<TileData> UnfinishedPiece::getMoveTiles([[maybe_unused]]const std::array<ChessPiece::PlayerPieces,
							Defines::PLAYERS_COUNT>& activePieces) const
{
	return std::vector<TileData> { };
}
