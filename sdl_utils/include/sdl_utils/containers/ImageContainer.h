/*
 * ImageContainer.h
 *
 *  Created on: Oct 20, 2021
 *      Author: tomislav
 */

#ifndef SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_
#define SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_

#include <cstdint>
#include <unordered_map>

#include "sdl_utils/config/ImageContainerCfg.h"
#include "utils/drawing/Rectangle.h"

struct SDL_Texture;
struct ImageContainerCfg;
struct ImageCfg;

using Frames = std::vector<Rectangle>;

class ImageContainer
{
public:
	int32_t init(const ImageContainerCfg& cfg);

	void deinit();

	SDL_Texture* getImageTexture(int32_t rsrcId) const;

	const Frames& getImageFrame(int32_t rsrcId) const;

private:
	int32_t loadSingleResource(const ImageCfg& imgCfg, int32_t rsrcID);
private:
	std::unordered_map<int32_t, SDL_Texture*> _textures;
	std::unordered_map<int32_t, Frames> _textureFrames;
};

#endif /* SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_ */
