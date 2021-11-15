/*
 * DrawMgr.cpp
 *
 *  Created on: Oct 27, 2021
 *      Author: tomislav
 */

#include "managers/mgr/DrawMgr.h"
#include "managers/config/DrawMgrCfg.h"
#include "managers/mgr/RsrcMgr.h"

#include <iostream>

DrawMgr* gDrawMgr = nullptr;

int32_t DrawMgr::init(const DrawMgrCfg& drawMgr_cfg)
{

	if(EXIT_SUCCESS != _window.init(drawMgr_cfg.windowCfg))
	{
		std::cerr << "window.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != _renderer.init(_window.getWindow()))
	{
		std::cerr << "loadResources() failed" << std::endl;
		return EXIT_FAILURE;
	}

	_maxFrames = drawMgr_cfg.MaxFPS;

	return EXIT_SUCCESS;
}

void DrawMgr::deinit()
{
	_renderer.deinit();
	_window.deinit();
}

void DrawMgr::process()
{

}

void DrawMgr::clearScreen()
{
	_renderer.clearScreen();
}

void DrawMgr::finishFrame()
{
	_renderer.finishFrame();
}

void DrawMgr::addDrawCmd(const DrawParams &p_drawParams)
{
	SDL_Texture* texture = getTextureInternal(p_drawParams);
	_renderer.renderTexture(texture, p_drawParams);
}

void DrawMgr::setWidgetBlendMode(const DrawParams &drawParams,
		BlendMode blendMode)
{
	SDL_Texture* texture = getTextureInternal(drawParams);
	_renderer.setWidgetBlendMode(texture, blendMode);
}

void DrawMgr::setWidgetOpacity(const DrawParams &drawParams, int32_t opacity)
{
	if(drawParams.widgetType == WidgetType::IMAGE)
	{
		return;
	}

	SDL_Texture* texture = getTextureInternal(drawParams);
	_renderer.setWidgetOpacity(texture, opacity);
}

int64_t DrawMgr::getMaxFrames() const
{
	return _maxFrames;
}

SDL_Texture* DrawMgr::getTextureInternal(const DrawParams& p_drawParams) const
{
	if(WidgetType::IMAGE == p_drawParams.widgetType)
	{
		return gRsrcMgr->getImageTexture(p_drawParams.rsrcId);
	}
	else if(WidgetType::TEXT == p_drawParams.widgetType)
	{
		return gRsrcMgr->getTextTexture(p_drawParams.textId);
	}
	else
	{
		std::cerr << "Error, received unsupported WidgeType: "
				<< static_cast<int32_t>(p_drawParams.widgetType) << "for rsrcID: "
				<< p_drawParams.rsrcId << std::endl;
	}
	return nullptr;
}
