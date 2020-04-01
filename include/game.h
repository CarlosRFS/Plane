#ifndef GAME_H
#define GAME_H

//PROJECT HEADERS
#include "campo.h"
#include "aviao.h"
#include "score.h"
#include "menu.h"

//STD HEADERS
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
	Aviao player{c, tiros_vector};
	//Aviao inimigo{c, player};
	Score s{c};
    
    std::vector<Aviao> enemy_vector;
    std::vector<Tiro> tiros_vector;
    
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
		Aviao a1{c, player, pos, s, tiros_vector};
        enemy_vector.push_back(a1);
	}

	void run() {
		c.swap_buffers();
		for(;;) {
			input();
		}
	}
	
	
	//MOVE DRAW AND DESTROY CONTROL 
	void aviao_control(std::vector<Aviao> &avioes) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
        if(!avioes.empty()) {
            //loop para atualizar a posição dos tiros
            for(int i = 0; i < avioes.size(); i++) {
                bool a = avioes[i].disparo();
                if(!a) enemy_vector.erase(enemy_vector.begin() + i);
            }
    
            enemy_draw(avioes);
            player.draw_on_campo(); //Desenhar o player de volta no buffer
            c.swap_buffers();
            
        }
    }
    
    void enemy_draw(std::vector<Aviao> &avioes) {
        if(!avioes.empty()) {
            for(int i = 0; i < avioes.size(); i++)
                avioes[i].draw_on_campo();
        }
        
    }
    
    void tiros_control(std::vector<Tiro> &tiros) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
        if(!tiros.empty()) {
            //loop para atualizar a posição dos tiros
            for(int i = 0; i < tiros.size(); i++) {
                bool a = tiros[i].disparo();
                if(!a) tiros_vector.erase(tiros_vector.begin() + i);
            }
    
            for(int i = 0; i < tiros.size(); i++) {
                tiros[i].draw_on_campo();
            }
            enemy_draw(enemy_vector);
            player.draw_on_campo();
            c.swap_buffers();
        }
    
    }
};
#endif
