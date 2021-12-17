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

     int posicaoNaLista (int dado)
    {
        if(listaVazia () == Verdadeiro)
            return ErroListaVazia;
        
        else{
            
            for (int cont=0;cont<=aLista.ultimo;cont++)
            {
                if(aLista.dados[cont] == dado)
                    return cont;
            }
            return ErroPosicao;
        }
    }

    int retiraListaEspecifico (int dado)
    {
        int resp;
        resp = posicaoNaLista(dado);
            if (resp <0)
                return resp;
            else
                {
                    resp = retiraListaNaPosicao (resp);
                    return resp;
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

    int contemNaLista (int dado)
    {
        if(listaVazia () == Verdadeiro)
            return ErroListaVazia;
        
        else{
            
            for (int cont=0;cont<=aLista.ultimo;cont++)
            {
                if(aLista.dados[cont] == dado)
                    return Verdadeiro;
            }
            return Falso;
        }
    }

    //-----------------------------------------MAIN-------------------------------------------------
    int main (){
        int num, resp, pos;
        char voltar= 's';
        inicializaLista ();
        mostraLista ();
    while (voltar == 's' || voltar == 'S')
    {
        /*resp=adicionaLista(58);
        if (resp>= 0)
            printf ("\nElemento adicionado");
        else if (resp== -2)
            printf ("\nA lista esta cheia, elemento  nao adicionado");
        else
            printf ("\nElemento nao adicionado");
        mostraLista();

        printf ("\nQual valor quer adicionar??");
        scanf("%d", &num);
        if(adicionaLista(num)>=0)
            printf("\nElemento %d nao adicionado!",num);
        else
            printf("\nElemenro nao adicionado");
        mostraLista ();

        printf("\nQual valor deseja adicionar?");
        scanf ("%d", &num);
    printf("Em qual posição deseja add",num);
    scanf("%d",pos);
    resp=adicionaListaNaPosicao(num,pos);
    if(resp>=0)
        printf("\nElemento %d adicionado na posição %d", num,pos);
    else if (resp == -2)
        printf("\nA lista esta cheia");
    else if (resp == -4)
        printf ("\n a posiçaõ nao existe %d",pos);
    else
        printf("Elemento nao adicionado");
    mostraLista ();

    printf ("\nQual valor quer remover??");
        scanf("%d", &num);
        resp = retiraListaEspecifico (num);
          if (resp>=-1)
            printf("Elemento %d removido",num);
        else if (resp == -3)
            printf("\n a lista esta vazia");
        else if(resp == -4)
            printf("A posição nao existe");
        else
            printf("\n elemento nao removido");
        mostraLista ();

        printf("\n Qual elemento ");

        printf("\nEm qual posiçao deseja remover?");
        scanf("%d", &pos);
        resp = retiraListaNaPosicao (pos);
        if (resp>=-1)
            printf("Elemento removido");
        else if (resp == -3)
            printf("\n a lista esta vazia");
        else if(resp == -4)
            printf("A posição nao existe");
        else
            printf("\n elemento nao removido");*/
        adicionaListanoInicio (5);
        adicionaLista (6);
        retiraListaEspecifico (5);
        retiraListaNaPosicao (2);
        retiraListaNoInicio ();
        retiraLista ();
        adicionaListaNaPosicao(1,5);
        contemNaLista(6);
        mostraLista ();

     }
    }
  

    
//1:32


// 0:45 29nov   https://www.youtube.com/watch?v=tM7EByVc_lk