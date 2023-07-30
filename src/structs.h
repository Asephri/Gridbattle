/*
Copyright (C) 2023-2024 Asephri. All rights reserved.
*/

/* Type definitions for structures. */
typedef struct Texture Texture;

/* App delegation structure.*/
typedef struct
{
    void (*logic)(void);
    void (*draw)(void);
} Delegate;

/* Texture structure. */
struct Texture
{
    char name[MAX_KEYBOARD_KEYS];
    SDL_Texture *texture;
    Texture *next;
};

/* Mouse Reader structure.*/
typedef struct
{
    int x;
    int y;
} Mouse;

/* App structure. */
typedef struct 
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    Delegate delegate; // App delegation.
    int keyboard[MAX_KEYBOARD_KEYS];
    Mouse mouse; // Reading the mouse.
    Texture textureHead, *textureTail;
} App;
