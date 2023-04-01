//=
// Created by shafa on 27.02.2023.
//

#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FPS 5
#define SIZE_X 128
#define SIZE_Y 69

typedef struct unit {
    int x, y;
    signed char state;
    char **texture;
    int sizeX, sizeY;
} Unit;

typedef struct game {
    char screen[SIZE_Y][SIZE_X];
    unsigned scoreCounter;
} Game;

void print_frame(Game *);

void draw_playground(char screen[SIZE_Y][SIZE_X]);

void initInvader(Unit*);

void initPlayer(Unit*);

void moveLeft(Unit *);

void moveRight(Unit *);

void moveUp(Unit *);

void moveDown(Unit *);

void draw(Unit, Game*);

bool isColide(Unit, Unit);

#endif //SPACEINVADERS_GAME_H