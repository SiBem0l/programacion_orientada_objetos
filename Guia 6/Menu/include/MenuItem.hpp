#ifndef MENU_MENUITEM_HPP
#define MENU_MENUITEM_HPP

#include <string>

class MenuItem {
public:
    virtual ~MenuItem() = default;

    virtual std::string name() const = 0;
    // virtual const std::string& name() const = 0;
    virtual void execute() = 0;
};

#endif 