#include<stdio.h>
#include<stdlib.h>

struct Node    //self referencial structure
{
    int Data;
    struct Node *Next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;


int main()
{
   PNODE First=NULL;     //struct Node * First=NULL;
   

    return 0;
}