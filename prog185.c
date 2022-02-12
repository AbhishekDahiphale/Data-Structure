#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

 void Display(PNODE Head,PNODE Tail)
   { 
     while (Head!=Tail)
     {
        printf("|%d|->",(Head->data));
        Head=Head->next;
     } 

     printf("|%d|->",(Head->data));
     printf("\n");
   }

  int Count(PNODE Head,PNODE Tail)
   {
       if(Head==NULL)
       {
           return 0;
       }
       else
       {
           int icnt=1;
          while (Head!=Tail)
           {
             icnt++;
             Head=Head->next;
           }
          return icnt;
        } 
   }

void InsertFirst(PPNODE Head,PPNODE Tail,int No)
{
   PNODE newn=(PNODE)malloc(sizeof(NODE));
   newn->data=No;
   newn->next=newn;

   if((*Head)==NULL)
   {
       (*Head)=newn;
       (*Tail)=newn;
   } 
   else
   {
      newn->next=(*Head);
      *Head=newn;
   }
}

void InsertLast(PPNODE Head,PPNODE Tail,int No)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=No;
    newn->next=NULL;

    if((*Head)==NULL)
    {
        *Head=newn;
        *Tail=newn;
    }
    else
    {
        (*Tail)->next=newn;
        newn->next=(*Head);
        (*Tail)=newn;
    }
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int No,int pos)
{
  int size=Count(*Head,*Tail);

  if((pos < 1) || (pos > (size+1)))
  {
      return;
  }

  if(pos==1)
  {
      InsertFirst(Head,Tail,No);
  }
  else if(pos==(size+1))
   {
       InsertLast(Head,Tail,No);
   }   
   else
   {
       PNODE temp=(*Head);
       int i=1;
       PNODE newn=(PNODE)malloc(sizeof(NODE));
       newn->data=No;
       newn->next=NULL;
        
       while(i!=(pos-1))
       {
           i++;
           temp=temp->next;
       }
       newn->next=temp->next;
       temp->next=newn;       
 
   }
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
    if((*Head)!=NULL)
    {
        if((*Head)->next==NULL)
        {
            free((*Head));
            *Head=NULL;
            *Tail=NULL;
        }
        else
        {
            (*Head)=(*Head)->next;
            free((*Tail)->next);
            (*Tail)->next=(*Head);
        }
    }

}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
   if((*Head)!=NULL)
   {
       if((*Head)->next==NULL)
       {
           free(*Head);
           *Head=NULL;
           *Tail=NULL;
       }
       else
       {
           PNODE temp=(*Head);

           while((temp->next->next)!=(*Head))
           {
               temp=temp->next;
           }
           temp->next=(*Head);
           free(*Tail);
           (*Tail)=temp;
       }
   }
}


void DeleteAtPos(PPNODE Head,PPNODE Tail,int pos)
{
   int size=Count(*Head,*Tail);

   if((pos < 1) || (pos > size))
   {
       return;
   }

   if(pos==1)
   {
       DeleteFirst(Head,Tail);
   }
   else if(pos==size)
   {
       DeleteLast(Head,Tail);
   }
   else
   {
       PNODE temp=(*Head);
       PNODE target=NULL;
       int i=1;
       while(i!=(pos-1))
       {
           i++;
           temp=temp->next;
       }
       target=temp->next;
       temp->next=target->next;
       free(target);

   }
}

int main()
{
   PNODE first=NULL;
   PNODE last=NULL;
   int iRet=0;

   InsertFirst(&first,&last,51);
   InsertFirst(&first,&last,21);   
   InsertFirst(&first,&last,11);
   Display(first,last);
   
   InsertAtPos(&first,&last,31,3);
    Display(first,last);

   DeleteAtPos(&first,&last,3);
   Display(first,last);
   
    iRet=Count(first,last);
   printf("NUmber of nodes are : %d\n",iRet);

   InsertLast(&first,&last,101);
   Display(first,last);

   DeleteFirst(&first,&last);
   Display(first,last);

    DeleteLast(&first,&last);
   Display(first,last);

   iRet=Count(first,last);
   printf("NUmber of nodes are : %d\n",iRet);

    return 0;
}
