#include "campo.h"
#include <chrono>
#include <thread>

struct Tiro {
	int pos;

	Campo * c;

	Tiro(int &body, Campo &c1) {
		c = &c1;
		pos = body - (c->width + 1);
	}

	void draw_on_campo() {
		c->campo[pos] = 'x';
	}
	
	void erase_on_campo() {
		c->campo[pos] = ' ';
	}

	void trigger() {
		std::thread th1([&](){ this->disparo(); });
		th1.detach();
	}

	void disparo() {
		for(;;) {
			draw_on_campo();
			c->print();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			erase_on_campo();
			pos -= (c->width + 1);
			if(c->campo[pos] == 26) break; // Se a posição dele chegar em algo "desenhado" o loop acaba
		}
		c->print();
		return;
	}
};
