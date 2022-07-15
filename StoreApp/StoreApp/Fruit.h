#pragma once
#include "StoreItem.h"

class Fruit : public StoreItem{
private:
	char* name;
	char* color;
public:
	Fruit();
	Fruit(int, double, char*, char*);
	Fruit(int, double, const char*, const char*);
	Fruit(const Fruit&);
	Fruit(Fruit&&) noexcept;
	Fruit& operator=(const Fruit&);
	Fruit& operator=(Fruit&&) noexcept;
	~Fruit();
	void copy(const Fruit&);
	void free();

	void setName(char*);
	void setColor(char*);
	void setName(const char*);
	void setColor(const char*);
	
	char* getName() const;
	char* getColor() const;
	
	virtual void print() const override;
	bool operator>(const Fruit&) const;
};


