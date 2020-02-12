#include "campo.h"
#include "tiro.h"

struct Aviao {
	int body;
	int asa1;
	int asa2;
	char caracter = 26;
	
	Aviao(Campo &c1) {
		body = 1300; // Posiciona corretamente apenas em um campo 50x30
		asa1 = body + c1.width - 2;
		asa2 = body + 3 * c1.width + 2;
		draw_on_campo(c1);
	}
	
	Aviao(Campo &c1, bool inimigo) { //construtor dos avioes inimigos
		body = c1.width / 2; // Posiciona corretamente apenas em qualquer campo
		asa2 = body + c1.width - 2;
		asa1 = body + 3 * c1.width + 2;
		draw_on_campo(c1);
		std::thread a1([&]() { this->disparo(c1); });
	}

	void draw_on_campo(Campo &c1) {
		for(int i = 0; i < 4; i++) c1.campo[body + (i * (c1.width + 1))] = caracter;

		for(int i = 0; i < 7; i++) c1.campo[asa1 + i] = caracter;

		for(int i = 0; i < 3; i++) c1.campo[asa2 + i] = caracter;
	}

	void erase_on_campo(Campo &c1) {
		for(int i = 0; i < 4; i++) c1.campo[body + (i * (c1.width + 1))] = ' ';

		for(int i = 0; i < 7; i++) c1.campo[asa1 + i] = ' ';

		for(int i = 0; i < 3; i++) c1.campo[asa2 + i] = ' ';
	}
	
	void move_e(Campo &c1) {
		if(c1.campo[asa1 - 1] == 26) return;
		erase_on_campo(c1);
		body -= 1;
		asa1 -= 1;
		asa2 -= 1;
		draw_on_campo(c1);
	}
	
	void move_d(Campo &c1) {
		if(c1.campo[asa1 + 7] == 26) return;
		erase_on_campo(c1);
		body += 1;
		asa1 += 1;
		asa2 += 1;
		draw_on_campo(c1);
	}

	
	void disparo(Campo &c1) { //serve apenas para os avioes inimigos
		for(;;) {
			draw_on_campo(c1);
			c1.print();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			erase_on_campo(c1);
			body += (c1.width + 1);
			if(c1.campo[body + 4 * (c1.width + 1)] == 26) break; 
		}
		c1.print();
		return;
	}
	

	void atirar(Campo &c1) {
		Tiro * t1 = new Tiro{body, c1};
		t1->trigger(c1);
		if(c1.campo[t1->pos] == 26) delete t1;
	}
};
