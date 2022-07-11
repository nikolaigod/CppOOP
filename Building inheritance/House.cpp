#include "House.h"

House::House(int height, double area, char* address, int floors, char* owner) : Building(height, area, address), floors{floors}{
    this->owner = new char[std::strlen(owner) + 1];
    std::strcpy(this->owner, owner);
}

House::House() : House(0, 0.0, "\0", 0, "\0"){}

House::House(const House& other) : Building(other), floors{other.floors}{
    owner = new char[std::strlen(other.owner) + 1];
    std::strcpy(owner, other.owner);
}

House::House(House&& other) noexcept : Building(other), floors{other.floors}, owner{other.owner}{
    other.owner = nullptr;
}

House& House::operator=(const House& other){
    if(this != &other){
        Building::operator=(other);
        delete[] owner;
        owner = new char[std::strlen(other.owner) + 1];
        std::strcpy(owner , other.owner);
        floors  = other.floors;
    }
    return *this;
}

House::~House(){
    delete[] owner;
}

std::ostream& operator<<(std::ostream& os, const House& other){
    os << "Height: " << other.height << " ";
    os << "Area: " << other.area << " ";
    os << "Address: " << other.address << " ";
    os << "Floors: " << other.floors << " ";
    os << "Owner: " << other.owner;
    return os;
}

std::istream& operator>>(std::istream& is, House& other){
    int heightBuff {0};
    double areaBuff {0.0};
    int floorsBuff {0};
    char* ownerBuff = new char[100];
    char* addressBuff = new char[100];
    std::cout << "Enter address" << std::endl;
    is.getline(addressBuff, 100);
    std::cout << "Enter owner" << std::endl;
    is.getline(ownerBuff, 100);
    std::cout << "Enter floors" << std::endl;
    is >> floorsBuff;
    std::cout << "Enter height" << std::endl;
    is >> heightBuff;
    std::cout << "Enter area" << std::endl;
    is >> areaBuff;
    other = House(heightBuff, areaBuff, addressBuff, floorsBuff, ownerBuff);
    delete[] ownerBuff;
    delete[] addressBuff;
    return is;
}
