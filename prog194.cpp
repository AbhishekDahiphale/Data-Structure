#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
}NODE,*PNODE;

class Queue
{
    private:
        PNODE first;
        int size;

    public:
        Queue()
        {
            first=NULL;
            size=0;
        }

        void EnQueue(int);
        int  Dqueue();
        void Display();
        int Count();
};

 void Queue :: EnQueue(int No)   //InsertLast
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

 int Queue :: Dqueue()   //DeleteFirst
 {
     PNODE temp=first;
     int idata=0;
        if(first!=NULL)
        {
            first=first->next;
            idata=(temp->data);
            delete temp;
            size--;
        }
        return idata;

 }

 void Queue :: Display()
 {
     if(first!=NULL)
     {
         PNODE temp =first;

       while (temp!=NULL)
       {
            cout<<"<-|"<<temp->data<<"|";
           temp=temp->next;
       }
       cout<<"<-NULL\n";

     }
     else
     {
         printf("Stack is empty\n");
         return;
     }
     
 }

 int Queue :: Count()
 {
   return size;
 }
 
int main()
{
    Queue obj;

    obj.EnQueue(11);
    obj.EnQueue(21);
    obj.EnQueue(51);
    obj.EnQueue(101);

    obj.Display();

    int iRet=obj.Dqueue();
    cout<<"Deleted element from queue: "<<iRet<<"\n";


    return 0;
}