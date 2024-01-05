# Evolving Dungeon

"Evolving Dungeon" is a simple dungeon crawler game created using C++ and SFML.

## Table of Contents

- [Project Implementation](#project-implementation)
- [Implemented Features](#implemented-features)
- [Working Practices](#working-practices)
- [Testing](#testing)
- [Source Code Documentation](#layout)
- [Credits](#credits)

## Project Implementation

The project uses github submodules to get the required SFML libraries, as it does for the googletest when performing tests.

If you are using Linux, make sure you have the [following](https://www.sfml-dev.org/tutorials/2.6/compile-with-cmake.php) installed for cmake to work correctly. One way of compiling the project with CMake when using Linux is to use the following commands:

1. git clone --recurse-submodules https://github.com/juhalo/evolving-dungeon.git
2. cd evolving-dungeon
3. cmake -S ./ -B ./build
4. cmake --build build
5. ./build/bin/EvolvingDungeon

You may also clone it normally and then run the command "git submodule init" followed by the command "git submodule update" instead of the --recurse-submodules tag.

## Implemented Features

## Working Practices

Will probably use feature branches and merge these to dev branch. Only when everything is working, it is merged to main branch. The coding style guide followed is the [SFML Code Style Guide](https://www.sfml-dev.org/style.php) to make it consistent with the major library used throughout the project. The project might also use WebKit style guide or Google C++ style guide etc. to fill in some blanks. These will (most likely) be documented here in the future.

Github Projects is used together with issues for organizing different parts that are planned to be completed.

## Testing

Uses googletest for the automatic tests for individual components/classes as well as interactions between different classes. Manual tests are also used to check that the game works properly. The testing is created together with the classes and changed if the classes change. In the main branch, all of the tests should pass at all times but this might not be the case for feature branches.

Testing can be found under tests/ folder and it has a readme.md that goes into much more detail about how the testing was done. To run the tests, clone the repository (as shown above, since you need the git submodules), follow the steps from [Project Implementation](#project-implementation), and then:

Go to tests/ and then type the following:

1. cmake -S . -B build
2. cmake --build build
3. cd build
4. ctest --rerun-failed --output-on-failure

## Source Code Documentation

Doxygen was used for documentation and creation of the pdf. The generated pdf file can be found under the doc/ folder.

## Credits
