#pragma once
#include<iostream>
enum Type {
	VEGETABLE = 0,
	FRUIT = 1
};

class StoreItem {
protected:
	Type type;
	int calories;
	double price;
public:
	StoreItem();
	StoreItem(Type, int, double);
	void setType(Type);
	void setCalories(int);
	void setPrice(double);
	Type getType() const;
	int getCalories() const;
	double getPrice() const;
	virtual void print() const = 0;
};

