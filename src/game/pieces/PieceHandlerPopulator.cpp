/*
 * PieceHandlerPopulator.cpp
 *
 *  Created on: Nov 9, 2021
 *      Author: tomislav
 */

#include "game/pieces/PieceHandlerPopulator.h"
#include "game/pieces/types/UnfinishedPiece.h"
#include "game/pieces/types/Rook.h"
#include "game/pieces/types/Pawn.h"

#include <iostream>
#include <cstdlib>

static constexpr auto STARTING_PIECES_COUNT = 16;
static constexpr auto PAWNS_COUNT = 8;

static constexpr auto WHITE_PLAYER_START_PAWN_ROW = 6;
static constexpr auto BLACK_PLAYER_START_PAWN_ROW = 1;

static std::unique_ptr<ChessPiece> createPiece(PieceType p_piecesType)
{
	switch (p_piecesType)
	{
		case PieceType::ROOK:
			return std::make_unique<Rook>();
			break;
		case PieceType::PAWN:
			return std::make_unique<Pawn>();
			break;
		case PieceType::KING:
		case PieceType::QUEEN:
		case PieceType::BISHOP:
		case PieceType::KNIGHT:
			return std::make_unique<UnfinishedPiece>();
			break;

		default:
			std::cerr << "Error, received unknown PieceType: " << std::endl;
			break;
	}

	return nullptr;
}

static int32_t populateWhitePieces(int32_t p_rsrcId, int32_t p_unfinishedPieceFontId, ChessPiece::PlayerPieces& p_whites)
{
	p_whites.reserve(STARTING_PIECES_COUNT);

	ChessPieceCfg pieceCfg;
	pieceCfg._boardPos.row = WHITE_PLAYER_START_PAWN_ROW;
	pieceCfg._playerId = Defines::WHITE_PLAYER_ID;
	pieceCfg.rsrcId = p_rsrcId;
	pieceCfg._pieceType = PieceType::PAWN;
	pieceCfg._unfinishedPieceFontId = p_unfinishedPieceFontId;


	for (int32_t i = 0; i < PAWNS_COUNT; ++i)
	{
		p_whites.push_back(createPiece(pieceCfg._pieceType));

		pieceCfg._boardPos.col = i;
		if(EXIT_SUCCESS != p_whites[i]->init(pieceCfg))
		{
			std::cerr << "Error, whites init() failed." << std::endl;
			return EXIT_FAILURE;
		}
	}

	constexpr auto nonPawnCount = PAWNS_COUNT;
	constexpr PieceType nonPawnPieces[PAWNS_COUNT] =
	{
		PieceType::ROOK, PieceType::KNIGHT, PieceType::BISHOP, PieceType::QUEEN,
		PieceType::KING, PieceType::BISHOP, PieceType::KNIGHT, PieceType::ROOK
	};
	pieceCfg._boardPos.row = WHITE_PLAYER_START_PAWN_ROW + 1;
	for (int32_t i = nonPawnCount; i < STARTING_PIECES_COUNT; ++i)
	{
		pieceCfg._boardPos.col = i - nonPawnCount;
		pieceCfg._pieceType = nonPawnPieces[i - nonPawnCount];

		p_whites.push_back(createPiece(pieceCfg._pieceType));

		if(EXIT_SUCCESS != p_whites[i]->init(pieceCfg))
		{
			std::cerr << "Error, whites init() failed." << std::endl;
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}

static int32_t populateBlackpieces(int32_t p_rsrcId, int32_t p_unfinishedPieceFontId, ChessPiece::PlayerPieces& p_blacks)
{
	p_blacks.reserve(STARTING_PIECES_COUNT);


	ChessPieceCfg pieceCfg;
	pieceCfg._boardPos.row = BLACK_PLAYER_START_PAWN_ROW;
	pieceCfg._playerId = Defines::BLACK_PLAYER_ID;
	pieceCfg.rsrcId = p_rsrcId;
	pieceCfg._pieceType = PieceType::PAWN;
	pieceCfg._unfinishedPieceFontId = p_unfinishedPieceFontId;


	for (int32_t i = 0; i < PAWNS_COUNT; ++i)
	{
		p_blacks.push_back(createPiece(pieceCfg._pieceType));

		pieceCfg._boardPos.col = i;
		if(EXIT_SUCCESS != p_blacks[i]->init(pieceCfg))
		{
			std::cerr << "Error, blacks init() failed." << std::endl;
			return EXIT_FAILURE;
		}
	}

	constexpr auto nonPawnCount = PAWNS_COUNT;
	constexpr PieceType nonPawnPieces[PAWNS_COUNT] =
	{
		PieceType::ROOK, PieceType::KNIGHT, PieceType::BISHOP, PieceType::QUEEN,
		PieceType::KING, PieceType::BISHOP, PieceType::KNIGHT, PieceType::ROOK
	};
	pieceCfg._boardPos.row = BLACK_PLAYER_START_PAWN_ROW - 1;
	for (int32_t i = nonPawnCount; i < STARTING_PIECES_COUNT; ++i)
	{
		pieceCfg._boardPos.col = i - nonPawnCount;
		pieceCfg._pieceType = nonPawnPieces[i - nonPawnCount];

		p_blacks.push_back(createPiece(pieceCfg._pieceType));

		if(EXIT_SUCCESS != p_blacks[i]->init(pieceCfg))
		{
			std::cerr << "Error, blacks init() failed." << std::endl;
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}


int32_t PieceHandlerPopulator::populatePieceHandler(int32_t p_whitePiecesRsrcId,
													int32_t p_blackPiecesRsrcId,
													int32_t p_unfinishedPieceFontId,
					 std::array<ChessPiece::PlayerPieces, Defines::PLAYERS_COUNT>& p_pieces)
{
	auto& whites = p_pieces[Defines::WHITE_PLAYER_ID];
	auto& blacks = p_pieces[Defines::BLACK_PLAYER_ID];
	if(EXIT_SUCCESS != populateWhitePieces(p_whitePiecesRsrcId, p_unfinishedPieceFontId, whites))
	{
		std::cerr << "Error, populateWhitepieces() failed." << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != populateBlackpieces(p_blackPiecesRsrcId, p_unfinishedPieceFontId, blacks))
	{
		std::cerr << "Error, populateBlackpieces() failed." << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
