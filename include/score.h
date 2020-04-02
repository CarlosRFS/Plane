#ifndef SCORE_H
#define SCORE_H

#include <string>
#include <sstream>
#include <iomanip>

#include "campo.h"

struct Score {
	unsigned int score;
	int pos;
	Campo * c;
	std::string output;
	
	Score(Campo &c1);

	void draw_on_campo();

	void update_score();
	

};

#endif
