/*
 * Pawn.cpp
 *
 *  Created on: Nov 14, 2021
 *      Author: tomislav
 */

#include "game/pieces/types/Pawn.h"
#include "game/utils/BoardUtils.h"
#include <cstdint>

std::vector<TileData> Pawn::getWhiteMoveTiles(
		const std::array<PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const
{
	const std::unordered_map<Defines::Direction,MoveDirection> boardMoves = getWhiteBoardMoves();
	std::vector<TileData> moveTiles;
//	moveTiles.reserve(boardMoves.size());

	std::unordered_map<Defines::Direction, MoveDirection>::const_iterator it = boardMoves.find(Defines::UP);
	if(it != boardMoves.end())
	{
		for (const auto& pos : it->second)
		{
			const auto tileType = BoardUtils::getTileType(pos, activePieces[_playerId],
										activePieces[BoardUtils::getOpponentId(_playerId)]);
			// if first possible move is TAKE or GUARD - second move is impossible
			if(TileType::MOVE != tileType)
			{
				break;
			}

			moveTiles.push_back({pos, tileType});
		}
	}

	constexpr auto diagonalMovesCount = 2;
	const std::array<Defines::Direction, diagonalMovesCount> diagonalMoves
	{
		Defines::UP_LEFT,Defines::UP_RIGHT
	};

	for (const Defines::Direction move : diagonalMoves)
	{
		it = boardMoves.find(move);
		if(it != boardMoves.end())
		{
			for (const auto& pos : it->second)
			{
				const auto tileType = BoardUtils::getTileType(pos, activePieces[_playerId],
										activePieces[BoardUtils::getOpponentId(_playerId)]);
				if(TileType::MOVE != tileType)
				{
					moveTiles.push_back({pos, tileType});
				}
			}
		}
	}

//	for (const auto& boardMovePair : boardMoves)
//	{
//		const auto currentBoardMove = boardMovePair.second;
//
//		for (const auto& boardPos : currentBoardMove)
//		{
//			const TileType tileType =  BoardUtils::getTileType(boardPos,
//						activePieces[_playerId], activePieces[BoardUtils::getOpponentId(_playerId)]);
//
//			TileData tileData;
//			tileData.boardPos = boardPos;
//			tileData.tileType = tileType;
//
//			moveTiles.push_back(tileData);
//
//			if(TileType::MOVE != tileType)
//			{
//				break;
//			}
//		}
//	}

	return moveTiles;
}

std::vector<TileData> Pawn::getBlackMoveTiles
	([[maybe_unused]]const std::array<PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const
{
	std::vector<TileData> boardMoves;


	return boardMoves;
}

std::vector<TileData> Pawn::getMoveTiles(
const std::array<PlayerPieces, Defines::PLAYERS_COUNT>& activePieces) const
{
	if (Defines::WHITE_PLAYER_ID == _playerId)
	{
		return getWhiteMoveTiles(activePieces);
	}
	return getBlackMoveTiles(activePieces);
}

std::unordered_map<Defines::Direction,MoveDirection> Pawn::getWhiteBoardMoves() const
{
//	Defines::UP_LEFT,Defines::UP_RIGHT, Defines::UP

	std::unordered_map<Defines::Direction,MoveDirection> boardMoves;
	BoardPos futurePos = BoardUtils::getAdjacentPos(Defines::UP_LEFT, _boardPos);

	if(BoardUtils::isInsideBoard(futurePos))
	{
		boardMoves[Defines::UP_LEFT].push_back(futurePos);

	}

	futurePos = BoardUtils::getAdjacentPos(Defines::UP_RIGHT, _boardPos);
	if(BoardUtils::isInsideBoard(futurePos))
	{
		boardMoves[Defines::UP_RIGHT].push_back(futurePos);

	}

	futurePos = BoardUtils::getAdjacentPos(Defines::UP, futurePos);
	if(BoardUtils::isInsideBoard(futurePos))
	{
		boardMoves[Defines::UP].push_back(futurePos);

	}

	return boardMoves;
}

std::unordered_map<Defines::Direction,MoveDirection> Pawn::getBlackBoardMoves() const
{
	std::unordered_map<Defines::Direction,MoveDirection> boardMoves;


	return boardMoves;
}
