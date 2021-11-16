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

	return moveTiles;
}

std::vector<TileData> Pawn::getBlackMoveTiles
	(const std::array<PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const
{
	const std::unordered_map<Defines::Direction, MoveDirection> boardMoves =
															getBlackBoardMoves();

	std::vector<TileData> moveTiles;
//	moveTiles.reserve(boardMoves.size());
	const int32_t opponentId = BoardUtils::getOpponentId(_playerId);

	std::unordered_map<Defines::Direction, MoveDirection>::const_iterator it =
													boardMoves.find(Defines::DOWN);
	if (it != boardMoves.end())
	{
		for (const auto &pos : it->second)
		{
		  const auto tileType = BoardUtils::getTileType(pos, activePieces[_playerId],
			  activePieces[opponentId]);
		  //if first possible move is TAKE or GUARD - second move will be impossible
		  if (TileType::MOVE != tileType)
		  {
			break;
		  }

		  moveTiles.push_back({pos, tileType});
		}
	}

	constexpr auto diagonalMovesCnt = 2;
	const std::array<Defines::Direction, diagonalMovesCnt> diagonalMoves
	{
	  Defines::DOWN_LEFT, Defines::DOWN_RIGHT
	};

	for (const Defines::Direction move : diagonalMoves)
	{
		it = boardMoves.find(move);
		if (it != boardMoves.end())
		{
			  for (const auto &pos : it->second)
			  {
				const auto tileType = BoardUtils::getTileType(pos,
					activePieces[_playerId], activePieces[opponentId]);
				if (TileType::MOVE != tileType)
				{
				  moveTiles.push_back({pos, tileType});
				}
			  }
		}
	}

	return moveTiles;
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

	constexpr auto allowedDirs = 3; //UP_LEFT, UP, UP_RIGHT
	std::unordered_map<Defines::Direction, MoveDirection> boardMoves(allowedDirs);

	BoardPos futurePos;
	futurePos = BoardUtils::getAdjacentPos(Defines::UP_LEFT, _boardPos);
	if (BoardUtils::isInsideBoard(futurePos))
	{
		boardMoves[Defines::UP_LEFT].emplace_back(futurePos);
	}

	futurePos = BoardUtils::getAdjacentPos(Defines::UP_RIGHT, _boardPos);
	if (BoardUtils::isInsideBoard(futurePos))
	{
		boardMoves[Defines::UP_RIGHT].emplace_back(futurePos);
	}

	futurePos = BoardUtils::getAdjacentPos(Defines::UP, _boardPos);
	boardMoves[Defines::UP].emplace_back(futurePos);

	//do the double pawn move
	if (Defines::WHITE_PLAYER_START_PAWN_ROW == _boardPos.row)
	{
		futurePos = BoardUtils::getAdjacentPos(Defines::UP, futurePos);
		boardMoves[Defines::UP].emplace_back(futurePos);
	}

	return boardMoves;
}

std::unordered_map<Defines::Direction,MoveDirection> Pawn::getBlackBoardMoves() const
{
	constexpr auto allowedDirs = 3; //DOWN_LEFT, DOWN, DOWN_RIGHT
	std::unordered_map<Defines::Direction, MoveDirection> boardMoves(allowedDirs);

	BoardPos futurePos;
	futurePos = BoardUtils::getAdjacentPos(Defines::DOWN_LEFT, _boardPos);
	if (BoardUtils::isInsideBoard(futurePos))
	{
		boardMoves[Defines::DOWN_LEFT].emplace_back(futurePos);
	}

	futurePos = BoardUtils::getAdjacentPos(Defines::DOWN_RIGHT, _boardPos);
	if (BoardUtils::isInsideBoard(futurePos))
	{
		boardMoves[Defines::DOWN_RIGHT].emplace_back(futurePos);
	}

	futurePos = BoardUtils::getAdjacentPos(Defines::DOWN, _boardPos);
	boardMoves[Defines::DOWN].emplace_back(futurePos);

	//do the double pawn move
	if (Defines::BLACK_PLAYER_START_PAWN_ROW == _boardPos.row)
	{
		futurePos = BoardUtils::getAdjacentPos(Defines::DOWN, futurePos);
		boardMoves[Defines::DOWN].emplace_back(futurePos);
	}

	return boardMoves;
}
