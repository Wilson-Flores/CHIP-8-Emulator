#ifndef Platform_hpp
#define Platform_hpp

#include <SDL.h>


class Platform
{
public:
    Platform(char const* title, int windowWidth, int windowHeight);
    ~Platform();

    // void const*: a pointer to a constant memory block of unspecified type
    void update(void const* buffer);
    bool ProcessInput(uint8_t* keys);

private:

    // SDL_Window: graphical window or screen where the program can render its graphics 
    // its a pointer, allowing the program to interact with and manippulate the window
    SDL_Window* window{};

    // SDL_Renderer: used for 2D rendering operations, such as drawing shapres, images, and text, onto an 'SDL_Window'
    // it is a pointer, allows interatcion with and manipulation of the renderer.
    SDL_Renderer* renderer{};

    // SDL_Texture: an image or pixel data that can be rendered onto an 'SDL_Renderer'
    // provides a way to efficiently store and render graphical content 
    SDL_Texture* texture{};
};

#endif