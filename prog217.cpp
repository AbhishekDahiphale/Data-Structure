#include<iostream>
using namespace std;

typedef struct node 
{
   int data;
   struct node * right;
   struct node * left;
}NODE,*PNODE;


class BST
{
   private:
      PNODE first;
      int size;

   public:
       BST();
       void Insert(int);
       bool Search(int);
       void PreOrder();
       void InOrder();
       void PostOrder();
       int CountParent();
       int CountLeaf(); 
       int GFfrequency(int);
   private : 
       void PreOrderf(PNODE);
       int CountParentf(PNODE);
       int CountLeaff(PNODE);
       int GFfrequencyf(PNODE,int);


};

BST :: BST()
{
   first=NULL;
   size=0;
}

void BST :: Insert(int No)
{
   PNODE newn = new NODE;
   newn->data=No;
   newn->left=NULL;
   newn->right=NULL;

   if(first==NULL)
   {
      first=newn;
   }
   else
   {
      PNODE temp = first;

      while(1)
      {
         if(No == (temp->data))
         {
            delete newn;
            break;
         }
         else if(No > (temp->data))
         {
            if((temp->right)==NULL)
            {
               temp->right=newn;
               break;
            }
             temp=temp->right ; 
         }
         else if (No < (temp->data))
         {
            if((temp->left)==NULL)
            {
               temp->left=newn;
               break;
            }
            temp=temp->left;
         }
         
      }
   }
}


bool BST :: Search(int No)
{
   if(first!=NULL)
   {
      PNODE temp=first;
      bool flag=false;
      while(temp!=NULL)
      {
         if(No == (temp->data))
         {
            flag=true;
            break;
         }
         else if(No > (temp->data) )
         {
            temp=temp->right;
         }
         else if(No < (temp->data))
         {
            temp=temp->left;
         }
      }
      if(temp==NULL)
      {
         return false;
      }
      else
      {
         return flag;
      }

   }
   else
   {
      return false;
   }
}


void BST :: PreOrderf(PNODE temp)
{ 
   if(first!=NULL)
   {
    
      if(temp!=NULL)
      {
        cout<<temp->data<<"\t";
        PreOrderf(temp->left);
        PreOrderf(temp->right);
         
      }

   }
   else
   {
      return;
   }
}

int BST :: CountParentf(PNODE temp)
{
   if(first!=NULL)
   {
       static int icnt=1;
     if(temp!=NULL)
     {
        if(((temp->left)!=NULL) || ((temp->right)!=NULL))
        {
           icnt++;
        }
        CountParentf(temp->left);
        CountParentf(temp->right);
     }   
     return icnt;
   }
   else
   {
      return -1;
   }
}

int BST :: CountParent()
{
   int iRet = CountParentf(first);
   return iRet;
}

void BST :: PreOrder()
{
    PreOrderf(first);
}

int BST :: CountLeaff(PNODE temp)
{
  if(first!=NULL)
  {
    static int icnt=0;
    if(temp!=NULL)
    {
      if(((temp->left)==NULL)  && ((temp->right)==NULL))
      {
          icnt++;
      }
      
      CountLeaff(temp->right);
      CountLeaff(temp->left);
    }
    return icnt;
  }
  else
  {
    return -1;
  }
}

int BST :: CountLeaf()
{
   int iRet = CountLeaff(first);
   return iRet;
}


int BST ::  GFfrequencyf(PNODE temp,int No)
{
  if(first!=NULL)
  {
    static int icnt=0;
    if(temp!=NULL)
    {
       if(No <= (temp->data) )
       {
           icnt++;
       }
           GFfrequencyf(temp->right,No); 
           GFfrequencyf(temp->left,No);    
     }
    return icnt;
  }
  else
  {
    return -1;
  }

}

int BST :: GFfrequency(int No)
{
   int iRet = GFfrequencyf(first,No);
   return iRet;
} 



int main()
{
   BST obj;
   bool bRet=false;

   obj.Insert(51);
   obj.Insert(21);
   obj.Insert(101);
   obj.Insert(71);
   obj.Insert(37);
   obj.Insert(20);

   bRet=obj.Search(37);
   if(bRet==true)
   {
      cout<<"Number is present\n";
   }
   else
   {
      cout<<"Number is not present\n";
   }

   obj.PreOrder();

   
   return 0;

}