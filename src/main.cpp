#include "system/Menu.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
    try {
        ED::System::Menu menu = ED::System::Menu();
        menu.menuLoop();
    } catch (std::exception& exception) {
        std::cout << "\nEXCEPTION: " << exception.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
