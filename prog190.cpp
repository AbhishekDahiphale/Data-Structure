#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
}NODE,*PNODE;

class ScircularLL
{
    private:
         PNODE Head;
         PNODE Tail;
         int size;

    public:

         ScircularLL()
         {
             Head=NULL;
             Tail=NULL;
             size=0;
         }   

         void InsertFirst(int No)
         {
             PNODE newn =new NODE;
             newn->data=No;
             newn->next=NULL;

             if((Head==NULL) && (Tail==NULL))
             {
                 Head=newn;
                 Tail=newn;
             }
             else
             {
                 newn->next=Head;
                 Head=newn;
             }
             Tail->next=Head;
             size++;
         }    

         void InsertLast(int No)
         {
              PNODE newn =new NODE;
             newn->data=No;
             newn->next=NULL;

             if((Head==NULL) && (Tail==NULL))
             {
                 Head=newn;
                 Tail=newn;
             }
             else
             {
                 Tail->next=newn;
                 Tail=newn;
                 
             }
              Tail->next=Head;

              size++;
         }

         void InsertAtPos(int No,int pos)
         {
             if((pos < 1) || (pos > (size+1)))
             {
                 return;
             }

             if(pos==1)
             {
                 InsertFirst(No);
             }
             else if (pos==(size+1))
             {
                  InsertLast(No);
             }
             else
             {
                 PNODE newn=new NODE;
                 newn->data=No;
                 newn->next=NULL;

                 PNODE temp=Head;
                 int i=1;

                 while(i!=(pos-1))
                 {
                     i++;
                     temp=temp->next;
                 }
                  newn->next=temp->next;
                  temp->next=newn;
                  size++;
                  Tail->next=Head;
             }
             
             
         }

         void DeleteFirst()
         {
             if((Head!=NULL) && (Tail!=NULL))
             {
                  if((Head==Tail))
                 {
                     delete(Head);
                     Head=NULL;
                     Tail=NULL;
                 }
                 else
                 {
                     Head=Head->next;
                     delete(Tail->next);
                     Tail->next=Head;
                 }
                 size--;
             }
             else
             {
                 return;
             }
         }

         void DeleteLast()
         {
             if((Head!=NULL) && (Tail!=NULL))
             {
                 if((Head==Tail))
                 {
                     delete(Head);
                     Head=NULL;
                     Tail=NULL;
                 }
                 else
                 {
                     PNODE temp=Head;
                     while((temp->next)!=Tail)
                     {
                         temp=temp->next;
                     }
                     delete(Tail);
                     Tail=temp;
                     
                 }
                  Tail->next=Head;
                 size--;
             }
             else
             {
                 return;
             }
         }

         void DeleteAtPos(int pos)
         {
             if((pos < 1) || (pos > size))
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
                 PNODE temp=Head;
                 PNODE target=NULL;
                 int i=1;
                  while(i!=(pos-1))
                  {
                      i++;
                      temp=temp->next;
                  }
                 target=temp->next;
                 temp->next=target->next;
                 delete target;
               size--;
             }
             
         }

         void Display()
         {
             if(size!=0)
             {
                 PNODE temp=Head;
                 do
                 {
                      cout<<"|"<<temp->data<<"|-> ";
                      temp=temp->next;
                  }while(temp!=(Tail->next));
             }
             else
             {
                 return;
             }
         }

         int Count()
         {
             return size;
         }
};

int main()
{ 
      ScircularLL obj;
    int iRet=0,ichoice=1,ipos=0,ivalue=0;

    while(ichoice!=0)
    {
        cout<<"\n********************************************\n";
        cout<<"0 : Terminate the application \n";
        cout<<"1 : Insert the Node at first position \n";
        cout<<"2 : Insert the node at last position \n";
        cout<<"3 : Insert the node at desired position \n";
        cout<<"4 : Delete the first node\n";
        cout<<"5 : Delete the last node\n";
        cout<<"6 : Delete the node at desired position \n";
        cout<<"7 : Display the linkedlist \n";
        cout<<"8 : Count the nodes int the linked list \n";
        cin>>ichoice;
        cout<<"\n********************************************\n";


        switch(ichoice)
        {

            case 0 : 
                    cout<<"Thank You for using th linked list\n";
                    break;

            case 1 : 
                    cout<<"enter data to insert into the node\n";
                    cin>>ivalue;
                    obj.InsertFirst(ivalue);
                    break;

            case 2 : 
                    cout<<"enter data to insert into the node\n";
                    cin>>ivalue;
                    obj.InsertLast(ivalue);
                    break;

            case 3 : 
                    cout<<"enter data to insert into the node\n";
                    cin>>ivalue;
                    cout<<"enter the poistion \n";
                    cin>>ipos;
                    obj.InsertAtPos(ivalue,ipos);
                    break;                       

            case 4 : 
                    obj.DeleteFirst();
                    break;

            case 5 : 
                    obj.DeleteLast();
                    break;   

            case 6 : 
                    cout<<"Insert the position \n";
                    cin>>ipos;
                    obj.DeleteAtPos(ipos);
                    break;    

            case 7 : 
                    obj.Display();
                    break;     

            case 8 : 
                    iRet = obj.Count();
                    cout<<"Number of nodes in Linkedlist : "<<iRet<<"\n";
                    break;                    

            default : 
                 printf("wrong choice\n");
                  break;     

        }
    }


     return 0;
} 
