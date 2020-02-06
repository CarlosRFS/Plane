#include <iostream>
#include <string>

struct Campo {
	std::string campo;
	int width;
	int height;

	//no construtor ele vai preencher a string campo 
	//pela primeira vez usando o caracter passado e adicionar \n quando necessario.
	Campo(char caracter) {
		for(int i = 0; i < height * width; i++) {
			if(i % width = 0) campo += "\n"; //adiciona um \n na string quando termina uma fila
			
			if(i < width) campo += caracter; //automaticamente preenche a 1 fila

			else if(i % width == 0) campo += caracter; //preenche toda os primeiros espaços de cada fila

			else if(i % width == width - 1) campo += bloco; // os ultimos de cada fila

			else if(i + width > width * height) campo += bloco; // preenche a ultima fila inteira
		}
		campo += "\n";	
	} 
	void print(); //vai desenhar a string campo na tela;
};
