#include "campo.h"
#include "aviao.h"
#include <termios.h>
#include <unistd.h>

struct Game {
	char caracter = 26;
	char comando;

	Campo c{caracter, 30, 50};
	Aviao player{c};
	Aviao inimigo{c, player};

	struct termios t;

	void enter_off() {
		tcgetattr(STDIN_FILENO, &t);
		t.c_lflag &= ~ICANON;
		tcsetattr(STDIN_FILENO, TCSANOW, &t);	
	}

	void input() {
		enter_off();
		comando = std::cin.get();
		switch(comando) {
			case 'a':
				player.move_e();
				c.print();
				break;
			case 'd':
				player.move_d();
				c.print();
				break;
			case 't':
				player.atirar();
		}
	}

	void run() {
		c.print();
		for(;;) {
			input();
		}
	}
};
