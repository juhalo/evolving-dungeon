#include "Textures.hpp"
#include "system/Menu.hpp"
#include <iostream>

int main()
{
    bool loadedCorrectly = ED::Texture::loadTextures();
    if (!loadedCorrectly) {
        std::cerr << "Error: Failed to load textures" << std::endl;
        return EXIT_FAILURE;
    }
    ED::System::Menu menu = ED::System::Menu();

    while (menu.isRunning()) {
        menu.menuLoop();
    }

    return EXIT_SUCCESS;
}
