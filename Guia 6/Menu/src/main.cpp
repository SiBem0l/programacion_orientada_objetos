#include <iostream>

#include "Menu.hpp"
#include "HelloWorld.hpp"

using namespace std;

int main()
{
    Menu menu;
    menu.addOption(new HelloWorld);
    menu.run();
    
    return 0;
}
