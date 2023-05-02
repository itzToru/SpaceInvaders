#include "game.h"
#include <time.h>
#include <Windows.h>

int main() {
    Game game;
    Unit *invaders = malloc(15 * sizeof(Unit));
    Unit *bullet = malloc(sizeof(Unit));

    int bulletsNum = 1;

    int posX, posY;
    char key;

    Unit player;
    initPlayer(&player);

    bullet->sizeX = 1;
    bullet->sizeY = 2;

    initBullet(bullet);

    player.x = SIZE_X / 2;
    player.y = SIZE_Y - 8;

    bullet->x = player.x + 7;
    bullet->y = player.y - 5;

    for (int i = 0; i < 15; i++) {
        initInvader(invaders + i);
    }

    invaders[0].y = 10;
    invaders[0].x = 10;

    for (int i = 1; i < 15; i++) {
        invaders[i].x = invaders[i - 1].x + 20;
        invaders[i].y = invaders[i - 1].y;
        printf("[%d]Invader X: %d, Y: %d\n", i, invaders[i].x, invaders[i].y);
        if (i % 5 == 0) {
            invaders[i].y = invaders[i - 1].y + 10;
            invaders[i].x = invaders[0].x;
        }
    }


    int vector = 1;

    time_t start = time(NULL);

    while (1) {
        draw_playground(game.screen);

        key = get_key();

        if (key == 'a') {
            moveLeft(&player);
            moveLeft(&player);
            moveLeft(&player);
        } else if (key == 'd') {
            moveRight(&player);
            moveRight(&player);
            moveRight(&player);
        }
        if (difftime(time(NULL), start) >= 0.1) {
            bullet = (Unit *) realloc(bullet, sizeof(Unit) * (++bulletsNum));
            bullet[bulletsNum - 1] = bullet[bulletsNum - 2];
            bullet[bulletsNum - 1].x = player.x + 7;
            bullet[bulletsNum - 1].y = player.y - 5;
            start = time(NULL);
        }

        for (int n = 0; n < bulletsNum; n++) {
            if (bullet[n].y == 5) {
                swap(&bullet[bulletsNum - 1], &bullet[n]);
                bullet = (Unit *) realloc(bullet, sizeof(Unit) * (--bulletsNum));
                n--;
                continue;
            }
            moveUp(bullet + n);
        }

        for (int i = 0; i < 15; i++) {
            draw(invaders[i], &game);
        }

        for (int i = 0; i < 1; ++i) {
            if (invaders[4].x < SIZE_X - invaders[i].sizeX - 2 && invaders[0].x > 0)
                if (vector == 1)
                    for (int z = 0; z < 15; z++) {
                        moveRight(&invaders[z]);
                    }
                else
                    for (int z = 0; z < 15; z++) {
                        moveLeft(&invaders[z]);
                    }
            else {
                for (int j = 0; j < 15; ++j) {
                    moveDown(&invaders[j]);
                }
                if (vector) {
                    vector = 0;
                    for (int j = 0; j < 15; j++)
                        moveLeft(&invaders[j]);
                } else {
                    vector = 1;
                    for (int j = 0; j < 15; j++)
                        moveRight(&invaders[j]);
                }
            }
        }

        for (int i = 0; i < bulletsNum; i++) {
            draw(bullet[i], &game);
        }

        draw(player, &game);

        print_frame(&game);
        Sleep(100);
        fflush(stdin);
        //for(int i = 0; i < SIZE_Y + 1; i++) puts("");
        //Sleep(10)
        system("cls");
    }
}

