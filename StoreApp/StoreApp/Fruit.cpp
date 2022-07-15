#include "Fruit.h"

Fruit::Fruit(int cal, double price, char* name, char* color) : StoreItem(FRUIT ,cal, price) {
	setName(name);
	setColor(color);
}

Fruit::Fruit(int cal, double price, const char* name, const char* color) : StoreItem(FRUIT, cal, price) {
	setName(name);
	setColor(color);
}

Fruit::Fruit() : StoreItem(FRUIT, 0, 0.0) {
	name = nullptr;
	color = nullptr;
}

Fruit::Fruit(const Fruit& other) {
	copy(other);
}

Fruit::Fruit(Fruit&& other) noexcept{
	type = other.type;
	calories = other.calories;
	price = other.price;
	name = other.name;
	color = other.color;
	other.name = nullptr;
	other.color = nullptr;
}

Fruit& Fruit::operator=(const Fruit& other) {
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

Fruit& Fruit::operator=(Fruit&& other) noexcept{
	if (this != &other) {
		free();
		type = other.type;
		calories = other.calories;
		price = other.price;
		name = other.name;
		color = other.color;
		other.name = nullptr;
		other.color = nullptr;
	}
	return *this;
}

Fruit::~Fruit() {
	free();
}


void Fruit::copy(const Fruit& other) {
	type = other.type;
	calories = other.calories;
	price = other.price;
	name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	color = new char[strlen(other.color) + 1];
	strcpy_s(this->color, strlen(other.color) + 1, other.color);
}

void Fruit::free() {
	delete[] name;
	delete[] color;
}

void Fruit::setName(char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Fruit::setColor(char* color) {
	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);
}

void Fruit::setName(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Fruit::setColor(const char* color) {
	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);
}

char* Fruit::getName() const{
	return name;
}

char* Fruit::getColor() const {
	return color;
}

void Fruit::print() const{
	std::cout << "This product is a " << name << std::endl;
	std::cout << "It's color is " << color << std::endl;
	std::cout << "It's price is " << price << std::endl;
	std::cout << "And it contains " << calories << " calories" << std::endl;
	std::cout << std::endl;
}

bool Fruit::operator>(const Fruit& other) const {
	return (this->calories > other.calories);
}