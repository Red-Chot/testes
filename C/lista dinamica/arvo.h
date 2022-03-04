#include <stdio.h>
#include <stdlib.h>

struct item
{
    int cod;
};

typedef struct item Item;

struct node
{
    Item item;
    struct node *left;
    struct node *right;
    
};

typedef node Node;

Node *inicializa()
{
    return NULL;
}

Item create(int cod)
{
    Item item;
    item.cod = cod;
    return item;
}

Node *inserir(Node *raiz, Item x)
{   
    int resp;
    if (raiz == NULL)
    {
        Node*aux =(Node*)malloc(sizeof(Node));
        aux ->item = x;
        aux->left = NULL;
        aux->right= NULL;
        return aux;
    }
    else
    {   
        printf("\nDeseja adicionar a direita ou esquerda? 1/DIREITA | 2/ESQUERDA\n");
        scanf ("%d",&resp);
        if (resp == 1)
        {
            raiz->right =inserir(raiz->right,x);
        }
        else if (resp == 2)
        {
            raiz->left =inserir(raiz->left,x);
        }
        

    }
    return raiz;
}

void imprimir(Node *raiz)
{
    if(raiz != NULL)
    {
        printf("%d ",raiz->item.cod);
        imprimir(raiz->left);
        imprimir(raiz->right);
    }
}

void libera(Node *raiz)
{
    if(raiz != NULL)
    {
        libera(raiz->left);
        libera(raiz->right);
        free(raiz);
    }
}