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




Lista* insereListaFinal(Lista*l, int i)
{   
    Lista *l = (Lista*) malloc(sizeof(Lista));
        if (l == NULL)
        printf("Lista nao existe");
        else
        {
            Lista *no = (Lista*)
        }
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

Lista* removeListaPrimeiro(Lista *l)
{
    if (ListaVazia(l))
        printf("Lista vazia!, não pode ser removido\n");
    else
    {
        Lista *t;
        t=l;
        l = l->prox;
        free(t);
        return l;
    }
}

Lista *removeListaNoMeio (Lista *l, int v)
{
    if (ListaVazia(l))
        printf("Lista vazia!, não pode ser removido\n");
    else
    {
        Lista *ant = NULL;
        Lista *t = l;
        while (t != NULL && t->info !=v)
        {
            ant = t;
            t = t->prox;
        }
        if (t == NULL)          //NAO EXISTE
        {
            printf ("\nNão encontrado %d", v);
            return l;
        }
        else
        {   
            if(ant == NULL)     //PRIMEIRO
            {
                l = t->prox;
                printf("\nelemento removido %d",v);
            }
            else                //MEIO
            {
                ant->prox = t->prox;
                printf("\nelemento removido %d",v);
            }
            free (t);
            return l;
        }

    }
}

void liberaLista(Lista *l)
{
    Lista *t = l, *p;
    while (t != NULL)
    {
        p = t->prox;
        free (t);
        t = p;
    }
    
}

Lista *insereListaOrdenada(Lista *l, int v)
{
    Lista *novo;
    Lista *ant = NULL;
    Lista *p = l;

    while (p != NULL && p->info <v)
    {
        ant=p;
        p = p->prox;
    }
    novo= (Lista*) malloc(sizeof(Lista));
    novo->info = v;
    if (ant == NULL)
    {
        novo->prox = l;
        l=novo;
    }
    else
    {
        novo->prox=ant->prox;
        ant->prox = novo;
    }
    return l;
}

//1:27