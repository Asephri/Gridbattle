/*
Copyright (C) 2023-2024 Asephri. All rights reserved.
*/

#include "common.h"
#include "input.h"

extern App app;

static void doKeyUp(SDL_KeyboardEvent *event)
{
	if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
	{
		app.keyboard[event->keysym.scancode] = 0;
	}
}

static void doKeyDown(SDL_KeyboardEvent *event)
{
	if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
	{
		app.keyboard[event->keysym.scancode] = 1;
	}
}

void doInput(void)
{
    //printf("Calling doInput.\n");
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                printf("SDL_QUIT has been called! Closing application.\n");
                exit(0);
                break;
            case SDL_KEYDOWN:
                //printf("Keydown was pressed!\n");
                doKeyDown(&event.key);
                break;
            case SDL_KEYUP:
                //printf("Keydown was released!\n");
                doKeyUp(&event.key);
                break;
            default:
                //printf("default break was called in SDL_PollEvent\n");
                break;
        }
    }
    SDL_GetMouseState(&app.mouse.x,&app.mouse.y);
}
