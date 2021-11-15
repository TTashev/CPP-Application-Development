/*
 * ManagerHandlerCfg.h
 *
 *  Created on: Oct 30, 2021
 *      Author: tomislav
 */

#ifndef MANAGERS_INCLUDE_MANAGERS_CONFIG_MANAGERHANDLERCFG_H_
#define MANAGERS_INCLUDE_MANAGERS_CONFIG_MANAGERHANDLERCFG_H_

#include "managers/config/DrawMgrCfg.h"
#include "managers/config/RsrcMgrCfg.h"

struct ManagerHandlerCfg
{
	DrawMgrCfg drawMgrCfg;
	RsrcMgrCfg rsrcMgrCfg;
};


#endif /* MANAGERS_INCLUDE_MANAGERS_CONFIG_MANAGERHANDLERCFG_H_ */
