#include "Platform.hpp"


Platform::Platform(char const* title, int windowWidth, int windowHeight){

    // initializes the SDL video
    SDL_Init(SDL_INIT_EVERYTHING);

    // create SDL window
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_RenderSetLogicalSize(renderer, windowWidth, windowHeight);

    // Create texture that stores frame buffer
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, 64, 32);
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


void Platform::update(void const* buffer){

    // updates the texture with the pixel data, upload pixel data to GPU texture memory
    SDL_UpdateTexture(texture, nullptr, buffer, 64 * sizeof(Uint32));

    // clears the rendering target
    SDL_RenderClear(renderer);

    // copies the entire 'texture' to the rendering target window associated wiht the 'renderer'
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);

    // updates the window/screen with the rendered content, swaps the front and back buffers
    SDL_RenderPresent(renderer);
}


constexpr uint8_t keymap[16] = {
    SDLK_x,
    SDLK_1,
    SDLK_2,
    SDLK_3,
    SDLK_q,
    SDLK_w,
    SDLK_e,
    SDLK_a,
    SDLK_s,
    SDLK_d,
    SDLK_z,
    SDLK_c,
    SDLK_4,
    SDLK_r,
    SDLK_f,
    SDLK_v,
};


bool Platform::ProcessInput(uint8_t* keys){
    bool quit = false;

    // a structure that represents an event that ouccured in the program
    SDL_Event event;

    // processing user input events and updating the 'keys' array 
    while(SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT) {
            quit = true;
        }

        // process keydown events
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            }

            for (int i = 0; i < 16; i++) {
                if (event.key.keysym.sym == keymap[i]) {
                    keys[i] = 1;
                }
            }
        }

        // process keyup events
        if (event.type == SDL_KEYUP) {
            for (int i = 0; i < 16; i++) {
                if (event.key.keysym.sym == keymap[i]) {
                    keys[i] = 0;
                }
            }
        }
    }
    return quit;
}


