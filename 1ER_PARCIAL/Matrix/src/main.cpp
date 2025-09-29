#include <iostream>
#include "Matrix.hpp"

int main()
{
    Matrix m(3, 3);
    m(0,0) = 2; m(0,1) = 2; m(0,2) = 3;
    m(1,0) = 1; m(1,1) = 4; m(1,2) = 4;
    m(2,0) = 3; m(2,1) = 3; m(2,2) = 2;
    std::cout << "det: " << m.det() << "\n \n";
    std::cout << "adj:" << std::endl << m.adj() << std::endl;
    std::cout << "inv:" << std::endl << m.inv() << std::endl;
}
