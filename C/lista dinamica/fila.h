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
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo ->info = i;
    novo -> prox = l;
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
    
    Lista *t;
        int aux;
        for (t = l; t!=NULL ;t= t->prox)
        {   
            printf ("\n Info %d\n", t->info);
        
    }
    }
}
Lista* BuscaLista (Lista *l, int v)
{   
    if (ListaVazia(l))
        printf("Lista vazia!\n");
    else
    {
    
        Lista *t;
            for (t = l; t!=NULL ;t= t->prox)
            {
                if(t->info == v)
            {        
            printf("\n%d foi encontrado",t->info);
            return t;
        }
    }
        printf("\nElemento nao encontrado\n");
    }
    return NULL;
}

Lista* removeListaPrimeiro(Lista *l)
{
    if (ListaVazia(l))
        printf("\nLista vazia!, não pode ser removido\n");
    else
    {
        Lista *t;
        t=l;
        l = l->prox;
        free(t);
        return l;
    }
}

Lista *removeListaNoMeio (Lista *l, int v)
{
    if (ListaVazia(l))
        printf("\nLista vazia!, não pode ser removido\n");
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

Lista *insereListaOrdenada(Lista *l, int v)
{
    Lista *novo;
    Lista *ant = NULL;
    Lista *p = l;

    while (p != NULL && p->info <v)
    {
        ant=p;
        p = p->prox;
    }
    novo= (Lista*) malloc(sizeof(Lista));
    novo->info = v;
    if (ant == NULL)
    {
        novo->prox = l;
        l=novo;
    }
    else
    {
        novo->prox=ant->prox;
        ant->prox = novo;
    }
    return l;
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

 Lista *novo=aloca();
 novo->prox = NULL;

 if(vazia(LISTA))
  LISTA->prox=novo;
 else{
  Lista *tmp = LISTA->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
  novo->prox=NULL;
 }
}



//---------------------------------------------MENU--------------------------------------------------------------------

int menu_lista (int Resp=0)
    {
        
            
                printf ("\n--Escolha uma opcao:--\n 1- Adicione um elemento no fim.");
                printf ("\n 2- Remover elemento do início.");
                printf ("\n 3- Buscar na lista.");
                printf ("\n 4- Apagar lista.");
                printf ("\n 5- Imprime lista");
                printf ("\n 6- Sair lista.\n");
                scanf ("%d", &Resp);
        
                return Resp;
    }

