#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stddef.h>

typedef struct no 
{
    int info;
    struct no *dir, *esq;
} Node; 

/*

Node* inserir(Node *raiz, int num)
{
    if (raiz == NULL)
    {   
        Node*aux =(Node*)malloc(sizeof(Node));
        aux->info = num;
        aux->esq = NULL;
        aux->dir = NULL;
        return aux;
    }
    else
    {
        if(num< raiz->info)
            raiz->esq = inserir(raiz->esq,num);
        else
        {
            raiz->dir = inserir(raiz->dir,num);
            return raiz;
        }

    }
}
*/

void inserirr(Node **raiz, int num)
{
    if (*raiz == NULL)
    {
        *raiz =(Node*)malloc(sizeof(Node));
        (*raiz)->info = num;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    }
    else
    {
        if(num<(*raiz)->info)
        {
            inserirr(((*raiz)->esq),num);
        }
    }
}

void imprimir (Node * raiz)
{
    if (raiz)
    {
        printf("%d", raiz->info);
        imprimir(raiz->esq);
        imprimir(raiz->dir);
    }

}
int main () 
{
    Node *raiz = NULL;
    int valor, op;
    do{
        printf("\n0-Sair\n1-inserir\n2-imprimir\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d",&valor);
            //raiz = inserir (raiz, valor);
            inserirr (&raiz, valor);
            break;
        case 2:
            printf("\n Impressao\n ");
            imprimir(raiz);
            printf("\n");

            
            break;
        case 3:
            printf("Digite um valor: ");
            scanf("%d",&valor);
            //raiz = inserir (raiz, valor);
            break;
        case 4:
            printf("Digite um valor: ");
            scanf("%d",&valor);
            //raiz = inserir (raiz, valor);
            break;
        default:
            break;
        }


    }while (op !=0);
    return 0;
}