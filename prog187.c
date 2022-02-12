#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}NODE,*PNODE,**PPNODE;

void Display(PNODE Head,PNODE Tail)
{
    printf("-> ");
    while(Head!=Tail)
    {
        printf(" <-|%d|-> ",Head->data);
        Head=Head->next;
    }
      printf(" <-|%d|-> \n",Head->data);    
}

int Count(PNODE Head ,PNODE Tail)
{ 
   if(Head==NULL)
   {
       return 0;
   }
   else
   {
       int icnt=1;
       while(Head!=Tail)
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
    newn->next=NULL;
    newn->prev=NULL;

    if((*Head)==NULL)
    {
        *Head=newn;
        *Tail=newn;
    }
    else
    {
        newn->next=(*Head);
        newn->next->prev=newn;
        *Head=newn;
        newn->prev=(*Tail);
        (*Tail)->next=newn;
    }

}

void InsertLast(PPNODE Head,PPNODE Tail,int No)
{
     PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;

    if((*Head)==NULL)
    {
        *Head=newn;
        *Tail=newn;
    }
    else
    {
        newn->prev=(*Tail);
        (*Tail)->next=newn;
        (*Head)->prev=newn;
        newn->next=(*Head);
        (*Tail)=newn;
    }

}

void InsertAtPos(PPNODE Head,PPNODE Tail,int No,int pos)
{
    int size=Count(*Head,*Tail);

    if((pos < 1)|| (pos > (size+1)))
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
         newn->prev=NULL;

         while(i!=(pos-1))
         {
            i++;
            temp=temp->next;
         }
         newn->next=temp->next;
         temp->next->prev=newn;
         temp->next=newn;
         newn->prev=temp;
    }
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
    if((*Head)!=NULL)
    {
        if((*Head)->next==(*Head))
        {
            free(*Head);
            *Head=NULL;
            *Tail=NULL;
        }
        else
        {
            (*Head)=(*Head)->next;
            free((*Head)->prev);
            (*Head)->prev=(*Tail);
            (*Tail)->next=(*Head);
        }
    }
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
     if((*Head)!=NULL)
    {
        if((*Head)->next==(*Head))
        {
            free(*Head);
            *Head=NULL;
            *Tail=NULL;
        }
        else
        {
            (*Tail)=(*Tail)->prev;
            (*Tail)->next=(*Head);
            free((*Head)->prev);
            (*Head)->prev=(*Tail);
        }
    }
}

void DeleteAtPos(PPNODE Head,PPNODE Tail,int pos)
{
     int size=Count(*Head,*Tail);

     if((pos < 1)|| (pos > size))
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
        int i=1;

        while(i!=(pos-1))
        {
          i++;
          temp=temp->next;
        }
        temp->next=temp->next->next;
        free(temp->next->prev);
        temp->next->prev=temp;          
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
    iRet=Count(first,last);
    printf("Number of nodes are : %d\n",iRet);

    InsertLast(&first,&last,101);
    Display(first,last);
    iRet=Count(first,last);
    printf("Number of nodes are : %d\n",iRet);

    InsertAtPos(&first,&last,31,3);
    Display(first,last);
    iRet=Count(first,last);
    printf("Number of nodes are : %d\n",iRet);

     DeleteAtPos(&first,&last,3);
    Display(first,last);
    iRet=Count(first,last);
    printf("Number of nodes are : %d\n",iRet);


    DeleteFirst(&first,&last);
    Display(first,last);
    iRet=Count(first,last);
    printf("Number of nodes are : %d\n",iRet);

    DeleteLast(&first,&last);
    Display(first,last);
    iRet=Count(first,last);
    printf("Number of nodes are : %d\n",iRet);


    
    return 0;
}