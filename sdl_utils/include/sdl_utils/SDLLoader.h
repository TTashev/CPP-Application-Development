/*
 * SDLLoader.h
 *
 *  Created on: Oct 10, 2021
 *      Author: tomislav
 */

#ifndef SDL_UTILS_SDLLOADER_H_
#define SDL_UTILS_SDLLOADER_H_

#include <cstdint>

class SDL_Loader
{
public:
	SDL_Loader() = default;
	~SDL_Loader() = default;

	static int32_t init();

	static void deinit();

};

#endif /* SDL_UTILS_SDLLOADER_H_ */
