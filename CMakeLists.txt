cmake_minimum_required (VERSION 3.8)

project ("CHIP-8-Emulator")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the OpenGL preference to GLVND
#cmake_policy(SET CMP0072 NEW)
#set(OpenGL_GL_PREFERENCE "GLVND")

# Find SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL_INCLUDE_DIRS})

# Find OpenGL library
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

add_executable(CHIP-8-Emulator "main.cpp" "Chip8.hpp" "Chip8.cpp" "Platform.hpp" "Platform.cpp")


if (CMAKE_VERSION VERSION_GREATER 3.12)
	set_property(TARGET CHIP-8-Emulator PROPERTY CXX_STANDARD 20)
endif()

# Link SDL2 and OpenGL libraries
target_link_libraries(CHIP-8-Emulator ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})

