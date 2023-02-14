#include "montador.h"

int Operador(char* operador) {
	if (!strcmp("LOAD", operador))
		return opcode_LOAD;
	if (!strcmp("STORE", operador))
		return opcode_STORE;
	if (!strcmp("PUSH", operador))
		return opcode_PUSH;
	if (!strcmp("POP", operador))
		return opcode_POP;
	if (!strcmp("JUMP", operador))
		return opcode_JUMP;
	if (!strcmp("JZ", operador))
		return opcode_JZ;
	if (!strcmp("JNZ", operador))
		return opcode_JNZ;
	if (!strcmp("JN", operador))
		return opcode_JN;
	if (!strcmp("JNN", operador))
		return opcode_JNN;
	if (!strcmp("COPY", operador))
		return opcode_COPY;
	if (!strcmp("XOR", operador))
		return opcode_XOR;
	if (!strcmp("AND", operador))
		return opcode_AND;
	if (!strcmp("OR", operador))
		return opcode_OR;
	if (!strcmp("NOT", operador))
		return opcode_NOT;
	if (!strcmp("ADD", operador))
		return opcode_ADD;
	if (!strcmp("SUB", operador))
		return opcode_SUB;
	if (!strcmp("READ", operador))
		return opcode_READ;
	if (!strcmp("WRITE", operador))
		return opcode_WRITE;
	if (!strcmp("CALL", operador))
		return opcode_CALL;
	if (!strcmp("RET", operador))
		return opcode_RET;
	if (!strcmp("HALT", operador))
		return opcode_HALT;
	if (!strcmp("WORD", operador))
		return opcode_WORD;
	if (!strcmp("END", operador))
		return opcode_END;
	return 0;
}

int Operando(Lista* TabelaSimbolos, char* operando) {
	Celula* aux;
	int posicao;
	aux = TabelaSimbolos->Primeiro;
	posicao = 0;
	while (aux != NULL) {
		if (!strcmp(operando, aux->item.simbolo.label)) {
			posicao = aux->item.simbolo.posicao;
			return posicao;
		}
		aux = aux->Proximo;
	}
	return posicao;
}

void MontadorSaida(Lista *lista, Lista *TabelaSimbolos) {
	FILE* arquivo;
	Celula *celula;
	arquivo = fopen(saida, "w");
	celula = lista->Primeiro;
	while (celula != NULL) {
		fprintf(arquivo, "%d\n", celula->item.funcao.valor);
		celula = celula->Proximo;
	}
	if (*modo == 'v') {
		celula = TabelaSimbolos->Primeiro;
		while (celula != NULL) {
			printf("%s\t%d\n", celula->item.simbolo.label,
					celula->item.simbolo.posicao);
			celula = celula->Proximo;
		}
	}
}

void MontadorEntrada() {

	char palavra[100];
	Lista *lista, *TabelaSimbolos;
	FILE* arquivo;
	int aux, i, operador;
	lista = CriaLista();
	TabelaSimbolos = CriaLista();
	arquivo = fopen(entrada, "r");
	for (i = 0; i < 2; i++) {
		aux = 0;
		do {

			fscanf(arquivo, "%s", palavra);
			if (palavra[0] == 59) {
				fgets(palavra, 100, arquivo);
			} else {
				if (palavra[strlen(palavra) - 1] == ':') {
					if (!i)
						InsereSimbolo(TabelaSimbolos, aux, palavra);
					fscanf(arquivo, "%s", palavra);
					if (palavra[0] == 59) {
						fgets(palavra, 100, arquivo);
					} else {
						if (strcmp(palavra, "WORD") && strcmp(palavra, "END")) {
							operador = Operador(palavra);
							if (i)
								Insere(lista, operador);
						}
						aux++;
					}
				} else {
					if (strcmp(palavra, "WORD") && strcmp(palavra, "END")) {
						operador = Operador(palavra);
						if (i)
							Insere(lista, operador);
						aux++;
					}
				}

				if (strcmp("RET", palavra) && strcmp("HALT", palavra)
						&& strcmp("NOT", palavra) && strcmp("END", palavra)) {
					fscanf(arquivo, "%s", palavra);
					if (palavra[0] == 59) {
						fgets(palavra, 100, arquivo);
					} else {
						if (i) {
							Insere(lista, Operando(TabelaSimbolos, palavra));
							if (operador > 6 && operador < 12) {
								lista->Ultimo->item.funcao.valor -=
										lista->Ultimo->item.funcao.posicao;
							}
						}
						aux++;
					}
				}
			}
		} while (strcmp(palavra, "END"));
		rewind(arquivo);
	}

	fclose(arquivo);

	MontadorSaida(lista, TabelaSimbolos);

}
