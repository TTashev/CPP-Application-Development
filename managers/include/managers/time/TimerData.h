/*
 * TimerData.h
 *
 *  Created on: Nov 3, 2021
 *      Author: tomislav
 */

#ifndef MANAGERS_INCLUDE_MANAGERS_TIME_TIMERDATA_H_
#define MANAGERS_INCLUDE_MANAGERS_TIME_TIMERDATA_H_

#include <cstdint>

struct TimerClient;

enum class TimerType : uint8_t
{
	ONESHOT,
	PULSE
};

struct TimerData
{
	TimerData(	int64_t p_inputInterval,
				int64_t p_inputRemaining,
				TimerClient* p_inputCcInstance,
				TimerType p_inputTimerType) :

				interval(p_inputInterval), remaining(p_inputRemaining),
				tcInstance(p_inputCcInstance), timerType(p_inputTimerType)
				{}

	int64_t interval;
	int64_t remaining;
	TimerClient* tcInstance = nullptr;
	TimerType timerType;
};



#endif /* MANAGERS_INCLUDE_MANAGERS_TIME_TIMERDATA_H_ */
