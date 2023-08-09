cmake_minimum_required (VERSION 3.8)

project ("CHIP-8-Emulator")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Find SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL_INCLUDE_DIRS})


add_executable(Chip8 "main.cpp" "Chip8.cpp" "Platform.cpp")


# Link SDL2 and OpenGL libraries
target_link_libraries(Chip8 ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})

