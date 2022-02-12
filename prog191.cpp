#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
     int data;
     struct node *next;
     struct node *prev;
}NODE,*PNODE;

class DcircularLL
{
   private :
         PNODE Head;
         PNODE Tail;
         int size;

    public:
          DcircularLL()
          {
              Head=NULL;
              Tail=NULL;
              size=0;
          }     

          void InsertFirst(int No)
          {
               PNODE newn=new NODE;
               newn->data=No;
               newn->next=NULL;
               newn->prev=NULL;

               if(Head==NULL)
               {
                   Head=newn;
                   Tail=newn;
               }
               else
               {
                   newn->next=Head;
                   Head->prev=newn;
                   newn->prev=Tail;
                   Tail->next=newn;
                   Head=newn;
               }
               size++;
          }  

          void InserLast(int No)
          {
                PNODE newn=new NODE;
               newn->data=No;
               newn->next=NULL;
               newn->prev=NULL;

               if(Head==NULL)
               {
                   Head=newn;
                   Tail=newn;
               }
               else
               {
                   Tail->next=newn;
                   newn->prev=Tail;
                   Tail=newn;
                   Tail->next=Head;
                   Head->prev=Tail;
               }
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
              else if(pos==(size+1))
              {
                  InserLast(No); 
              }
              else
              {
                  PNODE newn=new NODE;
                  newn->data=No;
                  newn->next=NULL;
                  newn->prev=NULL;

                  PNODE temp=Head;
                  int i=1;
                  while(i!=(pos-1))
                  {
                      i++;
                      temp=temp->next;
                  }

                  newn->next=temp->next;
                  newn->prev=temp;
                  newn->next->prev=newn;
                  temp->next=newn;
                   size++;
              }
          }

          void DeleteFirst()
          {
              if(Head!=NULL)
              {
                  if(Head->next==NULL)
                  {
                      delete(Head);
                      Head=NULL;
                      Tail=NULL;
                  }
                  else
                  {
                      Head=Head->next;
                      delete(Head->prev);
                      Head->prev=Tail;
                      Tail->next=Head;
                      
                  }
                  size--;
              }
          }

          void DeleteLast()
          {
                if(Head!=NULL)
              {
                  if(Head->next==NULL)
                  {
                      delete(Head);
                      Head=NULL;
                      Tail=NULL;
                  }
                  else
                  {
                      Tail=Tail->prev;
                      delete(Tail->next);
                      Tail->next=Head;
                      Head->prev=Tail;

                  }
                  size--;
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
                  PNODE temp=Head;
                  int i=1;
                  while(i!=(pos-1))
                  {
                      i++;
                      temp=temp->next;
                  }
                  temp->next=temp->next->next;
                  delete(temp->next->prev);
                  temp->next->prev=temp;
                  size--;
              }
          }

          void Display()
          {
              PNODE temp=Head;

              while(temp!=Tail)
              {
                  cout<<"<-|"<<temp->data<<"|->";
                  temp=temp->next;
              }
                cout<<"<-|"<<temp->data<<"|->"<<"\n";
              
          }

          int Count()
          {
              return size;
          }


};

int main()
{
    DcircularLL obj;
    int iRet=0; 

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InserLast(101);
    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertAtPos(25,3);
    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteAtPos(3);
    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteLast();
    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";





    return 0;
}
