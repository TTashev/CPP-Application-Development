/*
 * GameCfg.h
 *
 *  Created on: Oct 17, 2021
 *      Author: tomislav
 */

#ifndef GAME_CONFIG_GAMECFG_H_
#define GAME_CONFIG_GAMECFG_H_

#include <cstdint>
#include <unordered_map>
#include <string>

struct GameCfg
{
	int32_t chessBoardRsrcId;
	int32_t whitePiecesRsrcId;
	int32_t blackPiecesRsrcId;
	int32_t targetRsrcId;
	int32_t moveTilesRsrcId;

	int32_t unfinishedPieceFontId;

	int32_t blinkTargetTimerId;
};

#endif /* GAME_CONFIG_GAMECFG_H_ */
