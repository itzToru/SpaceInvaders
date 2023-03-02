//
// Created by shafa on 27.02.2023.
//

#include "game.h"

void print_frame(Game *game) {
    for (int i = 0; i < SIZE_Y; i++) {
        for (int j = 0; j < SIZE_X; j++) {
            printf("%c", game->screen[i][j]);
        }
        printf("\n");
    }
}

void draw_playground(char screen[SIZE_Y][SIZE_X]) {
    for (int i = 0; i < SIZE_Y; i++) {
        for (int j = 0; j < SIZE_X; j++) {
            screen[i][j] = ((i == 0) || (i == SIZE_Y - 1)) || ((j == 0) || (j == SIZE_X - 1)) ? '#' : ' ';
        }
    }
}

Unit initInvader() {
    FILE *file = fopen("invader.txt", "r");

    Unit invader;
    fscanf(file, "%i%i", &invader.sizeY, &invader.sizeX);

    invader.texture = (char **) malloc(invader.sizeY * sizeof(char *));

    for (int i = 0; i < invader.sizeY; i++) {
        invader.texture[i] = (char *) malloc(invader.sizeX);
        fscanf(file, "%s", invader.texture[i]);
    }

    fclose(file);
}

Unit initPlayer() {
    FILE *file = fopen("player.txt", "r");

    Unit player;
    fscanf(file, "%i%i", &player.sizeY, &player.sizeX);

    player.texture = (char **) malloc(player.sizeY * sizeof(char *));

    for (int i = 0; i < player.sizeY; i++) {
        player.texture[i] = (char *) malloc(player.sizeX);
        fscanf(file, "%s", player.texture[i]);
    }

    fclose(file);
}

void draw(Unit unit, Game game){
    for(int i = 0; i < unit.sizeY; i++){
        for(int j = 0; j < unit.sizeX; j++){
            game.screen[unit.y + i][unit.x + j] = unit.texture[i][j];
        }
    }
}
