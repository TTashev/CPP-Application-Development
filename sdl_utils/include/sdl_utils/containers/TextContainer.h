/*
 * TextContainer.h
 *
 *  Created on: Oct 22, 2021
 *      Author: tomislav
 */

#ifndef SDL_UTILS_CONTAINERS_TEXTCONTAINER_H_
#define SDL_UTILS_CONTAINERS_TEXTCONTAINER_H_

#include <cstdint>
#include <vector>
#include <unordered_map>
#include <string>

#include "sdl_utils/config/TextContainerCfg.h"

struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;
struct Color;

class TextContainer
{
public:
	int32_t init(const TextContainerCfg& cfg);
	void deinit();

	void createText(const std::string text, const Color& color, int32_t fontId,
											int32_t& textId, int32_t& textWidth,
											int32_t& textHeight);

	void reloadText(const std::string text, const Color& color, int32_t fontId,
											int32_t textId, int32_t& textWidth,
											int32_t& textHeight);

	void unloadText(int32_t textId);
	SDL_Texture* getTextTexture(int32_t textId) const;

private:
	void occupyFreeSlotIndex(int32_t& index);
	void freeSlotIndex(int32_t index);
private:
	//the textures we'll be drawing
	std::vector<SDL_Texture*> _textures;
	std::unordered_map<int32_t, TTF_Font*> _fonts;
};

#endif /* SDL_UTILS_CONTAINERS_TEXTCONTAINER_H_ */
