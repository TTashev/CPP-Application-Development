/*
 * RsrcMgr.cpp
 *
 *  Created on: Oct 28, 2021
 *      Author: tomislav
 */

#include <iostream>
#include "managers/mgr/RsrcMgr.h"
#include "managers/config/RsrcMgrCfg.h"

RsrcMgr* gRsrcMgr = nullptr;

int32_t RsrcMgr::init(const RsrcMgrCfg& rsrcMgr_cfg)
{
	if(EXIT_SUCCESS != ImageContainer::init(rsrcMgr_cfg.imageContainerCfg))
	{
		std::cerr << "_imgContainer() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != TextContainer::init(rsrcMgr_cfg.textContainerCfg))
	{
		std::cerr << "_textContainer() failed" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void RsrcMgr::deinit()
{
	ImageContainer::deinit();
	TextContainer::deinit();
}

void RsrcMgr::process()
{

}
