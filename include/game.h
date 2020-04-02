#ifndef GAME_H
#define GAME_H


//STD HEADERS

#include <unistd.h>
#include <array>
#include <random>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <thread>

//PROJECT HEADERS
#include "campo.h"
#include "aviao.h"
#include "score.h"
#include "input.h"
#include "control_and_draw.h"


struct Game {
	char caracter = 26;


	Campo c{caracter, 30, 50};
	Aviao player{c, tiros_vector, enemy_vector};
	Score s{c};
    
    std::vector<Aviao> enemy_vector;
    std::vector<Tiro> tiros_vector;
 
    
	
	void enemy_control(int h);

	void create_enemy(int &pos);
    
	void run();	
};

#endif
