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

void init()
{

}

int main() {
    Game a;
    while (1) {
        draw_playground(a.screen);
        system("cls");
        print_frame(&a);
    }
}