/*
Copyright (C) 2023-2024 Asephri. All rights reserved.
*/

#include "common.h"
#include "draw.h"
#include "entities.h"

extern Entity *player;
extern Entity *playertank;
extern Stage stage;

void doEntities(void)
{
    Entity *e;

    for (e = stage.entityHead.next; e != NULL; e = e->next)
    {
        e->x += e->dx;
        e->y += e->dy;

        
        if (e == playertank) 
        {
            playertank->x = MIN(MAX(playertank->x, e->w/2), SCREEN_WIDTH - e->w/2);
            playertank->y = MIN(MAX(playertank->y, e->h/2), SCREEN_HEIGHT - e->h/2);
        }   
    }
}

void drawEntities(void)
{
    Entity *e;

    for (e = stage.entityHead.next; e != NULL; e = e->next)
    {
        blitRotated(e->texture, e->x, e->y, e->angle);
    }
}
