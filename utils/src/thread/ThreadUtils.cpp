/*
 * ThreadUtils.cpp
 *
 *  Created on: Oct 14, 2021
 *      Author: tomislav
 */

#include "utils/thread/ThreadUtils.h"

#include <thread>

#ifdef _WIN32
#include <windows.h>
#else
#include <thread>
#endif

void ThreadUtils::sleepFor(int64_t microseconds)
{
	if(0 > microseconds)
	{
		return;
	}

#ifdef _WIN32
	const DWORD milliseconds = static_cast<DWORD>(microseconds / 1000);
	Sleep(milliseconds); //sleep uses milliseconds
#else
	std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
#endif
}
