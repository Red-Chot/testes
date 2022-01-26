#include <stddef.h>
#include <stdio.h>


typedef struct lista
{
    int info; 
    struct lista *prox;
} Lista;


Lista* criaLista(){
    return NULL;
}

Lista* insereListaInicio(Lista *1, int i) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));

}