#ifndef GAME_H
#define GAME_H


#include "campo.h"
#include "aviao.h"
#include "score.h"
#include "menu.h"
#include <termios.h>
#include <unistd.h>
#include <array>
#include <random>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <thread>


struct Game {
	char caracter = 26;
	char comando;

	Campo c{caracter, 30, 50};
	Aviao player{c};
	//Aviao inimigo{c, player};
	Score s{c};

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

	void enemy_control(int h) {
		int pos = 6; 
		std::array<bool, 9> inimigos = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		
		for(int i = 0; i < h; i++) inimigos[i] = true;
		
		//embaralhar o array
		std::random_device rd;
		std::mt19937 g(rd());

		std::shuffle(inimigos.begin(), inimigos.end(), g);
		

		//criando os inimigos
		int w = 0; //o loop continua ate ele bater o h que e numero de inimigos na tela
		for(int z = 0; z < 3; z++) {
			int g = pos;
			for(int y = 0; y < 3; y++) {
				if(inimigos[w]) create_enemy(g);
				g += 18;
				w++;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(4000));
		}


	}

	void create_enemy(int &pos) {
		Aviao * a1 = new Aviao(c, player, pos);
	}

	void run() {
		c.print();
		for(;;) {
			input();
		}
	}
};
#endif
