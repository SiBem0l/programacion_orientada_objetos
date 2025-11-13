#ifndef HELLO_WORLD_HPP
#define HELLO_WORLD_HPP

#include <iostream>
#include "MenuItem.hpp"

class HelloWorld : public MenuItem
{
public:
    std::string name() const override
    {
        return "Hello World";
    }
    void execute() override
    {
        for(int i = 0; i < 100; i++)
        {
            std::cout << name();
        }
        std::cout << std::endl;
    }
};

#endif