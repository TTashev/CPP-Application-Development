cmake_minimum_required(VERSION 3.5.1)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers.cmake)

set(CMAKE_MODULE_PATH 
	${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/find_modules)

project(Chess LANGUAGES CXX)

if(UNIX)
	set(SDL2_image_name SDL2_image)
	set(SDL2_ttf_name SDL2_ttf)
	set(SDL2_mixer_name SDL2_mixer)
elseif(WIN32 OR APPLE)
	set(SDL2_image_name SDL2_IMAGE)
	set(SDL2_ttf_name SDL2_TTF)
	set(SDL2_mixer_name SDL2_MIXER)
endif()

find_package(SDL2 REQUIRED)
find_package(${SDL2_image_name} REQUIRED)
find_package(${SDL2_ttf_name} REQUIRED)
find_package(${SDL2_mixer_name} REQUIRED)

set(_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} 

								${_INC_DIR}/common/CommonDefines.h
								${_INC_DIR}/engine/Engine.h
								${_INC_DIR}/engine/config/EngineConfig.h
								${_INC_DIR}/engine/EngineConfigLoader.h
								${_INC_DIR}/game/Game.h
								${_INC_DIR}/game/GameBoardInterface.h
								${_INC_DIR}/game/config/GameCfg.h
								${_INC_DIR}/game/board/GameBoard.h
								${_INC_DIR}/game/board/MoveSelector.h
								${_INC_DIR}/game/utils/BoardPos.h
								${_INC_DIR}/game/utils/BoardUtils.h
								${_INC_DIR}/game/pieces/types/ChessPiece.h
								${_INC_DIR}/game/pieces/types/Rook.h
								${_INC_DIR}/game/pieces/types/Pawn.h
								${_INC_DIR}/game/pieces/types/UnfinishedPiece.h
								${_INC_DIR}/game/pieces/PieceHandlerPopulator.h
								${_INC_DIR}/game/pieces/PieceHandler.h
								${_INC_DIR}/game/defines/ChessDefines.h
								${_INC_DIR}/game/defines/ChessStructs.h

								${_SRC_DIR}/engine/Engine.cpp
								${_SRC_DIR}/engine/EngineConfigLoader.cpp
								${_SRC_DIR}/game/Game.cpp
								${_SRC_DIR}/game/board/GameBoard.cpp
								${_SRC_DIR}/game/board/MoveSelector.cpp
								${_SRC_DIR}/game/utils/BoardUtils.cpp
								${_SRC_DIR}/game/pieces/types/ChessPiece.cpp
								${_SRC_DIR}/game/pieces/types/Rook.cpp
								${_SRC_DIR}/game/pieces/types/Pawn.cpp
								${_SRC_DIR}/game/pieces/types/UnfinishedPiece.cpp
								${_SRC_DIR}/game/pieces/PieceHandler.cpp
								${_SRC_DIR}/game/pieces/PieceHandlerPopulator.cpp
								${_SRC_DIR}/main.cpp
)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PRIVATE	${_INC_DIR} )

target_link_libraries(${PROJECT_NAME} PRIVATE	managers )
			
add_subdirectory(utils)
add_subdirectory(sdl_utils)
add_subdirectory(managers)

