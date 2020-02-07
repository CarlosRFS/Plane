#include "campo.h"
#include "tiro.h"

#include <thread>

struct Aviao {
	int body;
	char caracter = 26;
	Aviao(Campo &c1, char &caracter) {
		body = 1300; 
		draw_on_campo(c1);
	}

	void draw_on_campo(Campo &c1) {
		for(int i = 0; i < 4; i++) c1.campo[body + (i * (c1.width + 1))] = caracter;
	}

	void erase_on_campo(Campo &c1) {
		for(int i = 0; i < 4; i++) c1.campo[body + (i * (c1.width + 1))] = ' ';
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

	//void atirar();
};
