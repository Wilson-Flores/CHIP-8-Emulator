cmake_minimum_required (VERSION 3.8)

project ("CHIP-8-Emulator")

# Find SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(CHIP-8-Emulator "main.cpp" "Chip8.hpp" "Chip8.cpp" "Platform.hpp" "Platform.cpp")


if (CMAKE_VERSION VERSION_GREATER 3.12)
	set_property(TARGET CHIP-8-Emulator PROPERTY CXX_STANDARD 20)
endif()

# Link SDL2 library
target_link_libraries(CHIP-8-Emulator ${SDL2_LIBRARIES})
target_link_libraries(CHIP-8-Emulator GL)
