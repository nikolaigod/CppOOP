#pragma once
#include "StoreItem.h"

class Vegetable : public StoreItem{
private:
	char* name;
	char* sort;
public:
	Vegetable();
	Vegetable(int, double, char*, char*);
	Vegetable(int, double, const char*, const char*);
	Vegetable(const Vegetable&);
	Vegetable(Vegetable&&) noexcept;
	Vegetable& operator=(const Vegetable&);
	Vegetable& operator=(Vegetable&&) noexcept;
	~Vegetable();
	void copy(const Vegetable&);
	void free();

	void setName(char*);
	void setSort(char*);
	void setName(const char*);
	void setSort(const char*);

	char* getName() const;
	char* getSort() const;

	virtual void print() const override;
	bool operator==(const Vegetable&) const;
};

