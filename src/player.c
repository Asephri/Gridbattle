/*
Copyright (C) 2023-2024 Asephri. All rights reserved.
*/

#include "common.h"
#include "draw.h"
#include "player.h"
#include "input.h"
#include "util.h"

extern App app;
extern Entity *player;
extern Entity *playertank;
extern Stage stage;

void initPlayer(void)
{

    printf("Intialising the player.\n");

    playertank = malloc(sizeof(Entity));
    memset(playertank, 0, sizeof(Entity));

    stage.entityTail->next = playertank;
    stage.entityTail = playertank;


    player = malloc(sizeof(Entity));
    memset(player, 0, sizeof(Entity));

    stage.entityTail->next = player;
    stage.entityTail = player;
    

    playertank->texture = loadTexture("gfx/tank.png");
    player->texture = loadTexture("gfx/playerturret.png");
    player->health = 5;

    playertank->x = SCREEN_WIDTH / 2;
    playertank->y = SCREEN_HEIGHT / 2;
    player->x = playertank->x;
    player->y = playertank->y;


    SDL_QueryTexture(player->texture, NULL, NULL, &player->w, &player->h);
    SDL_QueryTexture(playertank->texture, NULL, NULL, &playertank->w, &playertank->h);

    printf("Successful.\n");
}

void doPlayer(void)
{
    playertank->dx *= 0.86;
    playertank->dy *= 0.86;

    if (app.keyboard[SDL_SCANCODE_W])
    {   
        double angle_rad = playertank->angle * PI / 180;
        playertank->dx = PLAYER_SPEED * cos(angle_rad);
        playertank->dy = PLAYER_SPEED * sin(angle_rad);
    }

    if (app.keyboard[SDL_SCANCODE_S])
    {
        double angle_rad = playertank->angle * PI / 180;
        playertank->dx = -PLAYER_SPEED * cos(angle_rad) / 4;
        playertank->dy = -PLAYER_SPEED * sin(angle_rad) / 4;
    }

    if (app.keyboard[SDL_SCANCODE_A])
    {   
        playertank->angle = playertank->angle - ROTATION_ANGLE_SPEED;
    }
    else if (app.keyboard[SDL_SCANCODE_D])
    {
        playertank->angle = playertank->angle + ROTATION_ANGLE_SPEED;
    }

    playertank->x += playertank->dx;
    playertank->y += playertank->dy;

    player->x = playertank->x + (playertank->w - player->w) / 2.0;
    player->y = playertank->y + (playertank->h - player->h) / 2.0;

    // Have the turret track the player's mouse.
    player->angle = getAngle(player->x, player->y, app.mouse.x, app.mouse.y);
}
