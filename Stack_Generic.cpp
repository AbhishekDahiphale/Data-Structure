#include<iostream>
using namespace std;

template <typename T5>
struct node5
{
    T5 data;
    struct node5 * next;
};

template <class T5>
class Stack
{
    private:
        node5 <T5> * first;
        int size;

    public:
        Stack();
        void push(T5);
        int  pop();
        void Display();
        int Count();
};

template <class T5>
Stack <T5> :: Stack()
        {
            first=NULL;
            size=0;
        }


template <class T5>
 void Stack <T5> :: push(T5 No)  
 {
     node5 <T5> * newn=new node5 <T5>;
      
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

template <class T5>
 int Stack <T5> :: pop()   
 {
     node5 <T5> * temp=first;
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


template <class T5>
 void Stack <T5> :: Display()
 {
     if(first!=NULL)
     {
         node5 <T5> * temp =first;

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


template <class T5>
 int Stack <T5> :: Count()
 {
   return size;
 }
 
int main()
{
     int iSelect=1;


    while(iSelect!=0)
    {
         cout<<"-----Select the Datatype of Stack-------\n";
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
                        Stack <char> cobj;
                        int cchoice=1,cRet=0;
                        char chRet='\0',cValue='\0';
                         while(cchoice!=0)
                        {   
                             cout<<"---- Choose the operation perform of Stack ----\n";
                             cout<<"\n-----------------------------------------------------\n";
                             cout<<"0 : Terminate the application\n";
                             cout<<"1 : Insert the element in Stack \n";
                             cout<<"2 : Delete the element in Stack \n";
                             cout<<"3 : Display the all element in the Stack \n";
                             cout<<"4 : Count the all the Character present in the Stack\n";
                             cout<<"\n-----------------------------------------------------\n";
                             cin>>cchoice;
                             cout<<"\n-----------------------------------------------------\n";


                            switch(cchoice)
                           {
                             case 0 : 
                                         cout<<"Thank You For Using Stack\n";
                             break;

                             case 1 : 
                                         cout<<"enter the character which are insert int the Stack\n";
                                         cin>>cValue;
                                         cobj.push(cValue);
                                         break;

                             case 2 : 
                                         chRet=cobj.pop();
                                         cout<<"Deleted element from Stack : "<<chRet<<"\n";
                                         break; 

                             case 3 : 
                                         cobj.Display(); 
                                         break;

            
                             case 4 :
                                         cRet = cobj.Count();
                                         cout<<"Number of elemets in the Stack : "<<cRet<<"\n";
                                         break;

                             default : 
                                         cout<<"Wrong choice\n";
                                         break;                

                            }
                        }
                        }break;

            case 2 :     
                     {     
                     Stack <int> iobj;
                     int ichoice=1,iValue=0,iRet=0;
                         while(ichoice!=0)
                        {   
                             cout<<"---- Choose the operation perform of Stack ----\n";
                             cout<<"\n-----------------------------------------------------\n";
                             cout<<"0 : Terminate the application\n";
                             cout<<"1 : Insert the element in Stack \n";
                             cout<<"2 : Delete the element in Stack \n";
                             cout<<"3 : Display the all element in the Stack \n";
                             cout<<"4 : Count the all the element present in the Stack\n";
                             cout<<"\n-----------------------------------------------------\n";
                             cin>>ichoice;
                             cout<<"\n-----------------------------------------------------\n";


                            switch(ichoice)
                           {
                             case 0 : 
                                         cout<<"Thank You For Using Stack\n";
                             break;

                             case 1 : 
                                         cout<<"enter the data which are insert int the Stack\n";
                                         cin>>iValue;
                                         iobj.push(iValue);
                                         break;

                             case 2 : 
                                         iRet=iobj.pop();
                                         cout<<"Deleted element from Stack : "<<iRet<<"\n";
                                         break; 

                             case 3 : 
                                         iobj.Display(); 
                                         break;

            
                             case 4 :
                                         iRet = iobj.Count();
                                         cout<<"Number of elemets in the Stack : "<<iRet<<"\n";
                                         break;

                             default : 
                                         cout<<"Wrong choice\n";
                                         break;                

                            }
                        }
                     }break;

            case 3 :  
                     {        
                     Stack <float> fobj;
                     int fchoice=1,fRet=0;
                     float fValue=0,flRet=0;
                         while(fchoice!=0)
                        {   
                             cout<<"---- Choose the operation perform of Stack ----\n";
                             cout<<"\n-----------------------------------------------------\n";
                             cout<<"0 : Terminate the application\n";
                             cout<<"1 : Insert the element in Stack \n";
                             cout<<"2 : Delete the element in Stack \n";
                             cout<<"3 : Display the all element in the Stack \n";
                             cout<<"4 : Count the all the element present in the Stack\n";
                             cout<<"\n-----------------------------------------------------\n";
                             cin>>fchoice;
                             cout<<"\n-----------------------------------------------------\n";


                            switch(fchoice)
                           {
                             case 0 : 
                                         cout<<"Thank You For Using Stack\n";
                             break;

                             case 1 : 
                                         cout<<"enter the data which are insert int the Stack\n";
                                         cin>>fValue;
                                         fobj.push(fValue);
                                         break;

                             case 2 : 
                                         flRet=fobj.pop();
                                         cout<<"Deleted element from Stack : "<<flRet<<"\n";
                                         break; 

                             case 3 : 
                                         fobj.Display(); 
                                         break;

            
                             case 4 :
                                         fRet = fobj.Count();
                                         cout<<"Number of elemets in the Stack : "<<fRet<<"\n";
                                         break;

                             default : 
                                         cout<<"Wrong choice\n";
                                         break;                

                            }
                        }
                     }break;


            case 4 :  
                     {         
                     Stack <double> dobj;
                     int dchoice=1,dRet=0;
                     double dValue=0,doRet=0;
                         while(dchoice!=0)
                        {   
                             cout<<"---- Choose the operation perform of Stack ----\n";
                             cout<<"\n-----------------------------------------------------\n";
                             cout<<"0 : Terminate the application\n";
                             cout<<"1 : Insert the element in Stack \n";
                             cout<<"2 : Delete the element in Stack \n";
                             cout<<"3 : Display the all element in the Stack \n";
                             cout<<"4 : Count the all the element present in the Stack\n";
                             cout<<"\n-----------------------------------------------------\n";
                             cin>>dchoice;
                             cout<<"\n-----------------------------------------------------\n";


                            switch(dchoice)
                           {
                             case 0 : 
                                         cout<<"Thank You For Using Stack\n";
                             break;

                             case 1 : 
                                         cout<<"enter the data which are insert int the Stack\n";
                                         cin>>dValue;
                                         dobj.push(dValue);
                                         break;

                             case 2 : 
                                         doRet=dobj.pop();
                                         cout<<"Deleted element from Stack : "<<doRet<<"\n";
                                         break; 

                             case 3 : 
                                         dobj.Display(); 
                                         break;

            
                             case 4 :
                                         dRet = dobj.Count();
                                         cout<<"Number of elemets in the Stack : "<<dRet<<"\n";
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
