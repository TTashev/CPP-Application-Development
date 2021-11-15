/*
 * TimerMgr.h
 *
 *  Created on: Nov 3, 2021
 *      Author: tomislav
 */

#ifndef MANAGERS_INCLUDE_MANAGERS_MGR_TIMERMGR_H_
#define MANAGERS_INCLUDE_MANAGERS_MGR_TIMERMGR_H_

#include <unordered_map>
#include <unordered_set>
#include <cstdint>

#include "managers/mgr/MgrBase.h"
#include "managers/time/TimerData.h"
#include "utils/time/Time.h"

class TimerMgr: public MgrBase
{
public:
	int32_t init();

	void deinit() final;
	void process() final;
	void startTimer(int32_t timerId, const TimerData& p_timerData);
	void stopTimer(int32_t timerId);
	bool isActiveTimerId(int32_t timerId) const;
	void onInitEnd();

	int64_t getActiveTimersCount() const;

private:
	void removeTimersInternal();

	void onTimerTimeout(int32_t p_timerId, TimerData& p_timer);
private:
	Time _elapsedTime;
	std::unordered_map<int32_t, TimerData> _timerMap;
	std::unordered_set<int32_t> _removeTimerSet;
};

extern TimerMgr* gTimerMgr;

#endif /* MANAGERS_INCLUDE_MANAGERS_MGR_TIMERMGR_H_ */
