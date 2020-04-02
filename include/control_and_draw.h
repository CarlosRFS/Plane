#ifndef CONTROL_AND_DRAW_H
#define CONTROL_AND_DRAW_H

#include <mutex>
#include "game.h"
#include "aviao.h"
//MOVE DRAW AND DESTROY CONTROL 

void enemy_draw(std::vector<Aviao> &avioes) {
    if(!avioes.empty()) {
        for(int i = 0; i < avioes.size(); i++)
            avioes[i].draw_on_campo();
    }
        
}

void tiro_draw(std::vector<Tiro> &tiros) {
    if(!tiros.empty()) {
        for(int i = 0; i < tiros.size(); i++)
            tiros[i].draw_on_campo();
    } 
}

void aviao_control(std::vector<Aviao> &avioes, Aviao &player, Campo &c) {
    std::mutex trava;
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
    if(!avioes.empty()) {
        //loop para atualizar a posição dos tiros
        for(int i = 0; i < avioes.size(); i++) {
            bool a = avioes[i].disparo();
            std::cout << a << "\n";
            if(!a) avioes.erase(avioes.begin() + i);
        }
        trava.lock();
        enemy_draw(avioes);
        player.draw_on_campo(); //Desenhar o player de volta no buffer
        c.swap_buffers();
        trava.unlock();
        
    }
}
    

    
void tiros_control(std::vector<Tiro> &tiros, std::vector<Aviao> &enemy_vector, Aviao &player, Campo &c) {
    std::mutex trava;
        
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
    if(!tiros.empty()) {
        //loop para atualizar a posição dos tiros
        for(int i = 0; i < tiros.size(); i++) {
            bool a = tiros[i].disparo();
            if(a == false) tiros.erase(tiros.begin() + i);
        }
            
        //DRAW
        trava.lock();
        tiro_draw(tiros);
        enemy_draw(enemy_vector);
        player.draw_on_campo();
        c.swap_buffers();
        trava.unlock();
    }
    
}
    

#endif
