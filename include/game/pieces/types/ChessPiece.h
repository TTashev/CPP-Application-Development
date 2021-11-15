/*
 * ChessPiece.h
 *
 *  Created on: Nov 6, 2021
 *      Author: tomislav
 */

#ifndef INCLUDE_GAME_PIECES_TYPES_CHESSPIECE_H_
#define INCLUDE_GAME_PIECES_TYPES_CHESSPIECE_H_

#include "managers/drawing/Image.h"
#include "game/utils/BoardPos.h"
#include "game/defines/ChessDefines.h"
#include "game/defines/ChessStructs.h"
#include "game/pieces/types/ChessPiece.h"

struct InputEvent;

struct ChessPieceCfg
{
	BoardPos _boardPos {};
	int32_t _playerId {};
	int32_t rsrcId = INVALID_RSRC_ID;
	PieceType _pieceType = PieceType::UNKNOWN;

	int32_t _unfinishedPieceFontId;
};

class ChessPiece
{
public:
	using PlayerPieces = std::vector<std::unique_ptr<ChessPiece>>;

	virtual ~ChessPiece() = default;
	virtual int32_t init(const ChessPieceCfg& p_cfg);
	virtual void draw();
	bool containsEvent(const InputEvent& e) const;

	virtual void setBoardPos(const BoardPos& p_boardPos);
	virtual std::vector<TileData> getMoveTiles(const std::array<PlayerPieces,
									Defines::PLAYERS_COUNT>& activePieces) const = 0;
	BoardPos getBoardPos() const;

	int32_t getPlayerId() const;
protected:
	Image _pieceImg;
	BoardPos _boardPos;
	int32_t _playerId;
	PieceType _pieceType;
};



#endif /* INCLUDE_GAME_PIECES_TYPES_CHESSPIECE_H_ */
