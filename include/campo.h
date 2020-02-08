#ifndef CAMPO_H
#define CAMPO_H

#include <iostream>
#include <string>

struct Campo {
	std::string campo;
	int width;
	int height;

	/* No construtor ele vai preencher a string campo 
	   pela primeira vez usando o caracter passado e adicionar \n quando necessario.*/
	Campo(char &caracter, int h, int w)
	:height(h), width(w) {
		for(int i = 0; i < height * width; i++) {
			if(i % width == 0) campo += "\n"; // Adiciona um \n na string quando termina uma fila
			
			if(i < width) campo += caracter; // Automaticamente preenche a 1a fila

			else if(i % width == 0) campo += caracter; // Preenche toda os primeiros espaços de cada fila

			else if(i % width == width - 1) campo += caracter; // Os últimos de cada fila

			else if(i + width > width * height) campo += caracter; // Preenche a última fila inteira

			else campo += " ";
		}
		campo += "\n";
	} 
	
	// Vai desenhar a string campo na tela;
	void print() {
		std::cout << "\033[2J \033[0;0H" << campo;
	}
};

#endif
