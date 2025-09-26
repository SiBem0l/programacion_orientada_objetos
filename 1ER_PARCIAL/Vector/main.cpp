#include <iostream>
#include "Vector.hpp"

int main()
{ 
    Vector v(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    std::cout << "Print vector: " << std::endl << v << std::endl;
    return 0;
}
