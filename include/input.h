#ifndef INPUT_H
#define INPUT_H

#include <termios.h>
#include <iostream>
#include <unistd.h>

#include "aviao.h"
#include "campo.h"


void enter_off();

void input(Aviao &player, Campo &c);
	
#endif
