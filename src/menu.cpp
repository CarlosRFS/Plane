#include "menu.h"

Menu::Menu(Campo &c1, int pos1, Game jogo) 
: c(&c1), pos(pos1) {
    for(;;) {
        draw_on_campo();
        input(jogo);
        if(on == false) break;
    }
    erase();
    ajuste();

}

void Menu::draw_on_campo() {
    int w = pos;
    for(int i = 0; i < 3; i++) {
        if (difficulty == i) c->campo[w - 1] = 26; //marcador de seleçao
        for(int z = 0; z < lv_menu[i].size(); z++) {
            c->campo[w + z] = lv_menu[i][z];
        }
        w += c->width + 1;
    }
    c->swap_buffers();
}

void Menu::erase() {
    int w = pos;
    for(int i = 0; i < 3; i++) {
        if (difficulty == i) c->campo[w - 1] = ' '; //marcador de seleçao
        for(int z = 0; z < lv_menu[i].size(); z++) {
            c->campo[w + z] = ' ';
        }
        w += c->width + 1;
    }
    c->swap_buffers();
    
}

void Menu::input(Game &g) {
    enter_off();
    char entrada = std::cin.get();
    int w = pos + difficulty * (c->width + 1);
    switch(entrada) {
        case 'w':
            if(difficulty == 0) break;
            c->campo[w - 1] = ' ';
            difficulty--;
            draw_on_campo();
            break;
        case 's':
            if(difficulty == 2) break;
            c->campo[w - 1] = ' ';
            difficulty++;
            draw_on_campo();
            break;
        case 'f':
            on = false;
            break;
        default:
            break;
    }
}

void Menu::ajuste() {
    switch(difficulty) {
        case 0:
            difficulty = 3;
            break;

        case 1:
            difficulty = 5;
            break;
        
        case 2:
            difficulty = 7;
            break;
    }
}
