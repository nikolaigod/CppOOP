#ifndef FIRST_HOUSE_H
#define FIRST_HOUSE_H
#include "Building.h"

class House : public Building{
private:
    int floors;
    char* owner;
public:
    House();
    House(int, double, char*, int, char*);
    House(const House&);
    House(House&&) noexcept;
    House& operator=(const House&);
    ~House();
    friend std::istream& operator>>(std::istream& is, House&);
    friend std::ostream& operator<<(std::ostream& os, const House&);
};


#endif //FIRST_HOUSE_H
