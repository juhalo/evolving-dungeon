cmake_minimum_required(VERSION 3.16)
project(EvolvingDungeonTests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# include_directories(../)

add_subdirectory(../libs/googletest ./libs/googletest)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

add_subdirectory(../libs/SFML ./libs/SFML)

# Add all .cpp, - files under src/ directory
file(GLOB SOURCES_CPP CONFIGURE_DEPENDS "../src/*.cpp" "src/system/*.cpp")
# Remove main.cpp since googletest already has this defined, all of these are added to make sure it stays away
list(REMOVE_ITEM SOURCES_CPP ${CMAKE_SOURCE_DIR}/../src/main.cpp)
list(REMOVE_ITEM SOURCES_CPP ${CMAKE_CURRENT_SOURCE_DIR}/../src/main.cpp)
list(REMOVE_ITEM SOURCES_CPP ../src/main.cpp)
list(REMOVE_ITEM SOURCES_CPP "../src/main.cpp")

# Add all .cpp, - files under tests/ directory
file(GLOB SOURCES_TEST CONFIGURE_DEPENDS "*.cpp")
set(SOURCES ${SOURCES_CPP} ${SOURCES_TEST})

add_executable(
  ${PROJECT_NAME}
  ${SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE "../include")

target_link_libraries(
  ${PROJECT_NAME}
  GTest::gtest_main
  sfml-graphics sfml-graphics sfml-window sfml-audio sfml-network sfml-system
)

# Add fonts
add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/../resources/fonts $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources/fonts)

install(TARGETS ${PROJECT_NAME})


include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
