#include <stdio.h>
#include <conio.h>

    /*
    -erros-

    LISTACHEIA  = -1
    LISTAVAZIA  = -2
    ERROPOSIÇÃO = -3

    */
    #define maxlista 8
    #define ErroListaCheia -2
    #define ErroListaVazia -3
    #define ErroPosicao -4
    #define Verdadeiro -5
    #define Falso 0
    listaInteiros aLista;

   typedef struct Lista {
       int dados[maxlista];
       int ultimo;
   } listaInteiros;
    
    //--------------------------------------FUNÇOES--------------------------------------------------

    void inicializaLista () {
        aLista.ultimo = -1;
    }
    
    void destroiLista ()
    {
        aLista.ultimo = -1;
    }

    int listaCheia ()
    {
        if (aLista.ultimo == maxlista - 1 )
            return Verdadeiro;
        else
            return Falso;
    }

    int listaVazia ()
    {
        if (aLista.ultimo == - 1 )
            return Verdadeiro;
        else
            return Falso;
    }

    int adicionaLista (int add)
    {
        if (listaCheia () == Verdadeiro)
            return ErroListaCheia;
        else
        {
            aLista.ultimo++;
            aLista.dados[aLista.ultimo] = add;
            return aLista.ultimo;

             if (adicionaLista (20)>=0)
                printf ("\n elemento adicionado");
            else
                printf ("\n elemento nao adicionado");
        }
    }

      int adicionaListanoInicio (int add)
    {
        if (listaCheia () == Verdadeiro)
            return ErroListaCheia;
        else
        {
            int cont;
            aLista.ultimo++;
            for(cont = aLista.ultimo; cont >0; cont --)
            {
                aLista.dados[cont] = aLista.dados[cont-1];
            }
            aLista.dados[cont] = add;
            return aLista.ultimo;
        }
    }

     int adicionaListaNaPosicao (int add, int posicao)
    {
        if (listaCheia () == Verdadeiro)
            return ErroListaCheia;
        else
        {
            int cont;
            if (posicao < 0 || posicao > aLista.ultimo)
                return ErroPosicao;
                else{
                     aLista.ultimo++;
                    for(cont = aLista.ultimo; cont > posicao; cont --)
                    {
                    aLista.dados[cont] = aLista.dados[cont-1];
                    }
                    aLista.dados[posicao] = add;
                    return aLista.ultimo;
            }
        }
    }

    int retiraLista ()
    {
        if(listaVazia()== Verdadeiro)
            return ErroListaVazia;
        else{
            aLista.ultimo--;
            return aLista.ultimo;
        }
    }

     int retiraListaNoInicio ()
    {
        if(listaVazia()== Verdadeiro)
            return ErroListaVazia;
        else{
            aLista.ultimo--;
            for(int cont = 0; cont <=aLista.ultimo; cont++)
            {
                aLista.dados[cont] = aLista.dados [cont+1];
            }
            return aLista.ultimo;
        }
    }

    int retiraListaNaPosicao (int posicao)
    {
        if(listaVazia()== Verdadeiro)
            return ErroListaVazia;
        else{
            int cont;
            if (posicao < 0 || posicao > aLista.ultimo)
                return ErroPosicao;
                else{
                    aLista.ultimo--;
                    for(int cont = posicao; cont <=aLista.ultimo; cont++)
                    {
                        aLista.dados[cont] = aLista.dados [cont+1];
                    }
            return aLista.ultimo;
                }
        }
    }


    void mostraLista ()
    {
        if(listaVazia () == Verdadeiro)
            printf("\nLista vazia");
        
        else{
            int cont;
            for (cont=0;cont<=aLista.ultimo;cont++)
            {
                printf ("\n aLista [%d]",cont, aLista.dados [cont]);
            }
        }
    }

    //-----------------------------------------MAIN-------------------------------------------------
    int main (){
        int pos;

        inicializaLista ();
        mostraLista ();
        

        destroiLista();
        return 0;
    }
//1:32


// 0:45 29nov