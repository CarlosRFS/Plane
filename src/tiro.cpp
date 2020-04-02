#include "tiro.h"

Tiro::Tiro(int &body, Campo &c1, bool &l) {
    enemy = &l;
    c = &c1;
        
    if(!l) pos = body - (c->width + 1);
    else pos = body + 4 * (c->width + 1);
}

void Tiro::draw_on_campo() {
    c->campo[pos] = 'x';
        
}

bool Tiro::disparo() {
    //Direçao do Tiro
    if(!*enemy) pos -= (c->width + 1);
    else pos += (c->width + 1);

        if(c->frame[pos] != ' ') return false; // Se a posição dele chegar em algo "desenhado" o loop acaba
    return true;

}
