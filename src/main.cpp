#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>


#include "engine/Engine.h"
#include "engine/EngineConfigLoader.h"
#include "sdl_utils/SDLLoader.h"

static int32_t runApplication()
{
	//ManagerHandler mgrHandler;
	Engine engine;

	if(EXIT_SUCCESS != engine.init(EngineConfigLoader::loadConfig()))
	{
		std::cerr << "engine.init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	engine.start();

	engine.deinit();

	return EXIT_SUCCESS;
}

int32_t main([[maybe_unused]]int32_t argc, [[maybe_unused]]char* argv[])
{

	if(EXIT_SUCCESS != SDL_Loader::init())
	{
		std::cerr << "SDL_Loader::init() failed" << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != runApplication())
	{
		std::cerr << "runApplication() failed" << std::endl;
		return EXIT_FAILURE;
	}

	SDL_Loader::deinit();

	return EXIT_SUCCESS;
}
