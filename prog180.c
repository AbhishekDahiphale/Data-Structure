#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;

}NODE,*PNODE,**PPNODE;



void Display(PNODE Head)
{
   while(Head!=NULL)
   {
     printf("|%d|->",Head->data);
     Head=Head->next;
   }
   printf("NULL\n");
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


void InsertFirst(PPNODE Head,int No)
{
  PNODE newn=NULL;

  newn=(PNODE)malloc(sizeof(NODE));
  newn->data=No;
  newn->next=NULL;
  newn->prev=NULL;

  if(*Head==NULL)
  {
    *Head=newn;
  }
  else
  {
      (*Head)->prev=newn;
      newn->next=*Head;
      *Head=newn;
  }
}

void InsertLast(PPNODE Head,int No)
{
   PNODE newn=NULL;
   PNODE temp=*Head; 
    newn=(PNODE)malloc(sizeof(NODE));
   newn->data=No;
   newn->next=NULL;
   newn->prev=NULL;

   if(*Head==NULL)
   {
     *Head=newn;
   } 
   else
   {
      while (temp->next!=NULL)
      {
         temp=temp->next;
      }
      temp->next=newn;
      newn->prev=temp;
   }
}

void InsertAtPos(PPNODE Head , int No,int pos)
{
  int size=Count(*Head);
  int icnt=0;
  PNODE newn=NULL;
  PNODE temp=*Head;

  if( (pos < 1) || (pos > (pos+1)) )
  {
    return;
  }

  if(pos==1)
  {
    InsertFirst(Head,No);
  }
  else if(pos==(size+1))
  {
    InsertLast(Head,No);
  }
  else
  {
     newn=(PNODE)malloc(sizeof(NODE));
     newn->data=No;
     newn->next=NULL;
     newn->prev=NULL;

     icnt=1;
     while (icnt!=(pos-1))
     {
         icnt++;      
         temp=temp->next;
     }
     newn->next=temp->next;
     newn->prev=temp;
     temp->next=newn;
     newn->next->prev=newn;

     /*
       ** using for loop ** 

         for(icnt=1;icnt<(pos-1);icnt++)
         {
           temp=temp->next;
         }
         newn->next=temp->next;
     newn->prev=temp;
     temp->next=newn;
     newn->next->prev=newn;

     */
   
  }
}

void DeleteFirst(PPNODE Head)
{
  PNODE temp=NULL;
  if(*Head!=NULL)
  {
    *Head=(*Head)->next;
    (*Head)->prev=NULL;
     free(temp);
  }
}

void DeleteLast(PPNODE Head)
{
  PNODE temp=*Head;
  if(*Head!=NULL)
  {
    if(temp->next==NULL)
    {
      *Head=NULL;
      free(temp);
    }
    else
    {
      while (temp->next->next!=NULL)
      {
         temp=temp->next;
      }
      free(temp->next);
      temp->next=NULL;

    }
  }
}

void DeleteAtPos(PPNODE Head,int pos)
{
   int size=Count(*Head);
   int icnt=0;
   PNODE temp=*Head;
   PNODE target=NULL;

   if( (pos < 1) || (pos > (size+1)))
   {
     return;
   }

   if(pos==1)
   {
     DeleteFirst(Head);
   }
   else if (pos==size)
   {
      DeleteLast(Head);
   }
   else
   { 
     icnt=1;
       while (icnt!=(pos-1))
       {
          icnt++;
          temp=temp->next;
       }
       target=temp->next;
       temp->next=target->next;
       target->next->prev=temp;
       free(target);


        /*
        **** using for loop ****

         for(icnt=1;icnt<(pos-1);icnt++)
         {
           temp=temp->next;
         }

          target=temp->next;
       temp->next=target->next;
       target->next->prev=temp;
       free(target);

      */
       
   }
   
}

int main()
{
  PNODE first=NULL;
  int iRet=0;
  
  // InsertFirst(&first,40);
  InsertFirst(&first,30);
  InsertFirst(&first,20);
  InsertFirst(&first,10);

  Display(first);
 iRet = Count(first);
  printf("Number of nodes are : %d\n",iRet);

  InsertLast(&first,40);
  Display(first);
   
 InsertAtPos(&first,25,3);
  Display(first);
 iRet = Count(first);
  printf("Number of nodes are : %d\n",iRet);

  DeleteAtPos(&first,3);
    Display(first);
 iRet = Count(first);
  printf("Number of nodes are : %d\n",iRet);


 DeleteFirst(&first);
  Display(first);

  DeleteLast(&first);
  Display(first);

 

  return 0;
}