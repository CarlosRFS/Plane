#include "game.h"

void Game::enemy_control(int h) {
    int pos = 6; 
    std::array<bool, 9> inimigos = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    for(int i = 0; i < h; i++) inimigos[i] = true;
    
    //embaralhar o array
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(inimigos.begin(), inimigos.end(), g);
		
    //criando os inimigos
    int w = 0; //o loop continua ate ele bater o h que e numero de inimigos na tela
    for(int z = 0; z < 3; z++) {
        int g = pos;
        for(int y = 0; y < 3; y++) {
            if(inimigos[w]) create_enemy(g);
            g += 18;
            w++;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    }


}

void Game::create_enemy(int &pos) {
    Aviao a1{c, player, pos, s, tiros_vector};
    enemy_vector.push_back(a1);
}

void Game::run() {
    std::mutex trava;
    c.swap_buffers();
    for(;;) {
        trava.lock();
        input(player, c);
        trava.unlock();
    }
}
