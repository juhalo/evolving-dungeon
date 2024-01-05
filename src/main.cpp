#include "system/Menu.hpp"

int main()
{
    Menu menu = Menu();

    while (menu.isRunning()) {
        menu.menuLoop();
    }

    return 0;
}
