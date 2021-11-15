/*
 * TimerMgr.cpp
 *
 *  Created on: Nov 3, 2021
 *      Author: tomislav
 */

#include "managers/mgr/TimerMgr.h"
#include "managers/time/TimerClient.h"

#include <iostream>

TimerMgr* gTimerMgr = nullptr;

int32_t TimerMgr::init()
{
	_elapsedTime.getElapsed();

	return EXIT_SUCCESS;
}

void TimerMgr::deinit()
{

}

void TimerMgr::process()
{
	removeTimersInternal();

	const int64_t msElapsed = _elapsedTime.getElapsed().toMilliseconds();
	for (auto it = _timerMap.begin(); it != _timerMap.end(); ++it)
	{
		const int32_t timerId = it->first;
		TimerData& timerDAta = it->second;

		it->second.remaining -= msElapsed;
		if (0 > it->second.remaining)
		{
			onTimerTimeout(timerId, timerDAta);
		}
	}
	removeTimersInternal();
}

void TimerMgr::startTimer(int32_t timerId, const TimerData& p_timerData)
{
	if(isActiveTimerId(timerId))
	{
		std::cerr << "Error, trying to start an already existing timer with id: " << timerId << std::endl;
		return;
	}

	_timerMap.emplace(timerId, p_timerData);
}

void TimerMgr::stopTimer(int32_t timerId)
{
	if(!isActiveTimerId(timerId))
	{
		std::cerr << "Error, trying to stop non running timer with id: " << timerId << std::endl;
		return;
	}

	_removeTimerSet.insert(timerId);
}


bool TimerMgr::isActiveTimerId(int32_t timerId) const
{
	return (_removeTimerSet.end() == _removeTimerSet.find(timerId))
	&& (_timerMap.end() != _timerMap.find(timerId));
}

void TimerMgr::onInitEnd()
{
	_elapsedTime.getElapsed();
}

int64_t TimerMgr::getActiveTimersCount() const
{
	return _timerMap.size();
}

void TimerMgr::TimerMgr::removeTimersInternal()
{
	for (const int32_t timerId : _removeTimerSet)
	{
		auto mapIt = _timerMap.find(timerId);
		if (mapIt != _timerMap.end())
		{
			_timerMap.erase(mapIt);
		}
	}

	//clear the removeTimerSet
	_removeTimerSet.clear();
}

void TimerMgr::onTimerTimeout(int32_t p_timerId, TimerData& p_timer)
{
	if(TimerType::ONESHOT == p_timer.timerType)
	{
		_removeTimerSet.insert(p_timerId);
	}

	p_timer.tcInstance->onTimeout(p_timerId);
	p_timer.remaining += p_timer.interval;
}
