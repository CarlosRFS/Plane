#include "../include/menu.h"

int main() {
	Game jogo;
	Menu menu{jogo.c, 530, jogo};
	jogo.run();
	return 0;
}
