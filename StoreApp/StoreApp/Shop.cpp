#include "Shop.h"

Shop::Shop() {	
	size = 0;
	cappasity = 5;
	items = new StoreItem * [cappasity];
}

Shop::~Shop() {
	for (size_t i = 0; i < size; i++) {
		delete items[i];
	}
	delete[] items;
}

void Shop::addItem(const Fruit& item) {
	if (size == cappasity) {
		resize();
	}
	items[size] = new Fruit(item.getCalories(), item.getPrice(), item.getName(), item.getColor());
	size++;
}

void Shop::addItem(const Vegetable& item) {
	if (size == cappasity) {
		resize();
	}
	items[size] = new Vegetable(item.getCalories(), item.getPrice(), item.getName(), item.getSort());
	size++;
}

void Shop::removeItem(int index) {
	for (size_t i = index; i < size; i++) {
		items[i] = items[i + 1];
	}
	items[size] = nullptr;
	size--;
}

void Shop::changePrice(int index, double price) {
	items[index]->setPrice(price);
}

//void changeName(int, const char*);
//void changeName(int, char*);

void Shop::print() const{
	for (size_t i = 0; i < size; i++) {
		items[i]->print();
	}
}

void Shop::resize() {
	cappasity *= 2;
	StoreItem** tmp = new StoreItem * [cappasity];
	for (size_t i = 0; i < size; i++) {
		tmp[i] = items[i];
	}
	for (size_t i = 0; i < size; i++) {
		delete items[i];
	}
	delete[] items;
	items = new StoreItem * [cappasity];
	items = tmp;
	tmp = nullptr;
}