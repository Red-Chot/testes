#include <stdio.h>
#include "dinamica.h"

int main ()
{
    int num;

    Lista*aLista;
    aLista = criaLista();
    imprimeLista(aLista);
    aLista = insereListaInicio(aLista, 23);
    aLista = insereListaInicio(aLista, 45);
    aLista = insereListaInicio(aLista, 29);
    aLista = insereListaInicio(aLista, -9);
    aLista = removeListaPrimeiro(aLista);
    imprimeLista (aLista);
    printf ("\nDigite o valor a ser removido\n");
    scanf ("%d", &num);
    aLista = removeListaNoMeio(aLista, num);
    imprimeLista(aLista);
    liberaLista (aLista);
    aLista = criaLista();
    aLista = insereListaOrdenada(aLista, 23);
    aLista = insereListaOrdenada(aLista, 45);
    aLista = insereListaOrdenada(aLista, -9);
    imprimeLista(aLista);
    liberaLista (aLista);
    return 0; 
}


