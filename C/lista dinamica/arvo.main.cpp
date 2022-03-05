#include <stdio.h>
#include <stdlib.h>
#include "arvo.h"


int main()
{
    Node *Raiz = start();
    Raiz =inserir(Raiz,criar(10));
    Raiz =inserir(Raiz,criar(15));
    Raiz =inserir(Raiz,criar(20));
    Raiz =inserir(Raiz,criar(12));
    Raiz =inserir(Raiz,criar(5));


    
    printf("Antes de remover\n");
    imprimir(Raiz);
    Raiz = deletar(Raiz,12);
    printf("\n");
    printf("dps\n");
    imprimir (Raiz);
    libera(Raiz);
    return 0;
}

