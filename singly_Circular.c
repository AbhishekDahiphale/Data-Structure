#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

 void Display(PNODE Head,PNODE Tail)
   { 
      if((Head==NULL) && (Tail==NULL))
      {
          printf("Linked list is empty\n");
      }
      else
      {
           printf("->");
           do
          {
               printf("|%d|->",(Head->data));
               Head=Head->next;
           }  while ((Tail->next)!=Head);
           printf("\n");
      }
   }

  int Count(PNODE Head,PNODE Tail)
   {
       if((Head==NULL) && (Tail==NULL))
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
      (*Tail)->next=newn;
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
         if(((*Head)->next==(*Tail)) && (((*Tail)->next==(*Head))))
        {
            free((*Head));
            *Head=NULL;
            *Tail=NULL;
        }
        else
        {
            PNODE temp=*Head;
            (*Head)=(*Head)->next;
            free(temp);
            (*Tail)->next=(*Head);
        }
    }
    else
    {
        return;
    }


}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
   if((*Head)!=NULL)
   {
       if(((*Head)->next==(*Tail)) && (((*Tail)->next==(*Head))))
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
   else
   {
       return;
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
   int ichoice=1,ivalue,iRet=0,ipos=0;

   while(ichoice!=0)
   {
      printf("\n<------------------------------------------------------->\n");
      printf("0 : Terminate the application\n");
      printf("1 : Insert the node at first position\n");
      printf("2 : Insert the node at last position\n");
      printf("3 : Insert the node at desired position\n");
      printf("4 : Delete the first node \n");
      printf("5 : Delete the last node \n");
      printf("6 : Delete the node at desired position \n");
      printf("7 : Display the linkedlist \n");
      printf("8 : Count the nodes \n"); 
      scanf("%d",&ichoice);
      printf("\n<------------------------------------------------------->\n");

     switch(ichoice)
     {
         case 0 : 
                 printf("Thank You For Using The LinkedList \n");
                 break;

         case 1 :
                 printf("Enter the data to insert in the node\n");
                 scanf("%d",&ivalue);
                 InsertFirst(&first,&last,ivalue);
                 break;       

         case 2 :
                 printf("Enter the data to insert in the node\n");
                 scanf("%d",&ivalue);
                 InsertLast(&first,&last,ivalue);
                 break;    

         case 3 :
                 printf("Enter the data to insert in the node\n");
                 scanf("%d",&ivalue);
                 printf("Enter the Position\n");
                 scanf("%d",&ipos);
                 InsertAtPos(&first,&last,ivalue,ipos);
                 break;                              

         case 4 : 
                 DeleteFirst(&first,&last);
                 break;

         case 5 : 
                 DeleteLast(&first,&last);
                 break;

         case 6 : 
                 printf("Enter the Position\n");
                 scanf("%d",&ipos);
                 DeleteAtPos(&first,&last,ipos);
                 break;                       

         case 7 :
                 Display(first,last);
                 break;

         case 8 : 
                 iRet=Count(first,last);
                 printf("Number of nodes are : %d \n",iRet);
                 break;
 
         default : 
                 printf("wrong choice\n");
                  break;     

        }
    }

    return 0;
}
