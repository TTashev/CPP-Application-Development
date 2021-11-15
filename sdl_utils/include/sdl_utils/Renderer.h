/*
 * Renderer.h
 *
 *  Created on: Oct 18, 2021
 *      Author: tomislav
 */

#ifndef SDL_UTILS_RENDERER_H_
#define SDL_UTILS_RENDERER_H_

#include <cstdint>

#include "utils/drawing/DrawParams.h"

struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Window;

class Renderer
{
public:
	Renderer() = default;

	Renderer(const Renderer& other) = delete;
	Renderer(Renderer&& other) = delete;

	Renderer& operator=(const Renderer& other) = delete;
	Renderer& operator=(Renderer&& other) = delete;

	int32_t init(SDL_Window *window);
	void deinit();
	void clearScreen();
	void finishFrame();
	void renderTexture(SDL_Texture *texture, const DrawParams& drawParams);

	void setWidgetBlendMode(SDL_Texture* texture, BlendMode blendMode);
	void setWidgetOpacity(SDL_Texture* texture, int32_t opacity);

private:
	void drawImage(const DrawParams& drawParams, SDL_Texture *texture);
	void drawText(const DrawParams& drawParams, SDL_Texture *texture);

	void drawTextureInternal(const DrawParams& drawParams, SDL_Texture *texture);
private:
	//forbid the copy/move constructors and assignment operators
	SDL_Renderer *_sdlRenderer = nullptr;
};

#endif /* SDL_UTILS_RENDERER_H_ */
