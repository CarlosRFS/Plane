#include "aviao.h"
#include "control_and_draw.h"

Aviao::Aviao(Campo &c1, std::vector<Tiro> &tiros_vector, std::vector<Aviao> &enemy_vector) {
    c = &c1;
    tiros = &tiros_vector;
    enemys = &enemy_vector;
    body = 1300; // Posiciona corretamente apenas em um campo 50x30
    asa1 = body + c->width - 2;
    asa2 = body + 3 * c->width + 2;
    draw_on_campo();
}

Aviao::Aviao(Campo &c1, Aviao &a, int &pos, Score &s1, std::vector<Tiro> &tiros_vector) { //construtor dos avioes inimigos
    c = &c1;
    s = &s1;
    alvo = &a;
    tiros = &tiros_vector;
    body = pos - 3 * (1 + c->width); // Posiciona corretamente apenas em qualquer campo
    asa2 = body - 1;
    asa1 = body + 2 * c->width - 1;
    draw_on_campo();
    enemy = true;
}

void Aviao::draw_on_campo() {
    for(int i = 0; i < 4; i++) { 
        if(body + (i * (c->width + 1)) > 0)
            c->campo[body + (i * (c->width + 1))] = caracter; 
    }

    for(int i = 0; i < 7; i++) {
        if(asa1 + 1 > 0)
            c->campo[asa1 + i] = caracter;
    }

    for(int i = 0; i < 3; i++) {
        if(asa2 + i > 0)
            c->campo[asa2 + i] = caracter;
    }
}

//FUNÇÂO ERASE NECESSARIA PARA O PLAYER
void Aviao::erase_on_campo() {
    for(int i = 0; i < 4; i++) { 
        if(body + (i * (c->width + 1)) > 0)
            c->campo[body + (i * (c->width + 1))] = ' '; 
    }

    for(int i = 0; i < 7; i++) {
        if(asa1 + 1 > 0)
            c->campo[asa1 + i] = ' ';
    }

    for(int i = 0; i < 3; i++) {
        if(asa2 + i > 0)
            c->campo[asa2 + i] = ' ';
    }
}

void Aviao::move_e() {
    if(c->campo[asa1 - 1] == 26) return;
    erase_on_campo();
    body -= 1;
    asa1 -= 1;
    asa2 -= 1;
    draw_on_campo();
    enemy_draw(*enemys); //EU NAO POSSO COLOCAR NO DRAW_ON_CAMPO PORQUE ELA TAMBEM È CHAMADA PELA FUNÇÂO QUE DESENHA OS INIMIGOS;
}

void Aviao::move_d() {
    if(c->campo[asa1 + 7] == 26) return;
    erase_on_campo();
    body += 1;
    asa1 += 1;
    asa2 += 1;
    draw_on_campo();
    enemy_draw(*enemys);
}

bool Aviao::disparo() { //serve apenas para os avioes inimigos
    body += (c->width + 1);
    asa1 += (c->width + 1);
    asa2 += (c->width + 1);
        
    if(c->frame[body + 4 * (c->width + 1)] == 26) return false;

    if(c->frame[body + 4 * (c->width + 1)] == 'x') {
        s->update_score();
        return false;}

    if(alvo->body % (c->width + 1) == body % (c->width + 1)) atirar(); //na frente do alvo atira	
    return true;
}

void Aviao::atirar() {
    Tiro t1{body, *c, enemy};
    tiros->push_back(t1);
}
	
