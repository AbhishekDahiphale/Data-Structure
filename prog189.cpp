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

             if(Head==NULL)
             {
                 Head=newn;
                 Tail=newn;
             }
             else
             {
                 newn->next=Head;
                 Tail->next=newn;
                 Head=newn;
             }
             size++;
         }    

         void InsertLast(int No)
         {
              PNODE newn =new NODE;
             newn->data=No;
             newn->next=NULL;

             if(Head==NULL)
             {
                 Head=newn;
                 Tail=newn;
             }
             else
             {
                 Tail->next=newn;
                 newn->next=Head;
                 Tail=newn;
                  size++;
             }
            
             
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
                     delete(Tail->next);
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
                     PNODE temp=Head;
                     while((temp->next->next)!=Head)
                     {
                         temp=temp->next;
                     }
                     temp->next=Head;
                     delete(Tail);
                     Tail=temp;
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
                 delete(target);
               size--;
             }
             
         }

         void Display()
         {
             PNODE temp=Head;
             while(temp!=Tail)
             {
                 cout<<" <-|"<<temp->data<<"|-> ";
                 temp=temp->next;
             }
             cout<<" <-|"<<temp->data<<"|-> "<<"\n";

         }

         int Count()
         {
             return size;
         }
};

int main()
{ 
      ScircularLL obj;

      obj.InsertFirst(51);
      obj.InsertFirst(21);
      obj.InsertFirst(11);
      obj.Display();
      int iRet=obj.Count();
      cout<<"Number of nodes are : "<<iRet<<"\n";

      obj.InsertLast(101);
      obj.Display();
      iRet=obj.Count();
      cout<<"Number of nodes are : "<<iRet<<"\n";

      obj.InsertAtPos(31,3);
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
