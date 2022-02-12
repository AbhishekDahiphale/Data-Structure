#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
  int data;
  struct node *right;
  struct node *left;
}NODE,*PNODE,**PPNODE;


void Insert(PPNODE Head,int No)
{ 
   PNODE newn = (PNODE)malloc(sizeof(NODE));
   newn->data=No;
   newn->left=NULL;
   newn->right=NULL;

   if((*Head)==NULL)
   {
      (*Head)=newn;
   } 
   else 
   {
      PNODE temp=*Head;
      while(1)   //unconditional loop
       {
         if(temp->data==No)
          {
             free(newn);
             break;
          }
         else if(No > (temp->data))   //motha data
          {
              if(temp->right==NULL)
              {
                 temp->right=newn;
                 break;
              }
              temp=temp->right;
          }
          else if (No < (temp->data))  //lahan datat
          {
               if(temp->left==NULL)
              {
                 temp->left=newn;
                 break;
              }
              temp=temp->left;
          }
       }
   }

}

///  With flag ////

bool SearchFlag(PNODE Head,int No)
{
   if((Head)!=NULL)
   {
       bool flag=false;
       while(Head!=NULL)
       {
         if(No == (Head->data))
         {
            flag=true;
            break;
         }
         else if(No > (Head->data))
         {
             Head=Head->right;
         }
         else if(No < (Head->data))
         {
             Head=Head->left;
         }
       }
       return flag; 
   }
   else
   {
     return false;
   }

}

/// Without flag ///
bool Search(PNODE Head,int No)
{
   if((Head)!=NULL)
   {
       while(Head!=NULL)
       {
         if(No == (Head->data))
         {
            break;
         }
         else if(No > (Head->data))
         {
             Head=Head->right;
         }
         else if(No < (Head->data))
         {
             Head=Head->left;
         }
       }
       
       if(Head==NULL)
       {
          return false;
       }
       else
       {
         return true;
       }
   }
   else
   {
     return false;
   }

}

int GFfrequency(PNODE Head,int No)
{
  if(Head!=NULL)
  {
    static int icnt=0;
    if(Head!=NULL)
    {
       if(No <= (Head->data) )
       {
           icnt++;
       }
           GFfrequency(Head->right,No); 
           GFfrequency(Head->left,No);    
     }
    return icnt;
  }
  else
  {
    return -1;
  }

}

int Count(PNODE Head)
{
  if(Head!=NULL)
  {
    static int icnt=0;
    if(Head!=NULL)
    {
      icnt++;
      Count(Head->right);
      Count(Head->left);
    }
    return icnt;
  }
  else
  {
    return -1;
  }
}

int CountLeaf(PNODE Head)
{
  if(Head!=NULL)
  {
    static int icnt=0;
    if(Head!=NULL)
    {
      if(((Head->left)==NULL)  && ((Head->right)==NULL))
      {
          icnt++;
      }
      
      CountLeaf(Head->right);
      CountLeaf(Head->left);
    }
    return icnt;
  }
  else
  {
    return -1;
  }
}


int CountParent(PNODE Head)
{
  if(Head!=NULL)
  {
    static int icnt=0;
    if(Head!=NULL)
    {
      if(((Head->left)!=NULL)  || ((Head->right)!=NULL))
      {
          icnt++;
      }
      
      CountParent(Head->right);
      CountParent(Head->left);
    }
    return icnt;
  }
  else
  {
    return -1;
  }
}

void preorder(PNODE Head) //DLR
{
  if(Head!=NULL)
  {
    if(Head!=NULL)
    {
      printf("%d\t",Head->data); 
      preorder(Head->left);
      preorder(Head->right);
      
    }
   
  }
  else
  {
    return;
  }
   
}

void inorder(PNODE Head)  //LDR
{
  if(Head!=NULL)
  {
    if(Head!=NULL)
    { 
      inorder(Head->left); 
      printf("%d\t",Head->data);
      inorder(Head->right);
      
    }
   
  }
  else
  {
    return;
  }
   
}

void postorder(PNODE Head) //LRD
{
  if(Head!=NULL)
  {
    if(Head!=NULL)
    { 
      postorder(Head->left);
      postorder(Head->right);
      printf("%d\t",Head->data);
    }
     
  }
  else
  {
    return;
  }
   
}



int main()
{
     PNODE first=NULL;
     int ivalue=0,iRet=0;
     bool bRet=false;  

     Insert(&first,51);
     Insert(&first,21);
     Insert(&first,101);
     Insert(&first,75);
     Insert(&first,76);
     Insert(&first,77);
     
     printf("\n");
     printf("Preorder : \t");
     preorder(first);
     printf("\n");
     printf("inorder : \t");
     inorder(first);
     printf("\n");
     printf("postorder : \t");
     postorder(first);
     printf("\n");

     iRet=CountParent(first);
     printf("Number parent nodes are : %d\n",iRet);

     iRet=CountLeaf(first);
     printf("Number of Leaf nodes are : %d\n",iRet);

     iRet=CountParent(first);
     printf("Number of nodes are : %d\n",iRet);

     printf("Greater frequency\n");
     scanf("%d",&ivalue);

     iRet=GFfrequency(first,ivalue);
     printf("frequency : %d\n",iRet);

     printf("Enetr the number to search\n");
     scanf("%d",&ivalue);

     bRet = Search(first,ivalue);
     if(bRet==true)
     {
       printf("Number is present\n");
     }
     else
     {
       printf("Number is not present\n");
     }


    return 0;
}