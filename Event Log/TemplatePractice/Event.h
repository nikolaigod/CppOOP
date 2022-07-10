#pragma once
#include<iostream>

class Event{
private:
	char* description;
public:
	Event();
	Event(char*);
	Event(const Event&);
	Event& operator=(const Event&);
	~Event();
	void print();
};

