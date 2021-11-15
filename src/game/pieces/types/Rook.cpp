/*
 * Rook.cpp
 *
 *  Created on: Nov 12, 2021
 *      Author: tomislav
 */

#include "game/pieces/types/Rook.h"
#include "game/utils/BoardUtils.h"
#include <cstdint>


std::vector<TileData> Rook::getMoveTiles(
		const std::array<PlayerPieces, Defines::PLAYERS_COUNT> &activePieces) const
{
	std::vector<TileData> moveTiles;

	const std::vector<MoveDirection> boardMoves = getBoardMoves();


	for (const auto& moveDir : boardMoves)
	{
		if (moveDir.empty())
		{
			continue;
		}

		for (const auto& boardPos : moveDir)
		{
			const TileType tileType =  BoardUtils::getTileType(boardPos,
						activePieces[_playerId], activePieces[BoardUtils::getOpponentId(_playerId)]);

			TileData tileData;
			tileData.boardPos = boardPos;
			tileData.tileType = tileType;

			moveTiles.push_back(tileData);

			if(TileType::MOVE != tileType)
			{
				break;
			}
		}
	}

	return moveTiles;
}

std::vector<MoveDirection> Rook::getBoardMoves() const
{
	constexpr auto allowedDirs = 4;
	constexpr std::array<Defines::Direction, allowedDirs> rookDirs { Defines::UP,
	Defines::RIGHT, Defines::DOWN, Defines::LEFT };

	constexpr auto maxRootMoves = 14;
	std::vector<MoveDirection> boardMoves(allowedDirs);
	BoardPos futurePos;
	for (int32_t dirIdx = 0; dirIdx < allowedDirs; ++dirIdx)
	{
		boardMoves[dirIdx].reserve(maxRootMoves);
		futurePos = _boardPos;
		futurePos = BoardUtils::getAdjacentPos(rookDirs[dirIdx], futurePos);
		while(BoardUtils::isInsideBoard(futurePos))
		{
			boardMoves[dirIdx].push_back(futurePos);
			futurePos = BoardUtils::getAdjacentPos(rookDirs[dirIdx], futurePos);
		}
	}
	return boardMoves;
}

