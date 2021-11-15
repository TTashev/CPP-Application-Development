/*
 * DrawMgr.h
 *
 *  Created on: Oct 27, 2021
 *      Author: tomislav
 */

#ifndef MANAGERS_INCLUDE_MANAGERS_MGR_DRAWMGR_H_
#define MANAGERS_INCLUDE_MANAGERS_MGR_DRAWMGR_H_

#include <cstdint>

#include "managers/mgr/MgrBase.h"
#include "sdl_utils/MonitorWindow.h"
#include "sdl_utils/Renderer.h"

struct DrawMgrCfg;
struct DrawParams;

class DrawMgr: public MgrBase
{
public:
	DrawMgr() = default;

	DrawMgr(const DrawMgr& other) = delete;
	DrawMgr(DrawMgr&& other) = delete;

	DrawMgr operator=(const DrawMgr& other) = delete;
	DrawMgr operator=(DrawMgr&& other) = delete;

	int32_t init(const DrawMgrCfg& drawMgr_cfg);

	void deinit() override;
	void process() override;

	void clearScreen();
	void finishFrame();
	void addDrawCmd(const DrawParams& p_drawParams);

	void setWidgetBlendMode(const DrawParams& drawParams, BlendMode blendMode);
	void setWidgetOpacity(const DrawParams& drawParams, int32_t opacity);

	int64_t getMaxFrames() const;

private:
	SDL_Texture* getTextureInternal(const DrawParams& p_drawParams) const;

	Renderer _renderer;
	MonitorWindow _window;

	//Hold maximum frame rate cap
	int64_t _maxFrames { 0 };
};
extern DrawMgr *gDrawMgr;

#endif /* MANAGERS_INCLUDE_MANAGERS_MGR_DRAWMGR_H_ */
