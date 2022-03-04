#include <stdio.h>
#include <stdlib.h>
#include "arvo.h"


int main()
{
    Node *raiz = inicializa();
    raiz=inserir(raiz,create(10));
    raiz=inserir(raiz,create(25));
    raiz=inserir(raiz,create(14));
    imprimir(raiz);
    printf("\n");
    libera(raiz);

    return 0;
}

