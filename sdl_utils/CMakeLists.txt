cmake_minimum_required(VERSION 3.5.1)

project(sdl_utils LANGUAGES CXX)

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(_INC_DIR ${_BASE_DIR}/sdl_utils)
set(_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(${PROJECT_NAME} STATIC
			
			${_INC_DIR}/SDLLoader.h
			${_INC_DIR}/MonitorWindow.h
			${_INC_DIR}/config/MonitorWindowCfg.h
			${_INC_DIR}/config/ImageContainerCfg.h
			${_INC_DIR}/config/TextContainerCfg.h
			${_INC_DIR}/Texture.h
			${_INC_DIR}/InputEvent.h
			${_INC_DIR}/Renderer.h
			${_INC_DIR}/containers/ImageContainer.h
			${_INC_DIR}/containers/TextContainer.h


			${_SRC_DIR}/SDLLoader.cpp
			${_SRC_DIR}/MonitorWindow.cpp
			${_SRC_DIR}/Texture.cpp
			${_SRC_DIR}/InputEvent.cpp
			${_SRC_DIR}/Renderer.cpp
			${_SRC_DIR}/containers/ImageContainer.cpp
			${_SRC_DIR}/containers/TextContainer.cpp )

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC	${_BASE_DIR} PRIVATE
													${SDL2_INCLUDE_DIR}
													${SDL2_IMAGE_INCLUDE_DIR}
													${SDL2_TTF_INCLUDE_DIR}
													${SDL2_MIXER_INCLUDE_DIR})


target_link_libraries(${PROJECT_NAME} PUBLIC	utils PRIVATE
												${SDL2_LIBRARY}
												${SDL2_IMAGE_LIBRARY} 
												${SDL2_TTF_LIBRARY}
												${SDL2_MIXER_LIBRARY})

