#include "EventLog.h"


EventLog::EventLog() : events{nullptr}, size{0}, cappacity{5}{}

EventLog::EventLog(int cappacity) {
	events = new Event[cappacity];
	this->cappacity = cappacity;
	size = 0;
}

EventLog::EventLog(const EventLog& other) {
	this->events = new Event[other.cappacity + 1];
	for (size_t i = 0; i < other.cappacity; i++) {
		this->events[i] = other.events[i];
	}
	this->size = other.size;
	this->cappacity = other.cappacity;
}

EventLog& EventLog::operator=(const EventLog& other) {
	if (this != &other) {
		delete[] this->events;
		this->events = new Event[other.cappacity + 1];
		for (size_t i = 0; i < other.cappacity; i++) {
			this->events[i] = other.events[i];
		}
		this->size = other.size;
		this->cappacity = other.cappacity;
	}
	return *this;
}

EventLog::~EventLog() {
	delete[] events;
}

void EventLog::addEvent(const Event& event) {
	if (size == cappacity) {
		resize();
	}
	events[size] = event;
	size++;
}

void EventLog::printEvent() {
	for (int i = 0; i < size; i++) {
		events[i].print();
	}
}

void EventLog::resize() {
	cappacity *= 2;
	Event* temp = new Event[cappacity];
	for (size_t i = 0; i < size; i++) {
		temp[i] = events[i];
	}
	delete[] events;
	events = new Event[cappacity];
	events = temp;
	delete[] temp;
}

