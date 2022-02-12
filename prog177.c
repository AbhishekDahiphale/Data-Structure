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
   PNODE first=NULL;

   //call by value
   fun(first);  //fun(100)

  //call by address
   gun(&first);  //gun(50)

    return 0;
}