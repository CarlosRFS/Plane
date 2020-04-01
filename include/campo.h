#ifndef CAMPO_H
#define CAMPO_H

#include <iostream>
#include <string>

struct Campo {
    std::string frame;
	std::string campo;
    std::string buffer_limpo;
	int width;
	int height;

	/* No construtor ele vai preencher a string buffer_limpo que vai conter o campo limpo, e posteriormente o campo vai sempre copiar dela 
     * quando for pra limpar os objetos da tela 
	   pela primeira vez usando o caracter passado e adicionar \n quando necessario.*/
	Campo(char &caracter, int h, int w)
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
	
	void swap_buffers() {
        std::cout << "TROCANDO OS BUFFERS\n";
        frame = campo;
        campo = buffer_limpo;
        print();
    }
	
	// Vai desenhar a string campo na tela;
	void print() {
		std::cout << "\033[2J \033[0;0H" << frame;
	}
};

#endif
