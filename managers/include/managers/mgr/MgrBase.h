/*
 * MgrBase.h
 *
 *  Created on: Oct 27, 2021
 *      Author: tomislav
 */

#ifndef MANAGERS_INCLUDE_MANAGERS_MGR_MGRBASE_H_
#define MANAGERS_INCLUDE_MANAGERS_MGR_MGRBASE_H_

enum
{
	DRAW_MGR,
	RSRC_MGR,
	TIMER_MGR,
	MANAGERS_COUNT
};

class MgrBase
{
public:
	MgrBase() = default;
	virtual ~MgrBase() = default;

	MgrBase(const MgrBase& other) = delete;
	MgrBase(MgrBase&& other) = delete;

	MgrBase& operator=(const MgrBase& other) = delete;
	MgrBase& operator=(MgrBase&& other) = delete;

	virtual void deinit() = 0;
	virtual void process() = 0;
};

#endif /* MANAGERS_INCLUDE_MANAGERS_MGR_MGRBASE_H_ */
