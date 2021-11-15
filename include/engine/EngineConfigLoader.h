/*
 * EngineConfigLoader.h
 *
 *  Created on: Oct 16, 2021
 *      Author: tomislav
 */

#ifndef ENGINE_ENGINECONFIGLOADER_H_
#define ENGINE_ENGINECONFIGLOADER_H_

#include "engine/config/EngineConfig.h"

class EngineConfigLoader
{
public:
	EngineConfigLoader() = delete;
	~EngineConfigLoader() = default;

	static EngineCfg loadConfig();
};

#endif /* ENGINE_ENGINECONFIGLOADER_H_ */
