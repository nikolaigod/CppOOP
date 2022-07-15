#include "StoreItem.h"

StoreItem::StoreItem() : StoreItem(FRUIT, 0, 0.0){}

StoreItem::StoreItem(Type type, int calories, double price) : type{type}, calories{calories}, price{price}{}

void StoreItem::setType(Type type) {
	this->type = type;
}

void StoreItem::setCalories(int calories) {
	this->calories = calories;
}

void StoreItem::setPrice(double price) {
	this->price = price;
}

Type StoreItem::getType() const {
	return type;
}
int StoreItem::getCalories() const {
	return calories;
}
double StoreItem::getPrice() const {
	return price;
}