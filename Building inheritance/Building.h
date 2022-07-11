#ifndef FIRST_BUILDING_H
#define FIRST_BUILDING_H
#include<iostream>
#include<cstring>

class Building {
protected:
    int height;
    double area;
    char* address;
public:
    Building();
    Building(int, double, char*);
    Building(const Building&);
    Building(Building&&) noexcept ;
    Building& operator=(const Building&);
    Building& operator=(Building&&) noexcept;
    ~Building();
    friend std::istream& operator>>(std::istream& is, Building&);
    friend std::ostream& operator<<(std::ostream& os, const Building&);
};


#endif //FIRST_BUILDING_H
