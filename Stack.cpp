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
        Stack();
        void push(int);
        int  pop();
        void Display();
        int Count();
};

Stack :: Stack()
        {
            first=NULL;
            size=0;
        }

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
    int ichoice=1,ivalue=0,iRet=0;
   
    while(ichoice!=0)
    {   
        cout<<"---- Choose the operation perform of stack ----";
        cout<<"\n-----------------------------------------------------\n";
        cout<<"0 : Terminate the application\n";
        cout<<"1 : Push(Insert) the element in Stack \n";
        cout<<"2 : Pop(Delete) the element in Stack \n";
        cout<<"3 : Display the all element int stack \n";
        cout<<"4 : Count the all the numbers present in the stack\n";
        cout<<"\n-----------------------------------------------------\n";
        cin>>ichoice;
        cout<<"\n-----------------------------------------------------\n";


        switch(ichoice)
        {
            case 0 : 
                    cout<<"Thank You For Using Stack\n";
                    break;

            case 1 : 
                     cout<<"enter the number which are insert int the stack\n";
                     cin>>ivalue;
                     obj.push(ivalue);
                     break;

            case 2 : 
                     iRet=obj.pop();
                     cout<<"poped element from stack : "<<iRet<<"\n";
                     break; 

            case 3 : 
                     obj.Display(); 
                     break;

            case 4 :
                     iRet = obj.Count();
                     cout<<"Number of elemets in the stack : "<<iRet<<"\n";
                     break;

            default : 
                     cout<<"Wrong choice\n";
                     break;                

        }
    }


    return 0;
}
