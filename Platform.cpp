#include "Platform.hpp"
#define GL_CLAMP_TO_EDGE 0x812F

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

    //gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);


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


Platform::~Platform(){

    // destroy the texture object
    SDL_DestroyTexture(texture);

    // destroy renderer object
    SDL_DestroyRenderer(renderer);

    // destroy window object
    SDL_DestroyWindow(window);

    // shut down the SDL library, cleans up SDL subsystem
    SDL_Quit();
}


void Platform::update(void const* buffer, int pitch){

    // updates the texture with the pixel data, upload pixel data to GPU texture memory
    SDL_UpdateTexture(texture, nullptr, buffer, pitch);

    // clears the rendering target
    SDL_RenderClear(renderer);

    // copies the entire 'texture' to the rendering target window associated wiht the 'renderer'
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);

    // updates the window/screen with the rendered content, swaps the front and back buffers
    SDL_RenderPresent(renderer);
}


bool Platform::ProcessInput(uint8_t* keys){
    bool quit = false;

    // a structure that represents an event that ouccured in the program
    SDL_Event event;

    // processing user input events and updating the 'keys' array 
    while(SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_QUIT:
	            quit = true;
	            break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym){
                    case SDLK_ESCAPE: quit = true; break;
					case SDLK_x: keys[0] = 1; break;
					case SDLK_1: keys[1] = 1; break;
					case SDLK_2: keys[2] = 1; break;
					case SDLK_3: keys[3] = 1; break;
					case SDLK_q: keys[4] = 1; break;
					case SDLK_w: keys[5] = 1; break;
					case SDLK_e: keys[6] = 1; break;
					case SDLK_a: keys[7] = 1; break;
					case SDLK_s: keys[8] = 1; break;
					case SDLK_d: keys[9] = 1; break;
					case SDLK_z: keys[0xA] = 1; break;
					case SDLK_c: keys[0xB] = 1; break;
					case SDLK_4: keys[0xC] = 1; break;
					case SDLK_r: keys[0xD] = 1; break;
					case SDLK_f: keys[0xE] = 1; break;
					case SDLK_v: keys[0xF] = 1; break;
                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym){
 					case SDLK_x: keys[0] = 0; break;
					case SDLK_1: keys[1] = 0; break;
					case SDLK_2: keys[2] = 0; break;
					case SDLK_3: keys[3] = 0; break;
					case SDLK_q: keys[4] = 0; break;
					case SDLK_w: keys[5] = 0; break;
					case SDLK_e: keys[6] = 0; break;
					case SDLK_a: keys[7] = 0; break;
					case SDLK_s: keys[8] = 0; break;
					case SDLK_d: keys[9] = 0; break;
					case SDLK_z: keys[0xA] = 0; break;
					case SDLK_c: keys[0xB] = 0; break;
					case SDLK_4: keys[0xC] = 0; break;
					case SDLK_r: keys[0xD] = 0; break;
					case SDLK_f: keys[0xE] = 0; break;
					case SDLK_v: keys[0xF] = 0; break;                   
                }
                break;
        }
    }
    return quit;
}


