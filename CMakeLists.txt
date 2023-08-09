cmake_minimum_required (VERSION 3.8)

project ("CHIP-8-Emulator")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Find SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL_INCLUDE_DIRS})

set(SOURCE_FILES "src/main.cpp" "src/Chip8.cpp" "src/Platform.cpp")
add_executable(chip8 ${SOURCE_FILES})


# Link SDL2 and OpenGL libraries
target_link_libraries(chip8 ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})

