#include "menu.h"

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
    
    std::thread th2([&]() {
            for(;;) {
                tiros_control(jogo.tiros_vector, jogo.enemy_vector, jogo.player, jogo.c, jogo.s);
            }
    });
    
    std::thread th1([&]() {
            for(;;) {
                aviao_control(jogo.enemy_vector, jogo.player, jogo.c, jogo.s);
            }
    });
    
    std::thread th4([&]() {
            jogo.run();
    });
    
    th4.join();
    th3.join();
    th2.join();
    th1.join();

	return 0;
}
