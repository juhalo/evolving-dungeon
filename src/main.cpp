#include "Textures.hpp"
#include "system/Menu.hpp"
#include <iostream>

int main()
{
    bool loadedCorrectly = ED::Texture::loadTextures();
    std::cout << "Loading: " << loadedCorrectly << std::endl;
    ED::System::Menu menu = ED::System::Menu();

    while (menu.isRunning()) {
        menu.menuLoop();
    }

    return 0;
}
