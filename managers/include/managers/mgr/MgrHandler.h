/*
 * MgrHandler.h
 *
 *  Created on: Oct 28, 2021
 *      Author: tomislav
 */

#ifndef MANAGERS_INCLUDE_MANAGERS_MGR_MGRHANDLER_H_
#define MANAGERS_INCLUDE_MANAGERS_MGR_MGRHANDLER_H_

#include <cstdint>
#include "managers/mgr/MgrBase.h"

struct ManagerHandlerCfg;

class MgrHandler
{
public:

	int32_t init(const ManagerHandlerCfg& cfg);

	void deinit();

	void process();

private:
	void nullifyGlobalMgr(int32_t mgrIndex);
private:
	MgrBase* _managers[MANAGERS_COUNT];
};

#endif /* MANAGERS_INCLUDE_MANAGERS_MGR_MGRHANDLER_H_ */
