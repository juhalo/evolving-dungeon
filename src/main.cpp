#include "Textures.hpp"
#include "system/Menu.hpp"
#include <iostream>

int main()
{
    bool loadedCorrectly = ed::Textures::loadTextures();
    std::cout << "Loading: " << loadedCorrectly << std::endl;
    ed::System::Menu menu = ed::System::Menu();

    while (menu.isRunning()) {
        menu.menuLoop();
    }

    return 0;
}
