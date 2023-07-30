/*
Copyright (C) 2023-2024 Asephri. All rights reserved.
*/

/* Headers. */
#include "common.h"
#include "draw.h"
#include "stage.h"

extern App app;

static void logic(void);
static void draw(void);

static SDL_Texture *mousetargetTexture;

void initStage(void)
{
	app.delegate.logic = logic;
	app.delegate.draw = draw;

	mousetargetTexture = loadTexture("gfx/mousetarget.png");
}

static void logic(void)
{
}

static void draw(void)
{
	blit(mousetargetTexture, app.mouse.x, app.mouse.y, 1);
}
