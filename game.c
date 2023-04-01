//
// Created by shafa on 27.02.2023.
//

#include <synchapi.h>
#include "game.h"

void print_frame(Game *game) {
    for (int i = 0; i < SIZE_Y; i++) {
        puts(game->screen[i]);
    }
}

void draw_playground(char screen[SIZE_Y][SIZE_X]) {
    for (int i = 0; i < SIZE_Y; i++) {
        for (int j = 0; j < SIZE_X - 1; j++) {
            screen[i][j] = ((i == 0) || (i == SIZE_Y - 1)) || ((j == 0) || (j == SIZE_X - 2)) ? '#' : ' ';
        }
        screen[i][SIZE_X - 1] = '\0';
    }
}

void initInvader(Unit* invader) {
    FILE *file = fopen("../invader.txt", "r");

    fscanf(file, "%i%i", &invader->sizeY, &invader->sizeX);

    invader->texture = (char **) malloc(invader->sizeY * sizeof(char *));

    for (int i = 0; i < invader->sizeY; i++) {
        invader->texture[i] = (char *) malloc(invader->sizeX);
        for (int j = 0; j < invader->sizeX; ++j) {
            fscanf(file, "%c", &invader->texture[i][j]);
            if(invader->texture[i][j] == '\n') j--;
            if(invader->texture[i][j] == '.') invader->texture[i][j] = ' ';
        }

    }

    fclose(file);
}

void initPlayer(Unit* player) {
    FILE *file = fopen("../player.txt", "r");

    fscanf(file, "%i%i", &player->sizeY, &player->sizeX);

    player->texture = (char **) malloc(player->sizeY * sizeof(char *));

    for (int i = 0; i < player->sizeY; i++) {
        player->texture[i] = (char *) malloc(player->sizeX);
        fscanf(file, "%s", player->texture[i]);
    }

    fclose(file);
}

void draw(Unit unit, Game* game){
    for(int i = 0; i < unit.sizeY; i++){
        for(int j = 0; j < unit.sizeX; j++){
            game->screen[unit.y + i][unit.x + j] = unit.texture[i][j];
        }
    }
}

bool isColide(Unit a, Unit b) {
    if ((a.y >= b.y || a.y <= (b.y + b.sizeY)) && (a.x >= b.x || a.x <= (b.x + b.sizeX))){
        return true;
    }
    return false;
}

void moveDown(Unit *unit) {
    unit->y++;
}

void moveUp(Unit *unit) {
    unit->y--;
}

void moveRight(Unit *unit) {
    unit->x++;
}

void moveLeft(Unit *unit) {
    unit->x--;
}
