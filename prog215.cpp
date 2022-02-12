#include<iostream>
using namespace std;

template <typename T>
struct node
{
   T data;
   struct node * next;
};

template <class T>
class SinglyLL
{
   private:
      node <T> * first;

      public:

        SinglyLL();
        void Insert(T);
        void Display();
        int Count();
        
};

template< class T>
SinglyLL <T>:: SinglyLL()
{
    first=NULL;
}

template< class T>
void SinglyLL <T> :: Insert(T No)
{
    node <T> * newn = new node <T>;
    newn->data=No;
    newn->next=NULL;

    if((first)==NULL)
    {
       first=newn;
    }
    else
    {
       newn->next=first;
       first=newn;
    }

}

template< class T>
void SinglyLL <T> :: Display()
{
   if(first!=NULL)
   {
     static node <T> * temp=first;
       if(temp!=NULL)
       {
          cout<<"|"<<temp->data<<"|->";
          temp=temp->next;
          Display();
       }
      

   }
   else
   {
      return;
   }
}


template< class T>
int SinglyLL <T> :: Count()
{
   if(first!=NULL)
   {
      static int icnt=0;
      static node <T> * temp=first;
       if(temp!=NULL)
       {
          temp=temp->next;
          icnt++;
          Count();
       }
       return icnt;

   }
   else
   {
      return 0;
   }
}



int main()
{
    SinglyLL <int> obj;

    obj.Insert(10);
    obj.Insert(20);
    obj.Insert(30);
    obj.Insert(40);

    obj.Display();
     cout<<"\n";
    int iRet=obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
   

   return 0;
}