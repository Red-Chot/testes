#include <stdio.h>
#include <stdlib.h>
#include "arvo.h"
#include <locale.h>
/*
int main()
{   

    Node *Raiz = start();
    Raiz =inserir(Raiz,criar(10));
    Raiz =inserir(Raiz,criar(15));
    Raiz =inserir(Raiz,criar(20));
    Raiz =inserir(Raiz,criar(12));
    Raiz =inserir(Raiz,criar(5));
    Node *tmp = arvBusca(Raiz,3);
    if (tmp == NULL)
    {
        printf("Nao encotramos\n");
    }
    else
    {
        printf("Encotramos\n");
    }
    
    printf("Antes de remover\n");
    imprimir(Raiz);
    Raiz = deletar(Raiz,12);
    printf("\n");
    printf("dps\n");
    imprimir (Raiz);
    libera(Raiz);
    return 0;
}
*/

int main ()
{                                                                   setlocale (LC_ALL, "Portuguese");
    int num, Resp=0, sair = 1,posi=0;
    {   
        Node *Raiz = start();
        Item valor;
        while (sair == 1){
            int valor=0;
            Resp = menu_lista();
            system("cls");
            switch (Resp)
            {
            case 1:
                 printf ("\nInforme o valor para adicionar no fim:\n");
                scanf ("%g", &valor);
                Raiz =inserir(Raiz,criar(valor));
                break;
            case 2:
                printf ("\nInforme o valor para adicionar no fim:\n");
                scanf ("%d", &valor);
                Raiz = deletar(Raiz,(valor));
                imprimir (Raiz);
                break;
            case 3:
                printf ("\nInforme o valor para ser buscado\n");
                scanf ("%d", &valor);
                Node *tmp = arvBusca(Raiz,(valor));
                    if (tmp == NULL)
                        {
                            printf("Nao encotramos\n");
                        }
                    else
                        {
                        printf("Encotramos\n");
                        }
                break;
            case 4:
                libera(Raiz);
                break;
            case 5:
                imprimir (Raiz);
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

