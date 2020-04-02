#include "input.h"

void enter_off() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);	
}

void input(Aviao &player, Campo &c) {
    char comando;
    enter_off();
    comando = std::cin.get();
    switch(comando) {
        case 'a':
            player.move_e();
            c.swap_buffers();
            break;
        case 'd':
            player.move_d();
            c.swap_buffers();
            break;
        case 't':
            player.atirar();
    }
}
