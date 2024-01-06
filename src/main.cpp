#include "Textures.hpp"
#include "system/Menu.hpp"
#include <iostream>

int main()
{
    bool loadedCorrectly = ed::Textures::loadTextures();
    std::cout << "Loading: " << loadedCorrectly << std::endl;
    Menu menu = Menu();

    while (menu.isRunning()) {
        menu.menuLoop();
    }

    return 0;
}
