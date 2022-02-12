#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
  int data;
  struct node * next;
}NODE,* PNODE,** PPNODE;

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

void Insertfirst(PPNODE Head,int No)
{
  PNODE newn=NULL;

  newn= (PNODE)malloc(sizeof(NODE));

  newn->data=No;
  newn->next=NULL;

  if(*Head==NULL)
  { 
     *Head=newn;  
  }
  else
  {
    newn->next=*Head;
    *Head=newn;
  }

}

void InserLast(PPNODE Head,int No)
{
  PNODE newn=NULL;
  PNODE temp=*Head;
  newn= (PNODE)malloc(sizeof(NODE));

  newn->data=No;
  newn->next=NULL;

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
  
  }
    
 }



void InsertAtPos(PPNODE Head,int No,int pos)
{
  PNODE newn=NULL;
  PNODE temp=*Head;
  int i=1;
  int Cnt=Count(*Head);
  if( (pos < 1) || ( pos > (Cnt +1)))    //filter
  {
    return; 
  }
  if(pos==(Cnt+1))  //if position (cnt+1)
  {
    InserLast(Head,No);
  }
  else if(pos==1)   //if position is 1
  {
    Insertfirst(Head,No);
  }
  else
  {
   newn= (PNODE)malloc(sizeof(NODE));
   newn->data=No;
   newn->next=NULL;

     while(i!=(pos-1))
     {
       i++;
       temp=temp->next;
     }
     newn->next=temp->next;
     temp->next=newn;


     /* 
        ****using for loop****

       for(i=1;i < pos-1;i++)
       {
         temp=temp->next;
       }
     newn->next=temp->next;
     temp->next=newn;

     */
   
  }
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

void DeleteAtPos(PPNODE Head,int pos)
{
  int size=Count(*Head);
  PNODE temp=*Head;
  PNODE target=NULL;
  int i=1;
  if( (pos < 1) || (pos > (size+1)) )
  {
    return;
  }

  if(pos==1)
  {
    DeleteFirst(Head);
  }
  else if(pos==size)
  {
    DeleteLast(Head);
  }
  else
  {
     while (i!=(pos-1))
     {
         i++;
         temp=temp->next;
     }
     target=temp->next;
     temp->next=target->next;
     free(target);
     

     /*
       ***using for loop**
       for(i=1;i<(pos-1);i++)
       {
         temp=temp->next;
       }
       target=temp->next;
       temp->next=target->next;
       free(target);
     */
     
  }

}


int main()
{
  PNODE first=NULL;
  int ichoice=1,value=0,iRet=0,ipos=0;
  
  while(ichoice!=0)
  {
    printf("\n_______________________________________________\n");
    printf("Enter the desired operation that we want to perform on linkedlist\n");
    printf("0 : Terminate the application\n");
    printf("1 : Insert the node at first position\n");
    printf("2 : Insert the node at last position\n");
    printf("3 : Insert at Desired position \n");
    printf("4 : Delete the first node\n");
    printf("5 : Delete the last node\n");
    printf("6 : Delete node at the desired position \n");
    printf("7 : Display the linked list\n");
    printf("8 : Count the node\n");
    scanf("%d",&ichoice);
    printf("\n_______________________________________________\n");
  

  switch(ichoice)
  {
    case 0 :
            printf("thnk you for using linked list");
            break;

    case 1 :
          printf("enter the data to insert\n");
          scanf("%d",&value);
          Insertfirst(&first,value);
          break;

    case 2 :
          printf("enter the data to insert\n");
          scanf("%d",&value);
          InserLast(&first,value);
          break;   
          
    case 3 :
          printf("enter the data to insert\n");
          scanf("%d",&value);
          printf("enter the Position\n");
          scanf("%d",&ipos);
          InsertAtPos(&first,value,ipos);
          break;                 

    case 4 :
            DeleteFirst(&first);
            break;

    case 5 :
            DeleteLast(&first);
            break;    

    case 6 :
             printf("enter the position\n");
             scanf("%d",&ipos);
            DeleteAtPos(&first,ipos);
            break;       

    case 7 :
           printf("Elemenets of Linkedlist");
           Display(first);
           break;

    case 8 :
           iRet=Count(first);
           printf("Number of elements int the linked lis are : %d",iRet); 
           break;

    default :
           printf("wrong choice");
           break;                                        
  }
  
 }
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
