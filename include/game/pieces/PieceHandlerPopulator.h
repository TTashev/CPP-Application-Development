/*
 * PieceHandlerPopulator.h
 *
 *  Created on: Nov 9, 2021
 *      Author: tomislav
 */

#ifndef INCLUDE_GAME_PIECES_PIECEHANDLERPOPULATOR_H_
#define INCLUDE_GAME_PIECES_PIECEHANDLERPOPULATOR_H_

#include <cstdint>

#include "game/defines/ChessDefines.h"
#include "game/pieces/types/ChessPiece.h"


class PieceHandlerPopulator
{
public:
	PieceHandlerPopulator() = delete;
	~PieceHandlerPopulator() = default;

	static int32_t populatePieceHandler(int32_t p_whitePiecesRsrcId,
										int32_t p_blackPiecesRsrcId,
										int32_t p_unfinishedPieceFontId,
										std::array<ChessPiece::PlayerPieces, Defines::PLAYERS_COUNT>& p_pieces);
};

#endif /* INCLUDE_GAME_PIECES_PIECEHANDLERPOPULATOR_H_ */
