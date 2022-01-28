#include <stdio.h>
#include "dinamica.h"

int main ()
{
    Lista*aLista;
    aLista = criaLista();
    imprimeLista(aLista);
    aLista = insereListaInicio(aLista, 23);
    aLista = insereListaInicio(aLista, 45);
    aLista = insereListaInicio(aLista, -9);
    imprimeLista (aLista);
    return 0; 
}
