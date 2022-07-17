#include <iostream>
#include "Vector.h"
#include <string>

int main()
{
    Vector<std::string> vector;
    std::string one = "hello 1 ";
    std::string two = "hello 2 ";
    vector.push(one);
    vector.push(two);
    std::string three = "hello 3";
    vector[1] = three;
    vector.print();
}

