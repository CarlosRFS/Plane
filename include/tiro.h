#include "campo.h"
#include <chrono>
#include <thread>

struct Tiro {
	int pos;

	Tiro(int &body, Campo &c1) {
		pos = body - (c1.width + 1);
	}

	void draw_on_campo(Campo &c1) {
		c1.campo[pos] = 'x';
	}
	
	void erase_on_campo(Campo &c1) {
		c1.campo[pos] = ' ';
	}

	void trigger(Campo &c1) {
		std::thread th1([&](){ this->disparo(c1); });
		th1.detach();
	}

	void disparo(Campo &c1) {
		for(;;) {
			draw_on_campo(c1);
			c1.print();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			erase_on_campo(c1);
			pos -= (c1.width + 1);
			if(c1.campo[pos] == 26) break; // Se a posição dele chegar em algo "desenhado" o loop acaba
		}
		c1.print();
		return;
	}
};
