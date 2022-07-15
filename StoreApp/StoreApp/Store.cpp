#include <iostream>
#include "Fruit.h"
#include "Vegetable.h" 
#include "Shop.h"

int main()
{
	Fruit fruit(50, 2.5, "mango", "orange");
	//fruit.print();
	
	Vegetable vegetable(20, 1.2, "potato", "fat potatoe");
	//vegetable.print();
	
	Shop shop;
	shop.addItem(vegetable);
	shop.addItem(fruit);
	shop.removeItem(0);
	shop.changePrice(0, 100.5);
	shop.print();
	return 0;
}

