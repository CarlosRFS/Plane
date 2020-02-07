#include "campo.h"
#include "tiro.h"

#include <thread>

struct Aviao {
	int body;

	Aviao(Campo &c1, char &caracter) {
		draw_on_campo(c1);
	}

	void draw_on_campo(Campo &c1) {
		for(int i = 0; i < 4; i++) c1.campo[body + i] = caracter;
	}

	void erase_on_campo(Campo &c1) {
		for(int i = 0; i < 4; i++) c1.campo[body + i] = " ";
	}
	
	void move_<(Campo &c1) {
		if(c1.campo[body - 1] == 26) return;
		body-=1;
		draw_on_campo(c1);
	}
	
	void move_>() {
		if(c1.campo[body + 1] == 26) return;
		body+=1;
		draw_on_campo(c1);
	}

	//void atirar();
};
