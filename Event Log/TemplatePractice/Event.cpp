#include "Event.h"

Event::Event() : description{nullptr}{}

Event::Event(char* description) {
	this->description = new char[sizeof(description) / sizeof(description[0]) + 1];
	strcpy_s(this->description, sizeof(description) / sizeof(description[0]) + 1, description);
}

Event::Event(const Event& other) {
	this->description = new char[sizeof(other.description) / sizeof(other.description[0]) + 1];
	strcpy_s(this->description, sizeof(other.description) / sizeof(other.description[0]) + 1, other.description);
}

Event& Event::operator=(const Event& other) {
	if (this != &other) {
		delete[] this->description;
		this->description = new char[sizeof(other.description) / sizeof(other.description[0]) + 1];
		strcpy_s(this->description, sizeof(other.description) / sizeof(other.description[0]) + 1, other.description);
	}
	return *this;
}

Event::~Event() {
	delete[] description;
}

void Event::print() {
	std::cout << description;
}
