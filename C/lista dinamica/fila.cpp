#include <stdio.h>
#include "fila.h"
#include <locale.h>
#include <conio.h>

//-------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------EXECUTA ESSE-------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------



int main ()
{                                                                   setlocale (LC_ALL, "Portuguese");
    int num, Resp=0, sair = 1,posi=0;
    {
        Lista*aLista;
        aLista = criaLista();
        aLista = insereListaInicio(aLista, NULL);
        while (sair == 1){
            int valor=0;
            Resp = menu_lista();
            system("cls");
            switch (Resp)
            {
            case 1:
                 printf ("\nInforme o valor para adicionar no fim:\n");
                scanf ("%d", &valor);
                insereFim(aLista);
                break;
            case 2:
                aLista = removeListaPrimeiro(aLista);
                printf ("\n",aLista);
                break;
            case 3:
                printf ("\nInforme o valor para ser buscado\n");
                scanf ("%d", &valor);
                aLista = BuscaLista(aLista, valor);
                break;
            case 4:
                liberaLista(aLista);
                break;
            case 5:
                imprimeLista(aLista);
                break;
            
            case 6:
                sair = -1;
                break;
            }
        }
    }
    system ("PAUSE");
    return 0; 
}


