#include<iostream>
using namespace std;

template <typename T6>
struct node6
{
    T6 data;
    struct node6 * next;
};


template <class T6>
class Queue
{
    private:
        node6 <T6> * first;
        int size;

    public:
        Queue();
        void EnQueue(T6);
        int  Dqueue();
        void Display();
        int Count();
};

template <class T6>
 Queue <T6> :: Queue()
        {
            first=NULL;
            size=0;
        }

template <class T6>
 void Queue <T6> :: EnQueue(T6 No) 
 {
     node6 <T6> * newn=new node6 <T6>;

        newn->data=No;
        newn->next=NULL;

      if(first==NULL)
      {
          first=newn;
      }
      else
      {
         node6 <T6> * temp = first;
         
         while(temp->next!=NULL)
         {
             temp=temp->next;
         }
         temp->next=newn;
      }
      size++;

 }

template <class T6>
 int Queue <T6> :: Dqueue()  
 {
     node6 <T6> * temp=first;
     <T6> idata=0;
        if(first!=NULL)
        {
            first=first->next;
            idata=(temp->data);
            delete temp;
            size--;
        }
        return idata;

 }

template <class T6>
 void Queue <T6> :: Display()
 {
     if(first!=NULL)
     {
         node6 <T6> * temp =first;

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

template <class T6>
 int Queue  <T6> :: Count()
 {
   return size;
 }
 
int main()
{
    int iSelect=1;


    while(iSelect!=0)
    {
         cout<<"-----Select the Datatype of Queue-------\n";
         cout<<"\n-----------------------------------------------------\n";
         cout<<"0 : Terminate the application\n";
         cout<<"1 : For char\n";
         cout<<"2 : For int\n";
         cout<<"3 : For float\n";
         cout<<"4 : For Double\n";
         cout<<"\n-----------------------------------------------------\n";
         cin>>iSelect;
         cout<<"\n-----------------------------------------------------\n";

         switch(iSelect)
         {
            case 0 :    {
                         cout<<"Thank You for Using the application\n";
                         } 
                         break;
                          

            case 1 :  
                        {        
                        Queue <char> cobj;
                        int cchoice=1,cRet=0;
                        char chRet='\0',cValue='\0';
                         while(cchoice!=0)
                        {   
                             cout<<"---- Choose the operation perform of Queue ----\n";
                             cout<<"\n-----------------------------------------------------\n";
                             cout<<"0 : Terminate the application\n";
                             cout<<"1 : Insert the element in Queue \n";
                             cout<<"2 : Delete the element in Queue \n";
                             cout<<"3 : Display the all element in the Queue \n";
                             cout<<"4 : Count the all the Character present in the Queue\n";
                             cout<<"\n-----------------------------------------------------\n";
                             cin>>cchoice;
                             cout<<"\n-----------------------------------------------------\n";


                            switch(cchoice)
                           {
                             case 0 : 
                                         cout<<"Thank You For Using Queue\n";
                             break;

                             case 1 : 
                                         cout<<"enter the character which are insert int the Queue\n";
                                         cin>>cValue;
                                         cobj.EnQueue(cValue);
                                         break;

                             case 2 : 
                                         chRet=cobj.Dqueue();
                                         cout<<"Deleted element from Queue : "<<chRet<<"\n";
                                         break; 

                             case 3 : 
                                         cobj.Display(); 
                                         break;

            
                             case 4 :
                                         cRet = cobj.Count();
                                         cout<<"Number of elemets in the Queue : "<<cRet<<"\n";
                                         break;

                             default : 
                                         cout<<"Wrong choice\n";
                                         break;                

                            }
                        }
                        }break;

            case 2 :     
                     {     
                     Queue <int> iobj;
                     int ichoice=1,iValue=0,iRet=0;
                         while(ichoice!=0)
                        {   
                             cout<<"---- Choose the operation perform of Queue ----\n";
                             cout<<"\n-----------------------------------------------------\n";
                             cout<<"0 : Terminate the application\n";
                             cout<<"1 : Insert the element in Queue \n";
                             cout<<"2 : Delete the element in Queue \n";
                             cout<<"3 : Display the all element in the Queue \n";
                             cout<<"4 : Count the all the element present in the Queue\n";
                             cout<<"\n-----------------------------------------------------\n";
                             cin>>ichoice;
                             cout<<"\n-----------------------------------------------------\n";


                            switch(ichoice)
                           {
                             case 0 : 
                                         cout<<"Thank You For Using Queue\n";
                             break;

                             case 1 : 
                                         cout<<"enter the data which are insert int the Queue\n";
                                         cin>>iValue;
                                         iobj.EnQueue(iValue);
                                         break;

                             case 2 : 
                                         iRet=iobj.Dqueue();
                                         cout<<"Deleted element from Queue : "<<iRet<<"\n";
                                         break; 

                             case 3 : 
                                         iobj.Display(); 
                                         break;

            
                             case 4 :
                                         iRet = iobj.Count();
                                         cout<<"Number of elemets in the Queue : "<<iRet<<"\n";
                                         break;

                             default : 
                                         cout<<"Wrong choice\n";
                                         break;                

                            }
                        }
                     }break;

            case 3 :  
                     {        
                     Queue <float> fobj;
                     int fchoice=1,fRet=0;
                     float fValue=0,flRet=0;
                         while(fchoice!=0)
                        {   
                             cout<<"---- Choose the operation perform of Queue ----\n";
                             cout<<"\n-----------------------------------------------------\n";
                             cout<<"0 : Terminate the application\n";
                             cout<<"1 : Insert the element in Queue \n";
                             cout<<"2 : Delete the element in Queue \n";
                             cout<<"3 : Display the all element in the Queue \n";
                             cout<<"4 : Count the all the element present in the Queue\n";
                             cout<<"\n-----------------------------------------------------\n";
                             cin>>fchoice;
                             cout<<"\n-----------------------------------------------------\n";


                            switch(fchoice)
                           {
                             case 0 : 
                                         cout<<"Thank You For Using Queue\n";
                             break;

                             case 1 : 
                                         cout<<"enter the data which are insert int the Queue\n";
                                         cin>>fValue;
                                         fobj.EnQueue(fValue);
                                         break;

                             case 2 : 
                                         flRet=fobj.Dqueue();
                                         cout<<"Deleted element from Queue : "<<flRet<<"\n";
                                         break; 

                             case 3 : 
                                         fobj.Display(); 
                                         break;

            
                             case 4 :
                                         fRet = fobj.Count();
                                         cout<<"Number of elemets in the Queue : "<<fRet<<"\n";
                                         break;

                             default : 
                                         cout<<"Wrong choice\n";
                                         break;                

                            }
                        }
                     }break;


            case 4 :  
                     {         
                     Queue <double> dobj;
                     int dchoice=1,dRet=0;
                     double dValue=0,doRet=0;
                         while(dchoice!=0)
                        {   
                             cout<<"---- Choose the operation perform of Queue ----\n";
                             cout<<"\n-----------------------------------------------------\n";
                             cout<<"0 : Terminate the application\n";
                             cout<<"1 : Insert the element in Queue \n";
                             cout<<"2 : Delete the element in Queue \n";
                             cout<<"3 : Display the all element in the Queue \n";
                             cout<<"4 : Count the all the element present in the Queue\n";
                             cout<<"\n-----------------------------------------------------\n";
                             cin>>dchoice;
                             cout<<"\n-----------------------------------------------------\n";


                            switch(dchoice)
                           {
                             case 0 : 
                                         cout<<"Thank You For Using Queue\n";
                             break;

                             case 1 : 
                                         cout<<"enter the data which are insert int the Queue\n";
                                         cin>>dValue;
                                         dobj.EnQueue(dValue);
                                         break;

                             case 2 : 
                                         doRet=dobj.Dqueue();
                                         cout<<"Deleted element from Queue : "<<doRet<<"\n";
                                         break; 

                             case 3 : 
                                         dobj.Display(); 
                                         break;

            
                             case 4 :
                                         dRet = dobj.Count();
                                         cout<<"Number of elemets in the Queue : "<<dRet<<"\n";
                                         break;

                             default : 
                                         cout<<"Wrong choice\n";
                                         break;                

                            }
                        }
                     }break;       

            default :
                     { 
                      cout<<"Wrong choice\n";
                     }
                      break;                             

         }
    }
   
   

    return 0;
}