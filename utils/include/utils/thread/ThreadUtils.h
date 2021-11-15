/*
 * ThreadUtils.h
 *
 *  Created on: Oct 14, 2021
 *      Author: tomislav
 */

#ifndef UTILS_THREAD_THREADUTILS_H_
#define UTILS_THREAD_THREADUTILS_H_

#include <cstdint>

class ThreadUtils
{
public:
	ThreadUtils() {};
	~ThreadUtils() {};

	static void sleepFor(int64_t microseconds);
};

#endif /* UTILS_THREAD_THREADUTILS_H_ */
