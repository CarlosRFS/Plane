#ifndef TIRO_H
#define TIRO_H

//STD HEADERS
#include <chrono>
#include <thread>

//Project Headers
#include "campo.h"

struct Tiro {
    int pos;
    Campo * c;
    bool * enemy;
    
    Tiro(int &body, Campo &c1, bool &l) {
        enemy = &l;
        c = &c1;
        
        if(!l) pos = body - (c->width + 1);
        else pos = body + 4 * (c->width + 1);
    }

    void draw_on_campo() {
        c->campo[pos] = 'x';
        
    } //NAO PRECISA SER ALTERADA
    
    
    bool disparo() {
        //Direçao do Tiro
        if(!*enemy) pos -= (c->width + 1);
        else pos += (c->width + 1);

			if(c->frame[pos] != ' ') return false; // Se a posição dele chegar em algo "desenhado" o loop acaba
		return true;

    }

    
};

#endif
