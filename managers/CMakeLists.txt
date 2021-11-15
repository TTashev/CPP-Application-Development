cmake_minimum_required(VERSION 3.5.1)

project(managers LANGUAGES CXX)

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(_INC_DIR ${_BASE_DIR}/managers)
set(_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(${PROJECT_NAME} STATIC

			${_INC_DIR}/config/DrawMgrCfg.h
			${_INC_DIR}/config/RsrcMgrCfg.h
			${_INC_DIR}/mgr/MgrBase.h
			${_INC_DIR}/mgr/DrawMgr.h
			${_INC_DIR}/mgr/RsrcMgr.h
			${_INC_DIR}/mgr/TimerMgr.h
			${_INC_DIR}/mgr/MgrHandler.h
			${_INC_DIR}/debug/DebugConsole.h
			${_INC_DIR}/drawing/Widget.h
			${_INC_DIR}/drawing/Image.h
			${_INC_DIR}/drawing/Text.h
			${_INC_DIR}/input/ButtonBase.h
			${_INC_DIR}/time/TimerClient.h
			${_INC_DIR}/time/TimerData.h


			${_SRC_DIR}/time/TimerClient.cpp
			${_SRC_DIR}/input/ButtonBase.cpp
			${_SRC_DIR}/debug/DebugConsole.cpp
			${_SRC_DIR}/drawing/Image.cpp
			${_SRC_DIR}/drawing/Text.cpp
			${_SRC_DIR}/drawing/Widget.cpp
			${_SRC_DIR}/mgr/DrawMgr.cpp
			${_SRC_DIR}/mgr/RsrcMgr.cpp 
			${_SRC_DIR}/mgr/TimerMgr.cpp 
			${_SRC_DIR}/mgr/MgrHandler.cpp)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC	${_BASE_DIR})


target_link_libraries(${PROJECT_NAME} PUBLIC sdl_utils)

