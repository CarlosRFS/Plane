#include "../include/menu.h"

int main() {
	Game jogo;
	Menu menu{jogo.c, 530, jogo};
	std::thread th3([&]() { jogo.enemy_control(menu.difficulty); });
	jogo.run();
	return 0;
}
