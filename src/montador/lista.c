#include "lista.h"

//cria uma lista vazia
Lista* CriaLista()
{
    Lista* lista; 
    lista=malloc(sizeof(Lista));
    lista->Primeiro=lista->Ultimo=NULL;
    return lista;

}
//verifica se uma lista esta vazia
int Vazia(Lista* lista)
{  
    if (lista->Primeiro == NULL)
        return(1);
    else
        return(0);
}

//torna uma lista vazia 
void FazVaziaSimbolos(Lista* lista)
{
   Celula *aux,*aux2;
   aux = lista->Primeiro;
    do
    {
       aux2=aux->Proximo;
       free(aux->item.simbolo.label);
       free(aux);
       aux=aux2;
    }while(aux != NULL);
}

//torna uma lista vazia 
void FazVazia(Lista* lista)
{
   Celula *aux,*aux2;
   aux = lista->Primeiro;
    do
    {
       aux2=aux->Proximo;
       free(aux);
       aux=aux2;
    }while(aux != NULL);
}

//insere uma celula na lista 
void Insere(Lista* lista,int valor)
{
    int aux;
   
   if(lista->Primeiro==NULL)
   {
       lista->Primeiro=malloc(sizeof(Celula));
       lista->Ultimo=lista->Primeiro;
       lista->Ultimo->item.funcao.posicao=0;     
   }
   else
   {
       aux=lista->Ultimo->item.funcao.posicao; 
       lista->Ultimo->Proximo=malloc(sizeof(Celula));
       lista->Ultimo=lista->Ultimo->Proximo;
       lista->Ultimo->item.funcao.posicao=aux+1; 
   }
   lista->Ultimo->Proximo=NULL;
   lista->Ultimo->item.funcao.valor=valor;
}
//insere uma celula na lista de simbolos
void InsereSimbolo(Lista* lista,int posicao,char* label)
{
 
    if(lista->Primeiro==NULL)
   {
       lista->Primeiro=malloc(sizeof(Celula));
       lista->Ultimo=lista->Primeiro;
       lista->Ultimo->item.funcao.posicao=0;     
   }
   else
   {
       lista->Ultimo->Proximo=malloc(sizeof(Celula));
       lista->Ultimo=lista->Ultimo->Proximo;
   }
   lista->Ultimo->Proximo=NULL;
   lista->Ultimo->item.simbolo.posicao=posicao;
   lista->Ultimo->item.simbolo.label=malloc(50);
   strcpy(lista->Ultimo->item.simbolo.label,label);
   lista->Ultimo->item.simbolo.label[strlen(lista->Ultimo->item.simbolo.label)-1]='\0';
}

