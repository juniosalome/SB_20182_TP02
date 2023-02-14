#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item
{
    int posicao,valor;
        
}Item;

typedef struct Item2
{
    char* label;
    int posicao;
}Item2;

typedef union no
{ 
 Item funcao;
 Item2 simbolo;
}no;

typedef struct Celula
{   
   no item; 
   struct Celula *Proximo;
}Celula;


typedef struct Lista
{   
    Celula *Primeiro;
    Celula *Ultimo;
}Lista;
//cria uma lista vazia 
Lista* CriaLista();
//Insere um nova celula  na lista  
void Insere(Lista* lista,int valor);
//Insere um nova celula  na lista de simbolos 
void InsereSimbolo(Lista* lista,int posicao,char* label);
//retorna 1 se a lista estiver vazia e 0 caso contrario
int Vazia(Lista* lista);
//torna uma lista fazia
void FazVazia(Lista* lista);

#endif
