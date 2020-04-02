#include "campo.h"

Campo::Campo(char &caracter, int h, int w)
:height(h), width(w) {
    for(int i = 0; i < height * width; i++) {
        if(i % width == 0) buffer_limpo += "\n"; // Adiciona um \n na string quando termina uma fila
        
        if(i < width) buffer_limpo += caracter; // Automaticamente preenche a 1a fila

        else if(i % width == 0) buffer_limpo += caracter; // Preenche toda os primeiros espaços de cada fila

        else if(i % width == width - 1) buffer_limpo += caracter; // Os últimos de cada fila

        else if(i + width > width * height) buffer_limpo += caracter; // Preenche a última fila inteira

        else buffer_limpo += " ";
    }
    buffer_limpo += "\n";
    campo = buffer_limpo;
} 

void Campo::swap_buffers() {
    std::cout << "TROCANDO OS BUFFERS\n";
    frame = campo;
    campo = buffer_limpo;
    print();
}

void Campo::print() {
    std::cout << "\033[2J \033[0;0H" << frame;
}
