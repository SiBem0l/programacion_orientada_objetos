#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <vector>
#include "MenuItem.hpp"

class Menu
{
private:
    std::vector<MenuItem*> options;
    bool exit = false; 

public:
    Menu();
    ~Menu();
    void printOptions() const;
    void run();
    void addOption(MenuItem*);

    void setExitFlag(bool value);
    bool getExitFlag() const;
};

#endif