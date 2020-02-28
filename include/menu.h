#ifndef MENU_H
#define MENU_H

#include <array>
#include <string>
#include "campo.h"
#include "game.h"

struct Menu {
	int difficulty = 1;
	int pos;
	bool on = true;
	
	Campo * c;
	
	std::array<std::string, 3> lv_menu = { "Facil", "Medio", "Dificil" };

	Menu(Campo &c1, int pos1, Game jogo) 
	: c(&c1), pos(pos1) {
		for(;;) {
			draw_on_campo();
			input(jogo);
			if(on == false) break;
		}
		ajuste();
		erase();
	}

	void draw_on_campo() {
		int w = pos;
		for(int i = 0; i < 3; i++) {
			if (difficulty == i) c->campo[w - 1] = 26; //marcador de seleçao
			for(int z = 0; z < lv_menu[i].size(); z++) {
				c->campo[w + z] = lv_menu[i][z];
			}
			w += c->width + 1;
		}
		c->print();
	}

	void erase() {
		int w = pos;
		for(int i = 0; i < 3; i++) {
			if (difficulty == i) c->campo[w - 1] = ' '; //marcador de seleçao
			for(int z = 0; z < lv_menu[i].size(); z++) {
				c->campo[w + z] = ' ';
			}
			w += c->width + 1;
		}
		c->print();
		
	}

	void input(Game &g) {
		g.enter_off();
		char entrada = std::cin.get();
		int w = pos + difficulty * (c->width + 1);
		switch(entrada) {
			case 'w':
				if(difficulty == 0) break;
				c->campo[w - 1] = ' ';
				difficulty--;
				draw_on_campo();
				break;
			case 's':
				if(difficulty == 2) break;
				c->campo[w - 1] = ' ';
				difficulty++;
				draw_on_campo();
				break;
			case 'f':
				on = false;
				break;
			default:
				break;
		}
	}

	void ajuste() {
		switch(difficulty) {
			case 0:
				difficulty = 3;
				break;

			case 1:
				difficulty = 5;
				break;
			
			case 2:
				difficulty = 7;
				break;
		}
	}
};
#endif
