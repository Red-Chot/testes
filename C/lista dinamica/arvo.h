#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stddef.h>

struct item
{
    int info;
};

typedef struct item Item;

struct node
{   
    Item item;
    struct node *esq;
    struct node *dir;
};

typedef node Node;

Node *start()
{
    return NULL;
}

Item criar(int info)
{
    Item item;
    item.info = info;
    return item;
}

Node *inserir(Node *raiz, Item novo)  // inserindo elementos
{   
    int resp;
    if (raiz == NULL)
    {
        Node*aux =(Node*)malloc(sizeof(Node));
        aux ->item = novo;
        aux->dir= NULL;
        aux->esq = NULL;
        return aux;
    }
    else
    {   
        if(novo.info > raiz->item.info)
        {
            raiz->dir = inserir(raiz->dir,novo );
        }
        else if (novo.info < raiz->item.info)
        {
            raiz->esq = inserir(raiz->esq,novo );
        }
    }
    return raiz;
}

void imprimir(Node *raiz)
{
    if(raiz != NULL)
    {
        printf("\n-----------------------------------------------------------\n");
        printf(" %d",raiz->item.info);
        imprimir(raiz->dir);
        imprimir(raiz->esq);
        
    }
}

void libera(Node *cod)
{
    if(cod != NULL)
    {
        libera(cod->esq);
        libera(cod->dir);
        free(cod);
    }
}

Node *arvBusca(Node *raiz, int info)
{
    if(raiz != NULL)
    {
        if(raiz->item.info == info)
        {
            return raiz;
        }
        else
        {
            if (info >raiz->item.info)
            {
                return arvBusca(raiz->dir,info);
            }
            else 
            return arvBusca(raiz->esq,info);
        }
        
    }
    return NULL;
}

Node *menorElemento(Node *raiz)
{
    if (raiz != NULL)
    {
        Node *Raiz= raiz;
        while (Raiz ->esq != NULL)
        {
            Raiz= Raiz->dir;
        }
        return Raiz;
    } 
    return NULL;
}

Node *deletar (Node *raiz, int info)
{
    if (raiz != NULL)
    {
            if(info >raiz->item.info)
                raiz->dir = deletar(raiz->dir, info);
            else if (info< raiz->item.info)
                raiz->esq = deletar(raiz->esq, info);
            else
            {
                if(raiz->dir == NULL && raiz->esq == NULL)
                {   
                    Node *i;
                    free(raiz);
                    i = NULL;
                    return i;
                }
                else if(raiz->dir == NULL && raiz->esq != NULL)
                {   
                    Node *i;
                    Node *Raiz = raiz->esq;
                    free (raiz);
                    i = raiz;
                    return i; 
                }
                else if(raiz->dir != NULL && raiz->esq == NULL)
                {   
                    Node *i;
                    Node *Raiz = raiz->dir;
                    free(raiz);
                    i = raiz;
                    return i;
                }
                else
                {   
                    Node *i;
                    Node *Raiz = menorElemento(raiz->dir);
                    Item itemAux = Raiz->item;
                    raiz = deletar(raiz,itemAux.info);
                    raiz->item = itemAux;
                    i = raiz;
                    return i;
                }
                
            }return raiz;
    }   
    return NULL;
}
