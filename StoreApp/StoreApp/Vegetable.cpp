#include "Vegetable.h"

Vegetable::Vegetable(int cal, double price, char* name, char* color) : StoreItem(FRUIT, cal, price) {
	setName(name);
	setSort(color);
}

Vegetable::Vegetable(int cal, double price,const char* name,const char* color) : StoreItem(FRUIT, cal, price) {
	setName(name);
	setSort(color);
}

Vegetable::Vegetable() : StoreItem(FRUIT, 0, 0.0) {
	name = nullptr;
	sort = nullptr;
}

Vegetable::Vegetable(const Vegetable& other) {
	copy(other);
}

Vegetable::Vegetable(Vegetable&& other) noexcept {
	type = other.type;
	calories = other.calories;
	price = other.price;
	name = other.name;
	sort = other.sort;
	other.name = nullptr;
	other.sort = nullptr;
}

Vegetable& Vegetable::operator=(const Vegetable& other) {
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

Vegetable& Vegetable::operator=(Vegetable&& other) noexcept {
	if (this != &other) {
		free();
		type = other.type;
		calories = other.calories;
		price = other.price;
		name = other.name;
		sort = other.sort;
		other.name = nullptr;
		other.sort = nullptr;
	}
	return *this;
}

Vegetable::~Vegetable() {
	free();
}


void Vegetable::copy(const Vegetable& other) {
	type = other.type;
	calories = other.calories;
	price = other.price;
	name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	sort = new char[strlen(other.sort) + 1];
	strcpy_s(this->sort, strlen(other.sort) + 1, other.sort);
}

void Vegetable::free() {
	delete[] name;
	delete[] sort;
}

void Vegetable::setName(char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Vegetable::setSort(char* color) {
	this->sort = new char[strlen(color) + 1];
	strcpy_s(this->sort, strlen(color) + 1, color);
}

void Vegetable::setName(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Vegetable::setSort(const char* color) {
	this->sort = new char[strlen(color) + 1];
	strcpy_s(this->sort, strlen(color) + 1, color);
}

char* Vegetable::getName() const {
	return name;
}

char* Vegetable::getSort() const {
	return sort;
}

void Vegetable::print() const {
	std::cout << "This prduct is a " << name << std::endl;
	std::cout << "It's sort is " << sort << std::endl;
	std::cout << "It's price is " << price << std::endl;
	std::cout << "And it contains " << calories << " calories" << std::endl;
	std::cout << std::endl;
}

bool Vegetable::operator==(const Vegetable& other) const {
	return (strcmp(this->sort, other.sort));
}