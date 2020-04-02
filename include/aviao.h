#ifndef AVIAO_H
#define AVIAO_H

#include "campo.h"
#include "tiro.h"
#include "score.h"

#include <vector>

struct Aviao {
	int body;
	int asa1;
	int asa2;
	static constexpr char caracter = 26;
	bool enemy = false;

	Campo * c;
	Aviao * alvo;
	Score * s;
    std::vector<Tiro> * tiros;
    std::vector<Aviao> * enemys;
	
//TALVEZ SEJA NECESSARIO CRIAR UM PONTEIRO PARA O VECTOR DE TIROS

	Aviao(Campo &c1, std::vector<Tiro> &tiros_vector, std::vector<Aviao> &enemy_vector);
	
	Aviao(Campo &c1, Aviao &a, int &pos, Score &s1, std::vector<Tiro> &tiros_vector); //CONSTRUTOR DOS AVIOES INIMIGOS

	void draw_on_campo();

	//FUNÇÂO ERASE NECESSARIA PARA O PLAYER
    void erase_on_campo();

    void move_e();
	
	void move_d();
	
	bool disparo(); //serve apenas para os avioes inimigos

	void atirar();
};

#endif
