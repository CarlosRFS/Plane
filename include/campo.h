#ifndef CAMPO_H
#define CAMPO_H

#include <iostream>
#include <string>

struct Campo {
    std::string frame;
	std::string campo;
    std::string buffer_limpo;
    int height;
	int width;

	/* No construtor ele vai preencher a string buffer_limpo que vai conter o campo limpo, e posteriormente o campo vai sempre copiar dela 
     * quando for pra limpar os objetos da tela 
	   pela primeira vez usando o caracter passado e adicionar \n quando necessario.*/
	Campo(char &caracter, int h, int w);
	
	void swap_buffers();
	
	// Vai desenhar a string campo na tela;
	void print();
};

#endif
