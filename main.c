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

void initInvader() {
    FILE **file = fopen("invader.txt", "r");

    Unit invader;
    fscanf(file, "%i%i", &invader.sizeY, &invader.sizeX);

    invader.texture = (char **) malloc(invader.sizeY * sizeof(char *));

    for (int i = 0; i < invader.sizeY; i++) {
        invader.texture[i] = (char *) malloc(invader.sizeX);

    }

    for (int i = 0; i < invader.sizeY; i++) {
        fscanf(file, "%s", invader.texture[i]);
    }
    fclose("invader.txt");
}

void initPlayer(){
    FILE **file = fopen("player.txt", "r");

    Unit player;
    fscanf(file, "%i%i", &player.sizeY, &player.sizeX);

    player.texture = (char**)malloc(player.sizeY * sizeof(char*));

    for (int i = 0; i < player.sizeY; i++) {
        player.texture[i] = (char*) malloc(player.sizeX);

    }

    for (int i = 0; i < player.sizeY; i++) {
        fscanf(file, "%s", player.texture[i]);
    }
    fclose("player.txt");
}

//TODO: invaders cnt, make invaders mas


int main() {
    Game a;
    while (1) {
        draw_playground(a.screen);
        system("cls");
        print_frame(&a);
    }
}