#include "Platform.hpp"

Platform::Platform(char const* title, int windowWidth, int windowHeight, int textureWidth, int textureHeight){

    // initializes the SDL video
    SDL_Init(SDL_INIT_VIDEO);

    // set the attributes for the OpenGl context
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // specify what version of OpenGL to use
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3); // OpenGL ver 3.x
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3); // OpenGL ver 3.3

    // create SDL window
    // flags: open with OpenGL and be resizable 
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    // create OpenGL rendering context
    gl_context = SDL_GL_CreateContext(window);

    // set swap interval to enable VSync
    SDL_GL_SetSwapInterval(1);


    // generate new texture object and assigns it to the variable, '1' generate one texture object
    glGenTextures(1, &framebuffer_texture);

    // bind the texture object specified by 'framebuffer_texture' to the OpenGL target
    glBindTexture(GL_TEXTURE_2D, framebuffer_texture);

    // when texture needs to be displayed at a smaller size than original, the nearest pixel will be used for sampling.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // when texture needs to be displayed at a larger size than original, the nearest pixel will be used for sampling.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // set texture's wrapping mode to S (horizontal), if texture exceeds range of [0,1], texture will clamp to edge of the texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);

    // set texture's wrapping mode to T (vertical), if texture exceeds range of [0,1], texture will clamp to edge of the texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // set texture image of the bound texture object at level '0' with a specified format, width, height, border, and data type, 
    // null indicates no initial image data is provided.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 640, 320, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	
    // unbinds the currently bound texture. ID 0 represents the default texture
    glBindTexture(GL_TEXTURE_2D, 0);
}