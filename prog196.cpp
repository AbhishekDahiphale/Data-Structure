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
            if(first->next==NULL)
            {
               idata=first->data;
               delete(first);
               first=NULL;
            }
            else
            {
            first=first->next;
            idata=(temp->data);
            delete temp;
            size--;
            }
            return idata;
        }
        else
        {
            return -1;
        }
        
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
    int ichoice=1,ivalue=0,iRet=0;
   
    while(ichoice!=0)
    {   
        cout<<"---- Choose the operation perform of Queue ----";
        cout<<"\n-----------------------------------------------------\n";
        cout<<"0 : Terminate the application\n";
        cout<<"1 : Insert the element in Queue \n";
        cout<<"2 : Delete the element in Queue \n";
        cout<<"3 : Display the all element in the Queue \n";
        cout<<"4 : Count the all the numbers present in the Queue\n";
        cout<<"\n-----------------------------------------------------\n";
        cin>>ichoice;
        cout<<"\n-----------------------------------------------------\n";


        switch(ichoice)
        {
            case 0 : 
                    cout<<"Thank You For Using Queue\n";
                    break;

            case 1 : 
                     cout<<"enter the number which are insert int the Queue\n";
                     cin>>ivalue;
                     obj.EnQueue(ivalue);
                     break;

            case 2 : 
                     iRet=obj.Dqueue();
                     if(iRet==(-1))
                     {
                         cout<<"Queue is empty\n";
                     }
                     else
                     {
                         cout<<"Deleted element from Queue : "<<iRet<<"\n";
                     }
                     break; 

            case 3 : 
                     obj.Display(); 
                     break;

            case 4 :
                     iRet = obj.Count();
                     cout<<"Number of elemets in the Queue : "<<iRet<<"\n";
                     break;

            default : 
                     cout<<"Wrong choice\n";
                     break;                

        }
    }

    return 0;
}