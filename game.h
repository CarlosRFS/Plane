#include "campo.h"
#include "aviao.h"
#include <cstdio>


struct Game {
	char caracter = 26;
	char comando;
	Campo c{caracter, 30, 50};

	Aviao player{c, caracter};

	void input() {
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
		}
	}

	void run() {
		c.print();
		for(;;) {
			input();
		}
	}
};
