/*
 * RsrcMgr.h
 *
 *  Created on: Oct 28, 2021
 *      Author: tomislav
 */

#ifndef MANAGERS_INCLUDE_MANAGERS_MGR_RSRCMGR_H_
#define MANAGERS_INCLUDE_MANAGERS_MGR_RSRCMGR_H_

#include "managers/mgr/MgrBase.h"

#include "sdl_utils/containers/ImageContainer.h"
#include "sdl_utils/containers/TextContainer.h"

struct RsrcMgrCfg;

class RsrcMgr: public MgrBase, public ImageContainer, public TextContainer
{
public:
	RsrcMgr() = default;

	RsrcMgr(const RsrcMgr& other) = delete;
	RsrcMgr(RsrcMgr&& other) = delete;

	RsrcMgr operator=(const RsrcMgr& other) = delete;
	RsrcMgr operator=(RsrcMgr&& other) = delete;

	int32_t init(const RsrcMgrCfg& rsrcMgr_cfg);

	void deinit() override;
	void process() override;
};

extern RsrcMgr* gRsrcMgr;

#endif /* MANAGERS_INCLUDE_MANAGERS_MGR_RSRCMGR_H_ */
