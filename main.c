#include "game.h"

int main() {
    Game game;
    Unit* invaders = malloc(3 * sizeof (Unit));
    Unit* bullet = malloc(sizeof(Unit));

    Unit player = initPlayer();
    for(int i = 0; i < 3; i++){
        invaders[i] = initInvader();
    }

    invaders[0].y = 10;
    invaders[0].x = 10;

    invaders[1].y = 10;
    invaders[1].x = 30;

    invaders[2].y = 10;
    invaders[2].x = 50;

    draw_playground(game.screen);

    for(int i = 0; i < 3; i++){
        draw(invaders[i], game);
    }


}

