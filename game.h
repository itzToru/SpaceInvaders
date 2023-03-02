//
// Created by shafa on 27.02.2023.
//

#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include <stdio.h>
#include <stdlib.h>

#define FPS 5
#define SIZE_X 256
#define SIZE_Y 256


typedef struct unit {
    int x, y;
    signed char state;
    char **texture;
    int sizeX, sizeY;
} Unit;

typedef struct game {
    char screen[SIZE_Y][SIZE_X];
    Unit player, *invader, *bullet;
    unsigned scoreCounter;
} Game;

void print_frame(Game *game);

void draw_playground(char screen[SIZE_Y][SIZE_X]);

Unit initInvader();

Unit initPlayer();

void draw(Unit unit);

#endif //SPACEINVADERS_GAME_H




