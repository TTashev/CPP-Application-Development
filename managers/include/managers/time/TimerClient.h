/*
 * TimerClient.h
 *
 *  Created on: Nov 3, 2021
 *      Author: tomislav
 */

#ifndef MANAGERS_INCLUDE_MANAGERS_TIME_TIMERCLIENT_H_
#define MANAGERS_INCLUDE_MANAGERS_TIME_TIMERCLIENT_H_

#include <cstdint>

#include "managers/time/TimerData.h"

class TimerClient
{
public:
	virtual ~TimerClient() = default;
	virtual void onTimeout(int32_t p_timerId) = 0;

	void startTimer(int64_t p_interval, int32_t p_timerId,
	TimerType p_timerType);
	void stopTimer(int32_t p_timerId);

	bool isActiveTimerId(int32_t p_timerId) const;
};

#endif /* MANAGERS_INCLUDE_MANAGERS_TIME_TIMERCLIENT_H_ */
