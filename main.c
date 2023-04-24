#include "game.h"
#include <Windows.h>

int main() {
    Game game;
    Unit* invaders = malloc(15 * sizeof (Unit));
    Unit* bullet = malloc(sizeof(Unit));

    int bulletsNum;

    int posX, posY;
    char key;

    Unit player;
    initPlayer(&player);

    bullet->sizeX = 1;
    bullet->sizeY = 2;

    initBullet(&bullet);


    player.x = SIZE_X / 2;
    player.y = SIZE_Y - 8;

    for(int i = 0; i < 15; i++){
        initInvader(invaders + i);
    }

    invaders[0].y = 10;
    invaders[0].x = 10;

    for(int i = 1; i < 15; i++){
        invaders[i].x = invaders[i - 1].x + 20;
        invaders[i].y = invaders[i - 1].y;
        printf("[%d]Invader X: %d, Y: %d\n", i, invaders[i].x, invaders[i].y);
        if(i % 5 == 0)
        {
            invaders[i].y = invaders[i - 1].y + 10;
            invaders[i].x = invaders[0].x;
        }
    }


    int vector = 1;

    while(1) {
        draw_playground(game.screen);

        key = get_key();

        if (key == 'a'){
            moveLeft(&player);
            moveLeft(&player);
            moveLeft(&player);
        }
        else if (key == 'd'){
            moveRight(&player);
            moveRight(&player);
            moveRight(&player);
        }

        bullet = realloc(bullet, sizeof(Unit) * bulletsNum + 1);
        bulletsNum++;

        for(int n = 1; n < bulletsNum; n++){
            bullet[n] = bullet[n - 1];
        }

        for(int i = 0; i < 15; i++){
            draw(invaders[i], &game);
        }
        for (int i = 0; i < 1; ++i) {
            if(invaders[4].x < SIZE_X - invaders[i].sizeX - 2 && invaders[0].x > 0)
                if(vector == 1)
                    for(int z = 0; z < 15; z++){
                        moveRight(&invaders[z]);
                    }
                else
                    for(int z = 0; z < 15; z++){
                        moveLeft(&invaders[z]);
                    }
            else {
                for (int j = 0; j < 15; ++j) {
                    moveDown(&invaders[j]);
                }
                if(vector) {
                    vector = 0;
                    for(int j = 0; j < 15; j++)
                        moveLeft(&invaders[j]);
                }
                else {
                    vector = 1;
                    for(int j = 0; j < 15; j++)
                        moveRight(&invaders[j]);
                }
            }
        }

        draw(player, &game);

        print_frame(&game);
        Sleep(100);
        //for(int i = 0; i < SIZE_Y + 1; i++) puts("");
        //Sleep(10)
        system("cls");
    }
}

