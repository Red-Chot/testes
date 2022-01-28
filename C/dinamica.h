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
    printf("Lista vazia!\n");
    else
    {
    
    Lista *t;
        for (t = l; t!=NULL ;t= t->prox)
        {
            printf ("\n Info %d", t->info);
        }
    }
}

Lista* BuscaLista (Lista *l, int v)
{   
    if (ListaVazia(l))
        printf("Lista vazia!\n");
    else
    {
    
        Lista *t;
            for (t = l; t!=NULL ;t= t->prox)
            {
                if(t->info == v)
            {        
            printf("\n%d foi encontrado",t->info);
            return t;
        }
    }
        printf("Elemento nao encontrado\n");
    }
    return NULL;
}

void removeListaPrimeiro(Lista *l)
{
    if (ListaVazia(l))
    printf("Lista vazia!, não pode ser removido\n");
    else
    {
        Lista *t;
        t=l;
        l = l->prox;
        free(t);

    }
}