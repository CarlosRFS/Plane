#include "score.h"
#include "campo.h"

Score::Score(Campo &c1) {
    c = &c1;
    score = 0;
    pos = c->width + 3;
    draw_on_campo();
}

void Score::draw_on_campo() {
    output = "SCORE:";
    std::stringstream ss;
    ss << std::setw(5) << std::setfill('0') << score;
    output += ss.str();;

    for(int i = 0; i < output.size(); i++) {
        c->campo[pos + i] = output[i];
    }
}

void Score::update_score() {
    score += 10;
    draw_on_campo();
}
