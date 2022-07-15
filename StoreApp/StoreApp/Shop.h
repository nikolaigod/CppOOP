#pragma once
#include "StoreItem.h"
#include "Fruit.h"
#include "Vegetable.h"

class Shop {
private:
	StoreItem** items;
	int size;
	int cappasity;
public:
	Shop();
	~Shop();
	void addItem(const Fruit&);
	void addItem(const Vegetable&); 

	void removeItem(int);

	//void addItem(Fruit&&);
	//void addItem(Vegetable&&);

	void changePrice(int, double);
	//void changeName(int, const char*);
	//void changeName(int, char*);

	void print() const;
	//void mostCalories() const;
	void resize();
};

