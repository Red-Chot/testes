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

Node *procurar(Node *raiz, int cod)
{
    if(raiz != NULL)
    {
        if(raiz->item.cod == cod){
        return raiz;
        }
        else 
        {
            Node *i;
            i = procurar(raiz->right, cod);
            if(i!= NULL)
            return procurar(raiz->right, cod);
            if(i == NULL)
            return procurar(raiz->left,cod);
        }
        
    }
    return NULL;
}

Node *menorElemento(Node *raiz)
{
    if (raiz != NULL)
    {
        Node *aux= raiz;
        while (aux ->left != NULL)
        {
            aux= aux->left;
        }
        return aux;
    } 
    return NULL;
}

Node *deletar (Node *raiz, int cod)
{
    if (raiz != NULL)
    {
        Node *i;
        i = procurar(raiz->right, cod);
            if(i!=NULL)
                raiz->right = deletar(raiz->right, cod);
            else if (i== NULL)
                raiz->left = deletar(raiz->left, cod);
            else
            {
                if(raiz->right == NULL && raiz->left == NULL)
                {
                    free(raiz);
                    return NULL;
                }
                else if(raiz->right == NULL && raiz->left != NULL)
                {
                    Node *aux = raiz->right;
                    free (raiz);
                    return aux; 
                }
                else if(raiz->right != NULL && raiz->left == NULL)
                {
                    Node *aux = raiz->left;
                    free(raiz);
                    return aux;
                }
                else
                {
                    Node *aux = menorElemento(raiz->left);
                    Item itemAux = aux->item;
                    raiz = deletar(raiz,itemAux.cod);
                    raiz->item = itemAux;
                    return raiz;
                }
                
            }
        return raiz;
    }   
    else
    return NULL;
}