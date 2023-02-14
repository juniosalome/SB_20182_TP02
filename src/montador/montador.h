#ifndef MONTADOR_H
#define MONTADOR_H
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "constantes.h"
#include "lista.h"

int Operador(char* operador);
int Operando(Lista* TabelaSimbolos,char* operando);
void MontadorEntrada();
void MontadorSaida(Lista *celula, Lista *TabelaSimbolos);
#endif
