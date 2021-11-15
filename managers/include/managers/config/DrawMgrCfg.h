/*
 * DrawMgrCfg.h
 *
 *  Created on: Oct 27, 2021
 *      Author: tomislav
 */

#ifndef MANAGERS_INCLUDE_MANAGERS_CONFIG_DRAWMGRCFG_H_
#define MANAGERS_INCLUDE_MANAGERS_CONFIG_DRAWMGRCFG_H_


#include "sdl_utils/config/MonitorWindowCfg.h"

struct DrawMgrCfg
{
	MonitorWindowCfg windowCfg;
	int64_t MaxFPS;
};


#endif /* MANAGERS_INCLUDE_MANAGERS_CONFIG_DRAWMGRCFG_H_ */
