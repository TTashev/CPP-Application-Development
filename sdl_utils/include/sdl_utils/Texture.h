/*
 * Texture.h
 *
 *  Created on: Oct 12, 2021
 *      Author: tomislav
 */

#ifndef SDL_UTILS_TEXTURE_H_
#define SDL_UTILS_TEXTURE_H_

#include <cstdint>
#include <string>

#include "utils/drawing/DrawParams.h"

struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;

typedef struct _TTF_Font TTF_Font;
struct Color;

class Texture
{
public:
	Texture() = default;
	~Texture();

	static int32_t createSurfaceFromFile(const std::string& filePath, SDL_Surface*& surface);
	static int32_t createTextureFromFile(const std::string& filePath, SDL_Texture*& texture);

	static int32_t createTextureFromSurface(SDL_Surface*& surface, SDL_Texture*& texture);

	static int32_t createTextureFromText(const std::string text, const Color& color,
																TTF_Font* font,
																SDL_Texture*& texture,
																int32_t& textWidth,
																int32_t& textHeight);

	static void freeSurface(SDL_Surface*& surface);
	static void freeTexture(SDL_Texture*& texture);

	static void setRenderer(SDL_Renderer* renderer);

	static int32_t setBlendModeTexture(SDL_Texture *texture, BlendMode blendMode);

	static int32_t setAlphaTexture(SDL_Texture *texture, int32_t alpha);
};

#endif /* SDL_UTILS_TEXTURE_H_ */
