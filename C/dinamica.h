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

int ListaVazia(Lista *l)
{
    return (l== NULL);
    
}

void imprimeLista (Lista *l)
{   
    if (ListaVazia(l))
    printf("Lista vazia!");
    else
    {
    
    Lista *t;
    for (t = l; t!=NULL ;t= t->prox)
    {
        printf ("\n Info %d", t->info);
    }
    }

}

