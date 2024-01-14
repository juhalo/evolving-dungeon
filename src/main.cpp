#include "system/Game.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
    try {
        ED::System::Game game = ED::System::Game();
        game.run();
    } catch (std::exception& exception) {
        std::cout << "\nEXCEPTION: " << exception.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
