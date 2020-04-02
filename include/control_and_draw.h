#ifndef CONTROL_AND_DRAW_H
#define CONTROL_AND_DRAW_H

#include <mutex>
#include "game.h"
#include "aviao.h"
//MOVE DRAW AND DESTROY CONTROL 

void enemy_draw(std::vector<Aviao> &avioes);

void tiro_draw(std::vector<Tiro> &tiros);

void aviao_control(std::vector<Aviao> &avioes, Aviao &player, Campo &c);
    
void tiros_control(std::vector<Tiro> &tiros, std::vector<Aviao> &enemy_vector, Aviao &player, Campo &c);
    

#endif
