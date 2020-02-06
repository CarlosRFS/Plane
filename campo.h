#include <iostream>
#include <string>

struct Campo {
	std::string campo;
	int width;
	int height;

	Campo(char tijolo); //no construtor ele vai preencher a string campo 
			    //pela primeira vez usando o caracter passado e adicionar \n quando necessario.
	void print(); //vai desenhar a string campo na tela;
};
