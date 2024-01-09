#include "system/Menu.hpp"

int main()
{
    ED::System::Menu menu = ED::System::Menu();

    while (menu.isRunning()) {
        menu.menuLoop();
    }

    return EXIT_SUCCESS;
}
