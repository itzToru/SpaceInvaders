#include "game.h"
#include <Windows.h>

int main() {
    Game game;
    Unit* invaders = malloc(3 * sizeof (Unit));
    Unit* bullet = malloc(sizeof(Unit));

    Unit player;
    initPlayer(&player);

    for(int i = 0; i < 3; i++){
        initInvader(invaders + i);
    }

    invaders[0].y = 10;
    invaders[0].x = 10;

    invaders[1].y = 10;
    invaders[1].x = 30;

    invaders[2].y = 10;
    invaders[2].x = 50;

    int invadersY = 10;

    while(1) {
        draw_playground(game.screen);

        for(int i = 0; i < 3; i++){
            draw(invaders[i], &game);
        }
        for (int i = 0; i < 3; ++i) {
            if(invaders[i].x < SIZE_X - invaders[i].sizeX - 2)
                moveRight(&invaders[i]);
            else {
                invadersY += 5;
                invaders[0].y = invadersY;
                invaders[0].x = 10;

                invaders[1].y = invadersY;
                invaders[1].x = 30;

                invaders[2].y = invadersY;
                invaders[2].x = 50;
            }
        }
        print_frame(&game);
        Sleep(100);
        //for(int i = 0; i < SIZE_Y + 1; i++) puts("");
        //Sleep(10);
        system("cls");
    }
}

