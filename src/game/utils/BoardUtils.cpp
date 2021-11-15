/*
 * BoardUtils.cpp
 *
 *  Created on: Nov 6, 2021
 *      Author: tomislav
 */

#include "game/utils/BoardUtils.h"
#include "utils/drawing/Rectangle.h"
#include <iostream>

static constexpr auto BOARD_SIZE = 8;

static constexpr auto FIRST_TILE_X_POS = 58;
static constexpr auto FIRST_TILE_Y_POS = 60;

static constexpr auto TILE_SIZE = 98;

BoardPos BoardUtils::getBoardPos(const Point& p_absPos)
{
	return { (p_absPos.y - FIRST_TILE_Y_POS) / TILE_SIZE,		// rows
			 (p_absPos.x - FIRST_TILE_X_POS) / TILE_SIZE };	// col
}

Point BoardUtils::getAbsPos(const BoardPos& p_boardPos)
{
	return { (p_boardPos.col * TILE_SIZE) + FIRST_TILE_X_POS,
			 (p_boardPos.row * TILE_SIZE) + FIRST_TILE_Y_POS };
}

bool BoardUtils::isInsideBoard(const BoardPos& p_boardPos)
{
	const Rectangle& bound { 0, 0, BOARD_SIZE, BOARD_SIZE };
	const Point pos {p_boardPos.col, p_boardPos.row};

	return bound.isPointInside(pos);
}

bool BoardUtils::isInsideBoard(const Point& p_absPos)
{
	const Rectangle& bound { FIRST_TILE_X_POS, FIRST_TILE_Y_POS,
							 BOARD_SIZE * TILE_SIZE, BOARD_SIZE * TILE_SIZE };

	return bound.isPointInside(p_absPos);
}

int32_t BoardUtils::getOpponentId(int32_t p_activePlayerId)
{
	if(Defines::WHITE_PLAYER_ID == p_activePlayerId)
	{
		return Defines::BLACK_PLAYER_ID;
	}

	return Defines::WHITE_PLAYER_ID;
}

BoardPos BoardUtils::getAdjacentPos(Defines::Direction p_dir,
		const BoardPos &p_currPos)
{
	BoardPos pos = p_currPos;

	switch (p_dir)
	{
	case Defines::UP_LEFT:
		--pos.row;
		--pos.col;
		break;
	case Defines::UP:
		--pos.row;
		break;
	case Defines::UP_RIGHT:
		--pos.row;
		++pos.col;
		break;
	case Defines::RIGHT:
		++pos.col;
		break;
	case Defines::DOWN_RIGHT:
		++pos.row;
		++pos.col;
		break;
	case Defines::DOWN:
		++pos.row;
		break;
	case Defines::DOWN_LEFT:
		++pos.row;
		--pos.col;
		break;
	case Defines::LEFT:
		--pos.col;
		break;
	case Defines::DIRECTION_COUNT:
		break;
		default:
			std::cerr << "Received invalid dir: " << p_dir << std::endl;
		break;
	}

	return pos;
}

bool BoardUtils::doCollideWithPiece(const BoardPos &p_selectedPos,
		const ChessPiece::PlayerPieces &p_pieces,
		int32_t& p_collisionRelativeId)
{
	const size_t size = p_pieces.size();
	for (size_t i = 0; i < size; ++i)
	{
		if(p_selectedPos == p_pieces[i]->getBoardPos())
		{
			p_collisionRelativeId = static_cast<int32_t>(i);
			return true;
		}
	}

	return false;
}

TileType BoardUtils::getTileType(const BoardPos &boardPos,
		const ChessPiece::PlayerPieces &p_playerPieces,
		const ChessPiece::PlayerPieces &p_enemyPieces)
{
	int32_t collisionIdx = -1;
	if(doCollideWithPiece(boardPos, p_playerPieces, collisionIdx))
	{
		return TileType::GUARD;
	}

	if(doCollideWithPiece(boardPos, p_enemyPieces, collisionIdx))
	{
		return TileType::TAKE;
	}

	return TileType::MOVE;
}
