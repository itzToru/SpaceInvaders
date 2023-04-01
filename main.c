#include "game.h"
#include <Windows.h>

int main() {
    Game game;
    Unit* invaders = malloc(3 * sizeof (Unit));
    Unit* bullet = malloc(sizeof(Unit));

    Unit player;
    initPlayer(&player);

    for(int i = 0; i < 4; i++){
        initInvader(invaders + i);
    }

    invaders[0].y = 10;
    invaders[0].x = 10;

    invaders[1].y = 10;
    invaders[1].x = 30;

    invaders[2].y = 10;
    invaders[2].x = 50;

    invaders[3].y = 10;
    invaders[3].x = 70;

    int vector = 1;

    while(1) {
        draw_playground(game.screen);

        for(int i = 0; i < 4; i++){
            draw(invaders[i], &game);
        }
        for (int i = 0; i < 4; ++i) {
            if(invaders[3].x < SIZE_X - invaders[i].sizeX - 2 && invaders[0].x > 1)
                if(vector == 1)
                    moveRight(&invaders[i]);
                else
                    moveLeft(&invaders[i]);
            else {
                for (int j = 0; j < 4; ++j) {
                    moveDown(&invaders[j]);
                }
                if(vector) {
                    vector = 0;
                    for(int j = 0; j < 4; j++)
                        moveLeft(&invaders[j]);
                }
                else {
                    vector = 1;
                    for(int j = 0; j < 4; j++)
                        moveRight(&invaders[j]);
                }
//                invaders[0].y = invadersY;
//                invaders[0].x = 10;
//
//                invaders[1].y = invadersY;
//                invaders[1].x = 30;
//
//                invaders[2].y = invadersY;
//                invaders[2].x = 50;
            }
        }
        print_frame(&game);
        Sleep(100);
        //for(int i = 0; i < SIZE_Y + 1; i++) puts("");
        //Sleep(10);
        system("cls");
    }
}

