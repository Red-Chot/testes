#include <stdio.h>
#include <stdlib.h>
#include "arvo.h"


int main()
{
    Node *raiz = inicializa();
    raiz=inserir(raiz,create(10));
    raiz=inserir(raiz,create(15));
    raiz=inserir(raiz,create(20));
    raiz=inserir(raiz,create(12));
    raiz=inserir(raiz,create(5));

    imprimir(raiz);
    printf("\n");
    imprimir(raiz);
    raiz = deletar(raiz, 10);
    imprimir (raiz);
    libera(raiz);



    return 0;
}

