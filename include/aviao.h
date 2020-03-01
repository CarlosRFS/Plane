#include "campo.h"
#include "tiro.h"
#include "score.h"

struct Aviao {
	int body;
	int asa1;
	int asa2;
	char caracter = 26;
	bool enemy = false;

	Campo * c;
	Aviao * alvo;
	Score * s;
	
	Aviao(Campo &c1) {
		c = &c1;
		body = 1300; // Posiciona corretamente apenas em um campo 50x30
		asa1 = body + c->width - 2;
		asa2 = body + 3 * c->width + 2;
		draw_on_campo();
	}
	
	Aviao(Campo &c1, Aviao &a, int &pos, Score &s1) { //construtor dos avioes inimigos
		c = &c1;
		s = &s1;
		alvo = &a;
		body = pos; // Posiciona corretamente apenas em qualquer campo
		asa2 = body - 1;
		asa1 = body + 2 * c->width - 1;
		draw_on_campo();
		trigger();
		enemy = true;
	}

	void trigger() {
		std::thread a1([&]() { this->disparo(); });
		a1.detach();
	}

	void draw_on_campo() {
		for(int i = 0; i < 4; i++) c->campo[body + (i * (c->width + 1))] = caracter;

		for(int i = 0; i < 7; i++) c->campo[asa1 + i] = caracter;

		for(int i = 0; i < 3; i++) c->campo[asa2 + i] = caracter;
	}

	void erase_on_campo() {
		for(int i = 0; i < 4; i++) c->campo[body + (i * (c->width + 1))] = ' ';

		for(int i = 0; i < 7; i++) c->campo[asa1 + i] = ' ';

		for(int i = 0; i < 3; i++) c->campo[asa2 + i] = ' ';
	}
	
	void move_e() {
		if(c->campo[asa1 - 1] == 26) return;
		erase_on_campo();
		body -= 1;
		asa1 -= 1;
		asa2 -= 1;
		draw_on_campo();
	}
	
	void move_d() {
		if(c->campo[asa1 + 7] == 26) return;
		erase_on_campo();
		body += 1;
		asa1 += 1;
		asa2 += 1;
		draw_on_campo();
	}

	
	void disparo() { //serve apenas para os avioes inimigos
		for(;;) {
			draw_on_campo();
			c->print();
			std::this_thread::sleep_for(std::chrono::milliseconds(800));
			erase_on_campo();
			body += (c->width + 1);
			asa1 += (c->width + 1);
			asa2 += (c->width + 1);
			
			if(c->campo[body + 4 * (c->width + 1)] == 26) break;

			if(c->campo[body + 4 * (c->width + 1)] == 'x') {
				s->update_score();
				break;}

			if(alvo->body % (c->width + 1) == body % (c->width + 1)) atirar(); //na frente do alvo atira	
		}
		c->print();
		return;
	}
	

	void atirar() {
		Tiro * t1 = new Tiro{body, *c, enemy};
		t1->trigger();
		if(c->campo[t1->pos] == 26) delete t1;
	}
};
