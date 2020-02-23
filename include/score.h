#include <string>
#include <sstream>
#include <iomanip>

struct Score {
	unsigned int score;
	int pos;
	Campo * c;
	std::string output;
	
	Score(Campo &c1) {
		c = &c1;
		score = 0;
		pos = c->width + 3;
		draw_on_campo();
	}

	void draw_on_campo() {
		output = "SCORE:";
		std::stringstream ss;
		ss << std::setw(5) << std::setfill('0') << score;
		output += ss.str();;

		for(int i = 0; i < output.size(); i++) {
			c->campo[pos + i] = output[i];
		}
	}
	

};
