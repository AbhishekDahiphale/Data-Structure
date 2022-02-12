#include<stdio.h>
#include<stdlib.h>

struct node
{
    int Data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head,int No)
{
  PNODE newn=NULL;

  newn=(PNODE)malloc(sizeof(NODE));  //allocate the memory
 
 //intialise the node
  newn->Data=No; 
  newn->next=NULL;  

  //insert the node.
  if((*Head)==NULL)  //LL is empty
   {
      *Head=newn;
  }
  else  //LL contains atleast one node
  {
    newn->next=*Head;
    *Head=newn;
  }

}

void InsertLast(PPNODE Head,int No)
{
  PNODE newn=NULL,temp=NULL;
   
  newn=(PNODE)malloc(sizeof(NODE));  //allocate the memory
 
 //intialise the node
  newn->Data=No; 
  newn->next=NULL;  

  //insert the node
  if(*Head==NULL)  //LL is empty
  {
    *Head=newn;
  }
  else   //LL contains atleast one node
  {
      temp=*Head;
    while((temp->next)!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newn;
  }
  
}

void Display(PNODE Head)
{
  
    while (Head!=NULL)
    {
        printf("%d\t",(Head->Data));
        Head=Head->next;
    }
    printf("\n");
}

int Count(PNODE Head)
{
    int icnt=0;
    while(Head!=NULL)
    {
        icnt++;
        Head=Head->next;
    }
    return icnt;
}

void DeleteFirst(PPNODE Head)
{
    PNODE temp=*Head;
     if(*Head!=NULL) // if LL contains atleast one node
     {
        *Head=(*Head)->next;
        free(temp);
     }
     
}

void DeleteLast(PPNODE Head)
{
    PNODE temp=*Head;
    if(*Head!=NULL)  // if LL contains atleast one node
    {
        if((*Head)->next==NULL) 
        {
            free(*Head);
            *Head=NULL;
        }
        else
        {
            while((temp->next->next)!=NULL)
           {
             temp=temp->next;
           }
           free(temp->next);
           temp->next=NULL;
        }
        
    }
}

int main()
{
  PNODE first=NULL;
  int iRet=0;

  InsertFirst(&first,101);  
  InsertFirst(&first,51);  
  InsertFirst(&first,21);
  InsertFirst(&first,11);

  InsertLast(&first,111);

  Display(first);

  iRet=Count(first);
  printf("number of nodes are : %d\n",iRet);

  
  DeleteFirst(&first);
  printf("after the delete first node \n");
   Display(first);

  iRet=Count(first);
  printf("number of nodes are : %d\n",iRet);

  DeleteLast(&first);
  printf("after the delete Last node \n");
   Display(first);

  iRet=Count(first);
  printf("number of nodes are : %d\n",iRet);


  return 0;
}

/*
 void InsertFirst(PPNODE Head , int No);
 void InsertLast(PPNODE Head , int No);
 void InsertAtPos(PPNODE Head , int No , int Pos);

 void DeleteFirst(PPNODE Head );
 void DeleteLast(PPNODE Head );
 void DeleteAtPos(PPNODE Head , int Pos);

 void Display(PNODE Head);
 int Count(PNODE Head);
*/
