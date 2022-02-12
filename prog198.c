#include<stdio.h>
#include<stdlib.h>


typedef struct node 
{
  int data;
  struct node * next;
}NODE,* PNODE,** PPNODE;

void Display(PNODE Head)
{
    if((Head)!=NULL)
    {
         while(Head!=NULL)
          {
             printf("<-|%d|",Head->data);
              Head=Head->next;
         }

              printf("\n");

    }
    else
    {
        return;
    } 
}

int Count(PNODE Head)
{
     if((Head)!=NULL)
    {
         int icnt=0;
         while(Head!=NULL)
         {
           icnt++;
           Head=Head->next;
     }
         return icnt;
    }
    else
    {
        return 0;
    }
  
}

void EnQueue(PPNODE Head,int No)
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

int DQueue(PPNODE Head)
{
    PNODE temp=*Head;
    int idata=0;
     if(*Head!=NULL) 
     {
        if((*Head)->next==NULL) 
        {
            idata=((*Head)->data);
            free(*Head);
            *Head=NULL;
        }
        else
        {
          *Head=(*Head)->next;
          idata=(temp->data);
           free(temp);
        }
        return idata;
     }
     else
     {
         return -1;
     }
}

int main()
{
    PNODE first=NULL;
    int ichoice=1,ivalue=0,iRet=0;
   
    while(ichoice!=0)
    {   
        printf("---- Choose the operation perform of Queue ----");
        printf("\n-----------------------------------------------------\n");
        printf("0 : Terminate the application\n");
        printf("1 : Insert the element in Queue \n");
        printf("2 : Delete the element in Queue \n");
        printf("3 : Display the all element int Queue \n");
        printf("4 : Count the all the numbers present in the Queue\n");
        printf("\n-----------------------------------------------------\n");
        scanf("%d",&ichoice);
        printf("\n-----------------------------------------------------\n");


        switch(ichoice)
        {
            case 0 : 
                    printf("Thank You For Using Queue\n");
                    break;

            case 1 : 
                     printf("enter the number which are insert int the Queue\n");
                     scanf("%d",&ivalue);
                     EnQueue(&first,ivalue);
                     break;

            case 2 : 
                     iRet=DQueue(&first);
                     if(iRet!=(-1))
                     {
                       printf("poped element from Queue : %d\n",iRet);
                     }
                     else
                     {
                         printf("Queue is empty\n");
                     }
                     
                     break; 

            case 3 : 
                     Display(first); 
                     break;

            case 4 :
                     iRet =Count(first);
                     printf("Number of elemets in the Queue : %d\n",iRet);
                     break;

            default : 
                     printf("Wrong choice\n");
                     break;                

        }
    }
   return 0;
}