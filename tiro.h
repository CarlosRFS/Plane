#include "campo.h"

struct Tiro {
	int pos;

	Tiro(int &body) {
		pos=body - c1.width + 1;
	}

	void draw_on_campo(Campo &c1) {
		c1.campo[pos] = x;
	}

	void disparo(Campo &c1) {
		for(;;) {
			draw_on_campo(c1);
			pos++;
			if(c1.campo[pos] == 26) break; //se a posição dele chegar em algo "desenhado" o loop acaba
		}
	}
};
