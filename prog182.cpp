#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
}NODE,*PNODE;

class SinglyLL
{
   private:
     PNODE first;
     int size;

   public:
    SinglyLL()
    {
        first=NULL;
        size=0;
    }  

    void InsertFirst(int No)
    {
      PNODE newn=new NODE;
      
      newn->data=No;
      newn->next=NULL;

      if(first==NULL)
      {
          first=newn;
      }
      else
      {
          newn->next=first;
          first=newn;
      }
      size++;
    }

    void InsertLast(int No)
    {
       PNODE newn=new NODE;

        newn->data=No;
        newn->next=NULL;

      if(first==NULL)
      {
          first=newn;
      }
      else
      {
         PNODE temp = first;
         
         while(temp->next!=NULL)
         {
             temp=temp->next;
         }
         temp->next=newn;
      }
      size++;

    }
    void InsertAtPos(int No,int pos)
    {
       if( (pos < 1) || (pos > (size +1)) )
       {
           return;
       }  

       if(pos==1)
       {
           InsertFirst(No);
       }
       else if(pos==(size+1))
       {
           InsertLast(No);
       }
       else
       {
           PNODE newn=new NODE;
           newn->data=No;
           newn->next=NULL;

           PNODE temp = first;
           int i=1;
           while(i!=(pos-1))
           { 
              i++;
              temp=temp->next;
           }
           newn->next=temp->next;
           temp->next=newn;
           size++;

       }

    }
    void DeleteFirst()
    {
      PNODE temp=first;

        if(first!=NULL)
        {
            first=first->next;
            delete temp;
            size--;
        }
    }
    void DeleteLast()
    {
      PNODE temp=first;

      if(first!=NULL)
      {
         if(first->next==NULL)
         {
             delete first;
             first=NULL;
             size--;
         }
         else
         {
             int i=1;
             while(i!=(size-1))
             {
               i++;
               temp=temp->next;
             }
             delete(temp->next);
             temp->next=NULL;
             size--;
         }
      }
    }
    void DeleteAtPos(int pos)
    {
        if( (pos < 1) || (pos > (size+1)) )
        {
            return;
        }

        if(pos==1)
        {
            DeleteFirst();
        }
        else if (pos==size)
        {
            DeleteLast();
        }
        else
        {
            PNODE temp=first;
            PNODE target=NULL;
            int i=1;
            while(i!=(pos-1))
            {
               i++;
               temp=temp->next;
            }
             target=temp->next;
             temp->next=target->next;
             delete(target);
             size--;
        }
        

    }
    void Display()
    {
       PNODE temp =first;

       while (temp!=NULL)
       {
           cout<<"|"<<temp->data<<"|->";
           temp=temp->next;
       }
       cout<<"NULL\n";
       
    }
    int Count()
    {
       return size;
    }
};

int main()
{
    SinglyLL obj;
    int iRet=0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.Display();

    obj.InsertAtPos(71,4);
    obj.Display();

    obj.DeleteAtPos(4);
    obj.Display();
     
    obj.DeleteFirst();  
    obj.Display();

     obj.DeleteLast();
     obj.Display();

    iRet=obj.Count();
    cout<<"Number of elemets are :"<<iRet<<"\n";

    return 0;
}