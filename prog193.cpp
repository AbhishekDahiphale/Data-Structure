#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
}NODE,*PNODE;

class Stack
{
    private:
        PNODE first;
        int size;

    public:
        Stack()
        {
            first=NULL;
            size=0;
        }

        void push(int);
        int  pop();
        void Display();
        int Count();
};

 void Stack :: push(int No)   //InsertFirst
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

 int Stack :: pop()   //DeleteFirst
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

 void Stack :: Display()
 {
     if(first!=NULL)
     {
         PNODE temp =first;

       while (temp!=NULL)
       {
           cout<<"|"<<temp->data<<"|->";
           temp=temp->next;
       }
       cout<<"NULL\n";

     }
     else
     {
         printf("Stack is empty\n");
         return;
     }
     
 }

 int Stack :: Count()
 {
   return size;
 }
 
int main()
{
    Stack obj;

    obj.push(11);
    obj.push(21);
    obj.push(51);
    obj.push(101);

    obj.Display();

    int iRet=obj.pop();
    cout<<"poped element from stack : "<<iRet<<"\n";


    return 0;
}