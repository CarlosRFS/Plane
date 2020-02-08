#include "campo.h"
#include "aviao.h"
#include <cstdio>
#include <termios.h>
#include <unistd.h>

struct Game {
	char caracter = 26;
	char comando;

	Campo c{caracter, 30, 50};
	Aviao player{c, caracter};

	struct termios t;

	void enter_off() {
		tcgetattr(STDIN_FILENO, &t);
		t.c_lflag &= ~ICANON;
		tcsetattr(STDIN_FILENO, TCSANOW, &t);	
	}

	void input() {
		enter_off();
		comando = getchar();
		switch(comando) {
			case 'a':
				player.move_e(c);
				c.print();
				break;
			case 'd':
				player.move_d(c);
				c.print();
				break;
			case 't':
				player.atirar(c);
		}
	}

	void run() {
		c.print();
		for(;;) {
			input();
		}
	}
};
