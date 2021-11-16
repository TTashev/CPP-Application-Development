/*
 * EngineConfigLoader.cpp
 *
 *  Created on: Oct 16, 2021
 *      Author: tomislav
 */

#include "engine/EngineConfigLoader.h"

#include "game/config/GameCfg.h"
#include "common/CommonDefines.h"

static constexpr auto WINDOW_WIDTH = 900;
static constexpr auto WINDOW_HEIGHT = 900;
static constexpr auto WINDOW_NAME = "Chess!";

constexpr auto CHESS_PIECES_FRAMES = 6;
constexpr auto CHESS_PIECES_SIZE = 96;

constexpr auto CHESS_BOARD_SIZE = 900;

constexpr auto TARGET_IMG_SIZE = 98;

constexpr auto MOVE_TILES_FRAMES = 3;
constexpr auto MOVE_TILES_IMG_SIZE = 98;

constexpr auto ANGELINE_VINTAGE_40_FONT_SIZE = 40;

constexpr auto MAX_FPS = 60;

static void populateTextContainerConfig(TextContainerCfg& p_cfg)
{
	FontCfg fontCfg;
	fontCfg.location = "../resources/f/AngelineVintage.ttf";
	fontCfg.fontSize = ANGELINE_VINTAGE_40_FONT_SIZE;
	p_cfg.fontConfigs.insert(std::make_pair(FontId::ANGELINE_VINTAGE_40, fontCfg));
}

static void populateImageContainerConfig(ImageContainerCfg& p_cfg)
{
	ImageCfg imageCfg;

	// CHESS PIECES
	const int32_t buttons_cnt = 2;
	const std::string buttonPaths[buttons_cnt] =
	{
		"../resources/p/whitePieces.png",
		"../resources/p/blackPieces.png"
	};
	const int32_t buttonRsrcIds[buttons_cnt] =
	{
		TextureId::WHITE_PIECES,
		TextureId::BLACK_PIECES
	};
	for (int32_t i = 0; i < buttons_cnt; ++i)
	{
		imageCfg.location = buttonPaths[i];
		for (int32_t frameId = 0; frameId < CHESS_PIECES_FRAMES; ++frameId)
		{
			imageCfg.frames.emplace_back(frameId * CHESS_PIECES_SIZE,	// x
											0,							// y
											CHESS_PIECES_SIZE,		// width
											CHESS_PIECES_SIZE);	// height
		}
		p_cfg.imageConfigs.emplace(buttonRsrcIds[i],imageCfg);
		imageCfg.frames.clear();
	}

	// CHESS BOARD
	imageCfg.location = "../resources/p/chessBoard.jpg";
	imageCfg.frames.emplace_back(0, 0, CHESS_BOARD_SIZE, CHESS_BOARD_SIZE);
	p_cfg.imageConfigs.emplace(TextureId::CHESS_BOARD,imageCfg);
	imageCfg.frames.clear();

	imageCfg.location = "../resources/p/target.png";
	imageCfg.frames.emplace_back(0, 0, TARGET_IMG_SIZE, TARGET_IMG_SIZE);
	p_cfg.imageConfigs.emplace(TextureId::TARGET,imageCfg);
	imageCfg.frames.clear();

	imageCfg.location = "../resources/p/moveTiles.png";
	for (int32_t frameId = 0; frameId < MOVE_TILES_FRAMES; ++frameId)
	{
		imageCfg.frames.emplace_back(frameId * MOVE_TILES_IMG_SIZE,	// x
										0,							// y
										MOVE_TILES_IMG_SIZE,		// width
										MOVE_TILES_IMG_SIZE);	// height
	}
	p_cfg.imageConfigs.emplace(TextureId::MOVE_TILES,imageCfg);
	imageCfg.frames.clear();

}

static void populateMonitorConfig(MonitorWindowCfg& p_windowCfg)
{
	p_windowCfg.windowName = WINDOW_NAME;
	p_windowCfg.windowWidth = WINDOW_WIDTH;
	p_windowCfg.windowHeight = WINDOW_HEIGHT;
	p_windowCfg.windowFlags = WINDOW_SHOWN;
}

static void populateRsrcMgrConfig(RsrcMgrCfg& p_RsrcMgrCfg)
{
	populateImageContainerConfig(p_RsrcMgrCfg.imageContainerCfg);
	populateTextContainerConfig(p_RsrcMgrCfg.textContainerCfg);
}

static void populateDrawMgrConfig(DrawMgrCfg& p_DrawMgrCfg)
{
	populateMonitorConfig(p_DrawMgrCfg.windowCfg);
	p_DrawMgrCfg.MaxFPS = MAX_FPS;
}

static void populateManagerHandlerConfig(ManagerHandlerCfg& p_cfg)
{
	populateDrawMgrConfig(p_cfg.drawMgrCfg);
	populateRsrcMgrConfig(p_cfg.rsrcMgrCfg);
}

static void populateGameConfig(GameCfg& p_cfg)
{
	p_cfg.chessBoardRsrcId = TextureId::CHESS_BOARD;
	p_cfg.whitePiecesRsrcId= TextureId::WHITE_PIECES;
	p_cfg.blackPiecesRsrcId= TextureId::BLACK_PIECES;
	p_cfg.targetRsrcId= TextureId::TARGET;
	p_cfg.moveTilesRsrcId = TextureId::MOVE_TILES;

	p_cfg.unfinishedPieceFontId = FontId::ANGELINE_VINTAGE_40;

	p_cfg.blinkTargetTimerId = TimerId::BLINK_TARGET_TIMER_ID;
}

EngineCfg EngineConfigLoader::loadConfig()
{
	EngineCfg cfg;

	populateManagerHandlerConfig(cfg.managerHandlerCfg);

	populateGameConfig(cfg.gameCfg);
	cfg.debugConsoleFontId = FontId::ANGELINE_VINTAGE_40;

	return cfg;
}

