/*
 * EngineConfig.h
 *
 *  Created on: Oct 16, 2021
 *      Author: tomislav
 */

#ifndef ENGINE_CONFIG_ENGINECONFIG_H_
#define ENGINE_CONFIG_ENGINECONFIG_H_

#include "managers/config/ManagerHandlerCfg.h"
#include "game/config/GameCfg.h"

struct EngineCfg
{
	ManagerHandlerCfg managerHandlerCfg;
	GameCfg gameCfg;

	int32_t debugConsoleFontId;
};


#endif /* ENGINE_CONFIG_ENGINECONFIG_H_ */
