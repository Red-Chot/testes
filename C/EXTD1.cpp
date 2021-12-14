#include <stdio.h>
#include <conio.h>

    /*
    -erros-

    LISTACHEIA  = -1
    LISTAVAZIA  = -2
    ERROPOSIÇÃO = -3

    */
    #define maxlista 100
    #define ErroListaCheia -1
    #define ErroListaVazia -2
    #define ErroPosicao -3
    #define Verdadeiro -4
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
    //-----------------------------------------MAIN-------------------------------------------------
    int main (){
        inicializaLista ();
        adicionaLista (20);
        
        destroiLista ();

        destroiLista();
        return 0;
    }



// 1:37m