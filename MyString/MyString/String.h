#pragma once
#include <iostream>

class String {
private:
	char* text;
	int size;
public:
	String();
	String(char*);
	String(const String&);
	String(const char[]);
	String& operator=(const String&);
	String& operator=(const char[]);
	~String();

	String operator+(const String&);
	String& operator+=(const String&);
	char operator[](int);

	int lenght();
	void print();
};


