#include <stdio.h>
#include <stdlib.h>

struct item
{
    int cod;
};

typedef struct item Item;

struct node
{
    Item item;
    struct node *left;
    struct node *right;
    
};

typedef node Node;
