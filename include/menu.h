#ifndef MENU_H
#define MENU_H

//STD HEADERS
#include <array>
#include <string>

//PROJECT HEADERS
#include "campo.h"
#include "game.h"
#include "input.h"

struct Menu {
	int difficulty = 1;
	int pos;
	bool on = true;
	
	Campo * c;
	
	std::array<std::string, 3> lv_menu = { "Facil", "Medio", "Dificil" };

	Menu(Campo &c1, int pos1, Game jogo);

	void draw_on_campo();

	void erase();

	void input(Game &g);
    
	void ajuste();
};
#endif
