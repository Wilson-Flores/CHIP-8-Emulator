#ifndef Platform_hpp
#define Platform_hpp


#include <cstdint>
#include <SDL.h>
#include <GL/gl.h> // dir: '/usr/include/GL/'


class Platform
{
public:
    Platform(char const* title, int windowWidth, int windowHeight, int textureWidth, int textureHeight);
    ~Platform();

    // void const*: a pointer to a constant memory block of unspecified type
    void update(void const* buffer, int pitch);
    bool ProcessInput(uint8_t* keys);

private:

    // SDL_Window: graphical window or screen where the program can render its graphics 
    // its a pointer, allowing the program to interact with and manippulate the window
    SDL_Window* window{};

    // SDL_GLContext: type used to represent an OpenGL rendering context within SDL.
    // encapsulates the necessary information and state for rendering OpenGL graphics in an SDL window
    SDL_GLContext gl_context{};

    // GLuint: unsigned int type used to represent an OpenGL object identifier or handle.
    // used to refer to various OpenGl objects such as textures, buffers, shaders, or framebuffers.
    GLuint framebuffer_texture;

    // SDL_Renderer: used for 2D rendering operations, such as drawing shapres, images, and text, onto an 'SDL_Window'
    // it is a pointer, allows interatcion with and manipulation of the renderer.
    SDL_Renderer* renderer{};

    // SDL_Texture: an image or pixel data that can be rendered onto an 'SDL_Renderer'
    // provides a way to efficiently store and render graphical content 
    SDL_Texture* texture{};
};



#endif