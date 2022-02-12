#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE,*PNODE;

class DoublyLL
{
    private:
         PNODE first;
         int  size;

    public:

        DoublyLL()
        {
            first=NULL;
            size=0;
        }

        void InsertFirst(int No)
        {
          PNODE newn = new NODE;
          newn->data=No;
          newn->next=NULL;
          newn->prev=NULL;
          
          if(first==NULL)
          {
              first=newn;
          }
          else
          {
              newn->next=first;
              first->prev=newn;
              first=newn;
          }
          size++;

        }
        void InsertLast(int No)
        {
            PNODE newn = new NODE;
            newn->data=No;
            newn->next=NULL;
            newn->prev=NULL;

            if(first==NULL)
            {
                first=newn;
            }
            else
            {
                PNODE temp=first;
                int i=1;
                while (i!=size)
                {
                    i++;
                    temp=temp->next;
                }
                temp->next=newn;
                newn->prev=temp;
                
            }
            size++;

        }   
        void InsertAtPos(int No,int pos)
        {
          if( (pos < 1 ) || (pos > (size+1)) )
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
              PNODE temp=first;
              int i=1;
              PNODE newn=new NODE;
              newn->data=No;
              newn->next=NULL;
              newn->prev=NULL;

             while(i!=(pos-1))
             {
                i++;
                temp=temp->next;
             }
             newn->next=temp->next;
             newn->next->prev=newn;
             newn->prev=temp;
             temp->next=newn;
            
              size++;
          }

        }
        void DeleteFirst()
        {
            if(first!=NULL)
            {
                if(first->next==NULL)
                {
                    delete(first);
                    first=NULL;
                }
                else
                {
                    first=first->next;
                    delete(first->prev);
                    first->prev=NULL;
                     size--;
                }
               
            }

        }
        void DeleteLast()
        {
            if(first!=NULL)
            {
                if(first->next==NULL)
                {
                    delete(first->next);
                    first=NULL;
                }
                else
                {
                    PNODE temp=first;
                    int i=1;

                    while(i!=size)
                    {
                        i++;
                        temp=temp->next;
                    }
                     temp->prev->next=NULL;
                     delete(temp);
                     size--;
                    
                }
               

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
            else if(pos==size)
            {
                DeleteLast();
            }
            else
            {
                PNODE temp=first;
                int i=1;
                while(i!=(pos))
                {
                    i++;
                    temp=temp->next;
                }
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev; 
                delete(temp);
                size--;
            }

        }
        void Display()
        {
          PNODE temp=first;

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
   DoublyLL obj;
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
                    cout<<"Number of nodes in the Linkedlist : "<<iRet<<"\n";
                    break;                    

            default : 
                 printf("wrong choice\n");
                  break;     
            
        }
    }
    return 0;
}