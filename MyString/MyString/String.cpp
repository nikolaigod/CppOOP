#include "String.h"

String::String() : size{ 0 }{
	text = new char[size];
}

String::String(char* text) {
	size = strlen(text) + 1;
	this->text = new char[size];
	strcpy_s(this->text, size, text);
}

String::String(const String& other) {
	size = other.size + 1;
	this->text = new char[size];
	strcpy_s(this->text, size, other.text);
}

String::String(const char other []) {
	size = strlen(other) + 1;
	text = new char[size];
	strcpy_s(text, size, other);
	
}

String& String::operator=(const String& other) {
	if (this != &other) {
		delete[] text;
		size = other.size + 1;
		this->text = new char[size];
		strcpy_s(this->text, size, other.text);
	}
	return *this;
}

String& String::operator=(const char other []) {
	size = strlen(other) + 1;
	text = new char[size];
	strcpy_s(text, size, other);
	return *this;
}

int String::lenght() {
	return size;
}

char String::operator[](int index) {
	return text[index];
}

String::~String() {
	delete[] text;
}

String String::operator+(const String& other) {
	char* tmp = new char[(size + other.size) + 1];
	strcpy_s(tmp, (size + other.size) + 1, text);
	strcat_s(tmp, (size + other.size) + 1, other.text);
	String ret(tmp);
	return ret;
}

String& String::operator+=(const String & other) {
	char* tmp = new char[(size + other.size) + 1];
	strcpy_s(tmp, (size + other.size) + 1, text);
	strcat_s(tmp, (size + other.size) + 1, other.text);
	delete[] text;
	text = new char[(size + other.size) + 1];
	text = tmp;
	tmp = nullptr;
	return *this;
}

void String::print() {
	std::cout << text;
}