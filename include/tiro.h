#ifndef TIRO_H
#define TIRO_H

//STD HEADERS
#include <chrono>
#include <thread>

//Project Headers
#include "campo.h"

struct Tiro {
    int pos;
    Campo * c;
    bool * enemy;
    
    Tiro(int &body, Campo &c1, bool &l);

    void draw_on_campo();
    
    
    bool disparo();

    
};

#endif
