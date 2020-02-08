#include "campo.h"
#include "tiro.h"

struct Aviao {
	int body;
	char caracter = 26;
	Aviao(Campo &c1, char &caracter) {
		body = 1300; // Posiciona corretamente apenas em um campo 50x30 
		draw_on_campo(c1);
	}

	void draw_on_campo(Campo &c1) {
		for(int i = 0; i < 4; i++) c1.campo[body + (i * (c1.width + 1))] = caracter;

		for(int i = 0; i < 7; i++) c1.campo[body + c1.width - 2 + i] = caracter;

		for(int i = 0; i < 3; i++) c1.campo[body + 3 * c1.width + 2 + i] = caracter;
	}

	void erase_on_campo(Campo &c1) {
		for(int i = 0; i < 4; i++) c1.campo[body + (i * (c1.width + 1))] = ' ';

		for(int i = 0; i < 7; i++) c1.campo[body + c1.width - 2 + i] = ' ';

		for(int i = 0; i < 3; i++) c1.campo[body + 3 * c1.width + 2 + i] = ' ';
	}
	
	void move_e(Campo &c1) {
		if(c1.campo[body - 1] == 26) return;
		erase_on_campo(c1);
		body-=1;
		draw_on_campo(c1);
	}
	
	void move_d(Campo &c1) {
		if(c1.campo[body + 1] == 26) return;
		erase_on_campo(c1);
		body+=1;
		draw_on_campo(c1);
	}

	void atirar(Campo &c1) {
		Tiro * t1 = new Tiro{body, c1};
		t1->trigger(c1);
		if(c1.campo[t1->pos] == 26) delete t1;
	}
};
