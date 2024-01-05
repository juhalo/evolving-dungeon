cmake_minimum_required(VERSION 3.16)
project(EvolvingDungeon LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Add all .cpp, - files under src/ directory
file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
# target_include_directories((${PROJECT_NAME} PRIVATE include))

add_subdirectory(libs/SFML)
# set(SFML_DIR "libs/SFML/")
# find_package(SFML 2.6 COMPONENTS audio graphics window system network REQUIRED)
# target_include_directories(${PROJECT_NAME} PRIVATE libs/SFML/include)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-graphics sfml-window sfml-audio sfml-network sfml-system)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET  ${PROJECT_NAME}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        VERBATIM)
endif()

install(TARGETS ${PROJECT_NAME})
