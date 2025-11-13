#include "Menu.hpp"
#include "Exit.hpp"

Menu::Menu()
{
    addOption(new Exit(*this));
}

Menu::~Menu()
{
    for (auto option : options)
    {
        delete option;
    }
}

void Menu::printOptions() const
{
    using namespace std;
    cout << "Menu options:" << endl;
    int i = 0;
    for (auto option : options)
    {
        cout << "  " << i++ << ": "<< option->name() << endl;
    }
}

static void clearScreen()
{
    std::cout << std::endl
              << std::endl;
}
static int readOption()
{
    int option = 0;
    std::cout << "Option: ";
    std::cin >> option;
    return option;
}
void Menu::run()
{
    using namespace std;
    while(getExitFlag() == false)
    {
        clearScreen();
        cout << ">>" << endl;
        cout << ">>" << endl;
        printOptions();
        int i = readOption();
        options[i]->execute();
        cout << "<<" << std::endl;
        cout << "<<" << std::endl;
    }
}

void Menu::addOption(MenuItem *item)
{
    options.push_back(item);
}

void Menu::setExitFlag(bool value)
{
    exit = value;
}

bool Menu::getExitFlag() const
{
    return exit;
}
