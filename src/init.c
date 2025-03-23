/*
Copyright (C) 2023-2024 Asephri. All rights reserved.
*/

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "common.h"
#include "init.h"

extern App app;

void initSDL(void)
{
    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED;

    windowFlags = 0;


    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Couldn't initialise SDL: %s\n", SDL_GetError());
        exit(1);
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
    {
        printf("Couldn't initialise SDL Mixer.\n");
        exit(1);
    }

    Mix_AllocateChannels(MAX_SND_CHANNELS);
    
    app.window = SDL_CreateWindow(APP_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    SDL_ShowCursor(0);
}

void initGame(void)
{
}

void cleanup(void)
{
    printf("Quitting Audio mixer.\n");
    Mix_Quit();
    printf("Quitting SDL_Image.\n");
    IMG_Quit();
    printf("Destroying the app renderer.\n");
    SDL_DestroyRenderer(app.renderer);
    printf("Destroying the app window\n");
    SDL_DestroyWindow(app.window);
    printf("Quitting the application.\n");
    SDL_Quit();
    printf("Successful.\n");
}
