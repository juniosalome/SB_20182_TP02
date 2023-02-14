#include "montador.h"


int main(int argc, char * argv[])
{

	/*Inicialização dos argumentos*/



		//Nome arquivo de entrada
		entrada = argv[1];
		//Nome arquivo de saida
		saida = argv[2];

		//Modo de operação
		if(argv[3] != NULL){
			modo = argv[3];
		}
		else{
			modo = "s";
		}

		MontadorEntrada();

    return 0;
}

