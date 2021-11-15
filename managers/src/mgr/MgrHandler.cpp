/*
 * MgrHandler.cpp
 *
 *  Created on: Oct 28, 2021
 *      Author: tomislav
 */

#include "managers/mgr/MgrHandler.h"

#include "managers/config/ManagerHandlerCfg.h"
#include "managers/mgr/RsrcMgr.h"
#include "managers/mgr/DrawMgr.h"
#include "managers/mgr/TimerMgr.h"
#include <cstdlib>
#include <iostream>


int32_t MgrHandler::init(const ManagerHandlerCfg &cfg)
{
	gDrawMgr = new DrawMgr();
	if(gDrawMgr == nullptr)
	{
		std::cerr << "Error, bad alloc DrawMgr!" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != gDrawMgr->init(cfg.drawMgrCfg))
	{
		std::cerr << "gDrawMgr->init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	gRsrcMgr = new RsrcMgr();
	if(gRsrcMgr == nullptr)
	{
		std::cerr << "Error, bad alloc DrawMgr!" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != gRsrcMgr->init(cfg.rsrcMgrCfg))
	{
		std::cerr << "gRsrcMgr->init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	gTimerMgr = new TimerMgr();
	if(gTimerMgr == nullptr)
	{
		std::cerr << "Error, bad alloc TimerMgr!" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != gTimerMgr->init())
	{
		std::cerr << "gTimerMgr->init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	_managers[DRAW_MGR] = static_cast<MgrBase*>(gDrawMgr);
	_managers[RSRC_MGR] = static_cast<MgrBase*>(gRsrcMgr);
	_managers[TIMER_MGR] = static_cast<MgrBase*>(gTimerMgr);

	return EXIT_SUCCESS;
}

void MgrHandler::deinit()
{
	for (int32_t i = MANAGERS_COUNT - 1; i >= 0; --i)
	{
		_managers[i]->deinit();
		_managers[i] = nullptr;

		nullifyGlobalMgr(i);
	}
}

void MgrHandler::process()
{
	for (int32_t i = 0; i < MANAGERS_COUNT; ++i)
	{
		_managers[i]->process();
	}
}

void MgrHandler::nullifyGlobalMgr(int32_t mgrIndex)
{
	switch (mgrIndex) {
		case DRAW_MGR:
			delete gDrawMgr;
			gDrawMgr = nullptr;
			break;
		case RSRC_MGR:
			delete gRsrcMgr;
			gRsrcMgr = nullptr;
			break;
		case TIMER_MGR:
			delete gTimerMgr;
			gTimerMgr = nullptr;
			break;
		default:
			std::cerr << "Received invalid mgrIndex: " << mgrIndex << std::endl;
			break;
	}
}
