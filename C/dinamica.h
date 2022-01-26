#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info; 
    struct lista *prox;
} Lista;


Lista* criaLista(){
    return NULL;
}

Lista* insereListaInicio(Lista *l, int i) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo ->info = i;
    novo -> prox = l;
    return novo;
}