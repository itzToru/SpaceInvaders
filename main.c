#include "game.h"

int main() {
    Game a;
    while (1) {
        draw_playground(a.screen);
        system("cls");
        print_frame(&a);
    }
}

//TODO: Сделать функцию отрисовки объектов