#include "Building.h"

Building::Building(int height, double area, char* address) : height{height}, area{area}{
    this->address = new char[std::strlen(address) + 1];
    std::strcpy(this->address, address);
}

Building::Building() : Building(0, 0.0, "\0"){}

Building::Building(const Building& other) : height{other.height}, area{other.area}{
    this->address = new char[std::strlen(other.address) + 1];
    std::strcpy(this->address, other.address);
}

Building::Building(Building&& other) noexcept : height{other.height}, area{other.area}, address{other.address}{
    other.address = nullptr;
}

Building& Building::operator=(const Building& other){
    if(this != &other){
        delete[] address;
        address = new char[std::strlen(other.address) + 1];
        std::strcpy(address, other.address);
        height = other.height;
        area = other.area;
    }
    return *this;
}

Building& Building::operator=(Building&& other) noexcept{
    if(this != &other){
        delete[] address;
        address = other.address;
        height = other.height;
        area = other.area;
        other.address = nullptr;
    }
    return *this;
}

Building::~Building(){
    delete[] address;
}

std::ostream& operator<<(std::ostream& os, const Building& other){
    os << "Height: " << other.height << " ";
    os << "Area: " << other.area << " ";
    os << "Address: " << other.address;
    return os;
}

std::istream& operator>>(std::istream& is, Building& other){
    int heightBuff {0};
    double areaBuff {0.0};
    char* addressBuff = new char[100];
    std::cout << "Enter address" << std::endl;
    is.getline(addressBuff, 100);
    std::cout << "Enter height" << std::endl;
    is >> heightBuff;
    std::cout << "Enter area" << std::endl;
    is >> areaBuff;
    other = Building(heightBuff, areaBuff, addressBuff);
    delete[] addressBuff;
    return is;
}

