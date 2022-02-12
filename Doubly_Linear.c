#include<stdio.h>
#include<stdlib.h>

typedef struct node
{ 
   int data;
   struct node * next;
   struct node *  prev;
}NODE,*PNODE,**PPNODE;

void Display(PNODE Head)
{
   if(Head==NULL)
   {
     printf("Linked list is empty\n");
   }
   else
   {
        while (Head!=NULL)
        {  
           printf("|%d|->",Head->data);
            Head=Head->next;
        }
           printf("NULL\n");
   }
    
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

  if( (pos < 1) || (pos > (size+1)) )
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
     newn->next->prev=newn;
     newn->prev=temp;
     temp->next=newn;
     

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
    if((*Head)->next==NULL)
    {
         free(*Head);
         *Head=NULL;
    }
    else
   {
      *Head=(*Head)->next;
     free(temp);
     if(*Head!=NULL)
     {
        (*Head)->prev=NULL;
     }
   }
  }
  else
  {
    return;
  }
}

////////////////DeleteFirst function not using any temp pointer///////////////////////
void DeleteFirstX(PPNODE Head)
{
  if(*Head==NULL)
  {
    return;
  }
  else if((*Head)->next==NULL)
  {
    free(*Head);
    *Head=NULL;
  }
  else
  {
    *Head=(*Head)->next;
    free((*Head)->prev);
    (*Head)->prev=NULL;
  }
}

void DeleteLast(PPNODE Head)
{
  PNODE temp=*Head;
  if(*Head!=NULL)
  {
    if((*Head)->next==NULL)
    {
      free(*Head);
      *Head=NULL;

    }
    else
    {

      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
      temp->prev->next=NULL;
      free(temp);
      /*
      while (temp->next->next!=NULL)
      {
         temp=temp->next;
      }
      free(temp->next);
      temp->next=NULL;
      */
    }
  }
}


void DeleteAtPos(PPNODE Head,int pos)
{
   int size=Count(*Head);
   int icnt=0;
   PNODE temp=*Head;

   if( (pos < 1) || (pos > size))
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
        temp->next=temp->next->next;
        free(temp->next->prev);
        temp->next->prev=temp;


        /*
        **** using for loop ****

         for(icnt=1;icnt<(pos-1);icnt++)
         {
           temp=temp->next;
         }

          temp->next=temp->next->next;
          free(temp->next->prev);
         temp->next->prev=temp;

      */
       
   }
   
}

int main()
{
    PNODE first=NULL;
    int ichoice=1,ivalue=0,ipos=0,iRet=0;

    while(ichoice!=0)
    {
        printf("\n_____________________________________________\n");
        printf("0 : Terminate the application\n");
        printf("1 : Insert the node at First Position \n");
        printf("2 : Insert the node at last position \n");
        printf("3 : Insert the node at desired position \n");
        printf("4 : Delete the node at position\n");
        printf("5 : Delete the node at last position \n");
        printf("6 : Delete the node at desired position\n");
        printf("7 : Display th linkdelist\n");
        printf("8 : Count the node in the linkedlist\n");
        scanf("%d",&ichoice);
        printf("\n_____________________________________________\n");

      switch(ichoice)
      {
          case 0 : 
                   printf("Thank you for using the linkedlist\n");
                   break;

          case 1 : 
                   printf("enter the data(Number) to insert the in the node\n");
                   scanf("%d",&ivalue);
                   InsertFirst(&first,ivalue);
                   break;
                   
          case 2 : 
                   printf("enter the data(Number) to insert the in the node\n");
                   scanf("%d",&ivalue);
                   InsertLast(&first,ivalue);
                   break; 

          case 3 : 
                   printf("enter the data(Number) to insert the in the node\n");
                   scanf("%d",&ivalue);
                   printf("enter the position \n");
                   scanf("%d",&ipos);
                   InsertAtPos(&first,ivalue,ipos);
                   break;  
          
          case 4 :
                   DeleteFirst(&first);
                   break;

          case 5 :
                   DeleteLast(&first);
                   break;    

          case 6 :
                   printf("enter the position \n");
                   scanf("%d",&ipos);  
                   DeleteAtPos(&first,ipos);
                   break;             

          case 7 : 
                   Display(first);
                   break;

          case 8 : 
                   iRet=Count(first);
                    printf("Number of nodes are : %d \n",iRet);
                    break;  

          default : 
                   printf("Wrong choice\n"); 
                   break;                             
      }
    }
    return 0;
}