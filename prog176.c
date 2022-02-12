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
   PPNODE q=NULL;
 
   First=(PNODE) malloc(sizeof(NODE));
   q=&First;

    return 0;
}