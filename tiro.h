#include "campo.h"
#include <chrono>
#include <thread>

struct Tiro {
	int pos;

	Tiro(int &body, Campo &c1) {
		pos=body - c1.width + 1;
	}

	void draw_on_campo(Campo &c1) {
		c1.campo[pos] = 'x';
	}
	

	void trigger(Campo &c1) {
		std::thread th1([&](){ this->disparo(c1); });
		th1.join();
	}

	void disparo(Campo &c1) {
		for(;;) {
			draw_on_campo(c1);
			pos++;
			if(c1.campo[pos] == 26) break; //se a posição dele chegar em algo "desenhado" o loop acaba
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		return;
	}
};
