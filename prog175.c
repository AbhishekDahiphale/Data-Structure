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
    NODE obj;
   obj.Data=11;
   obj.Next=NULL;

   PNODE First=NULL;     //struct Node * First=NULL;
   First=&obj;

  PPNODE q=NULL;
  q=&First;

    return 0;
}