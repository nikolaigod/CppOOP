#pragma once
#include "Event.h"

class EventLog{
private:
	Event* events;
	int size;
	int cappacity;
public:
	EventLog();
	EventLog(int);
	EventLog(const EventLog&);
	EventLog& operator=(const EventLog&);
	~EventLog();
	void addEvent(const Event&);
	void printEvent();
	void resize();
};

