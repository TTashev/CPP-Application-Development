/*
 * TimerClient.cpp
 *
 *  Created on: Nov 3, 2021
 *      Author: tomislav
 */

#include "managers/time/TimerClient.h"
#include "managers/mgr/TimerMgr.h"

#include <iostream>


void TimerClient::startTimer(int64_t p_interval, int32_t p_timerId, TimerType p_timerType)
{
	if(!gTimerMgr)
	{
		return;
	}

	constexpr auto minTimerInterval = 20; // ms
	if(p_interval < minTimerInterval)
	{
		std::cerr << "Timer with id: " << p_timerId
				<< " requested inerval"
				<< " lower than minimal: " << minTimerInterval << "ms" << std::endl;
		return;
	}

	const TimerData l_timerData {p_interval, p_interval, this, p_timerType};
	gTimerMgr->startTimer(p_timerId, l_timerData);
}

void TimerClient::stopTimer(int32_t p_timerId)
{
	if(!gTimerMgr)
	{
		return;
	}

	gTimerMgr->stopTimer(p_timerId);
}

bool TimerClient::isActiveTimerId(int32_t p_timerId) const
{
	if(!gTimerMgr)
	{
		return false;
	}

	return gTimerMgr->isActiveTimerId(p_timerId);
}
