/*
 * PieceHandler.h
 *
 *  Created on: Nov 6, 2021
 *      Author: tomislav
 */

#ifndef INCLUDE_GAME_PIECES_PIECEHANDLER_H_
#define INCLUDE_GAME_PIECES_PIECEHANDLER_H_

#include "game/pieces/types/ChessPiece.h"
#include "game/defines/ChessDefines.h"
#include "game/pieces/PieceHandlerPopulator.h"
#include <vector>
#include <array>

struct GameBoardProxy;

class PieceHandler
{
public:
	int32_t init(GameBoardProxy* p_gameBoardProxy, int32_t p_whitePiecesRsrcId,
													int32_t p_blackPiecesRsrcId,
													int32_t p_unfinishedPieceFontId);
	void draw();
	void handleEvent(const InputEvent& e);

private:
	void handlePieceGrabEvent(const InputEvent& e);
	void handlePieceReleaseEvent(const InputEvent& e);

	void doMovePiece(const BoardPos& boardPos);
private:
	std::array<ChessPiece::PlayerPieces, Defines::PLAYERS_COUNT> _pieces;

	GameBoardProxy* _gameBoardProxy;

	int32_t _selectedPieceId = 0;
	int32_t _selectedPiecePlayerId = 0;
	bool _isPieceGrabbed = false;
};

#endif /* INCLUDE_GAME_PIECES_PIECEHANDLER_H_ */
