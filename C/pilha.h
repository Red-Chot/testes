#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct lista
{
    int info; 
    struct lista *prox;
} Lista;



Lista* criaLista(){
    return NULL;
}

Lista* insereListaInicio(Lista *l, int i) {
    Lista *aux;
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo ->info = i;
    novo->prox = l;
    if(l==NULL)
        novo->prox=novo;
    
    else
    {
        aux =l;
        do{
            aux=aux->prox;
        }while (aux->prox != l);
        aux->prox = novo;
    }   

    return novo;
}


int ListaVazia(Lista *l)
{
    return (l== NULL);
}

void imprimeLista (Lista *l)
{   
    if (ListaVazia(l))
    printf("\nLista vazia!\n");
    else
    {
    
    Lista *t = l;
        do
        {
            printf ("\n Info %d\n", t->info);
            t=t->prox;
        }while(t != l);
    }
    
}

Lista* BuscaLista (Lista *l, int v)
{   
    if (ListaVazia(l))
        printf("Lista vazia!\n");
    else
    {
    
        Lista *t = l;
            do
            {
                if(t->info == v)
                {        
                    printf("\n%d foi encontrado",t->info);
                    return t;
                }
                t=t->prox;
            }while(t != l);
    }
        printf("\nElemento nao encontrado\n");
    return NULL;
}

Lista* removeListaPrimeiro(Lista *l)
{
    if (ListaVazia(l))
        printf("\nPilha vazia!, não pode ser removido\n");
    else
    {
        Lista *t, *aux ;
        aux = l;
        do{
            aux=aux->prox;
        }while (aux->prox != l);
        t=l;
        aux->prox = t->prox;
        l = l->prox;
        free(t);
        return l;
    }
}

Lista *removeListaNoMeio (Lista *l, int v)
{
    if (ListaVazia(l))
        printf("\nPilha vazia!, não pode ser removido\n");
    else
    {
        Lista *ant = NULL;
        Lista *t = l;
        while (t != NULL && t->info !=v)
        {
            ant = t;
            t = t->prox;
        }
        if (t == NULL)          //NAO EXISTE
        {
            printf ("\nNão encontrado %d\n", v);
            return l;
        }
        else
        {  
            if(ant == NULL)     //PRIMEIRO
            {
                l = t->prox;
                printf("\nelemento removido %d\n",v);
            }
            else                //MEIO
            {
                ant->prox = t->prox;
                printf("\nelemento removido %d\n",v);
            }
            free (t);
            return l;
        }

    }
}

void liberaLista(Lista *l)
{
    Lista *t = l, *p;
    while (t != NULL)
    {
        p = t->prox;
        free (t);
        t = p;
    }
    
}

int vazia(Lista *LISTA)
{
 if(LISTA->prox == NULL)
  return 1;
 else
  return 0;
}


Lista *aloca()
{
    int num = 0;
 Lista *novo=(Lista *) malloc(sizeof(Lista));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  printf("Novo elemento: "); scanf("%d", &novo->info);
  return novo;
 }
}


void insereFim(Lista *LISTA)
{
 Lista *aux;
 aux = LISTA;
 Lista *novo=aloca();
 novo->prox = aux;

 if(vazia(LISTA))
  LISTA->prox=novo;
 else{
  Lista *tmp = LISTA->prox;

  while(tmp->prox != aux)
   tmp = tmp->prox;

  tmp->prox = novo;
  novo->prox=aux;
 }
}



//---------------------------------------------MENU--------------------------------------------------------------------

int menu_lista (int Resp=0)
    {
        
            
                printf ("\n--Escolha uma opção:--\n 1- Adicione um elemento no início.");
                printf ("\n 2- Adicione um elemento no fim.");
                printf ("\n 3- Remover elemento do início.");
                printf ("\n 4- Remover elemento do meio.");
                printf ("\n 5- Buscar na pilha.");
                printf ("\n 6- Apagar pilha.");
                printf ("\n 7- Imprime pilha");
                printf ("\n 8- Sair da pilha.\n");
                scanf ("%d", &Resp);
        
                return Resp;
    }

