# Unit Tests

## Test Case/Suit: HelloTest

**Test suit description: Make sure that libraries and files get loaded correctly**

### Test: BasicAssertions

**Involved Classes: None**

**Involved Namespaces: None**

**Test File: DungeonGenericTests.cpp**

**Description: Make sure that googletest works**

**Results: All passed**

### Test: SFMLLoading

**Involved Classes: None**

**Involved Namespaces: sf**

**Test File: DungeonGenericTests.cpp**

**Description: Make sure that SFML loads correctly**

**Results: All passed**

### Test: StaticFileLoading

**Involved Classes: None**

**Involved Namespaces: sf, ED**

**Test File: DungeonCrawlerTests.cpp**

**Description: Make sure that evolved dungeon files work and textures/sounds get loaded**

**Results: All passed**

## Test Case/Suit: ButtonTest

**Test suit description: Test Button class**

### Test: BasicProperties

**Involved Classes: Button**

**Involved Namespaces: sf, ED, ED::System**

**Test File: DungeonGenericTests.cpp**

**Description: Check basic properties of Button class**

**Results: All passed**

# Valgrind

SFML causes some blocks to be either reachable or be lost (on my machine) even with the most minimal official SFML tutorial [code](https://www.sfml-dev.org/tutorials/2.6/start-linux.php). Note that in the current version of SFML "sf::VideoMode(200, 200)" has to be replaced by "sf::VideoMode(sf::Vector2u(200, 200))". [This](https://github.com/SFML/SFML/issues/1673) would suggest that the problem might be due to, and I quote "We don't know exactly what it is, either a leak in the OpenGL driver, or a false positive (memory deallocated at global exit, not seen by valgrind), but there's no known memory leak in SFML". Therefore, I will treat this amount of memory leakage as something that cannot be avoided.

The commands used for running valgrind were:

1. cd build/bin
2. valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./EvolvingDungeon
