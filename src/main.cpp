#include "../include/menu.h"

int main() {
	Game jogo;
	Menu menu{jogo.c, 530, jogo};
	std::thread th3([&]() { 
			for(;;) { 
				jogo.enemy_control(menu.difficulty);
				std::this_thread::sleep_for(std::chrono::milliseconds(10000));
			}
		}
	);
	jogo.run();
	return 0;
}
