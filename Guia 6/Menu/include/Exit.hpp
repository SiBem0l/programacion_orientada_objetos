#ifndef EXIT_HPP
#define EXIT_HPP

#include "MenuItem.hpp"
#include "Menu.hpp"

class Exit : public MenuItem
{
    Menu& menu;
public:
    Exit(Menu& menu) : menu(menu) {}
    std::string name() const override
    {
        return "Exit";
    }
    void execute() override
    {
        menu.setExitFlag(true);
    }
};

#endif