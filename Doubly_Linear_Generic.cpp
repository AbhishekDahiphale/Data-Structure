#include<iostream>
using namespace std;

template <typename T3>
struct node
{
    T3 data;
    struct node *next;
    struct node *prev;
};

template <class T3>
class DoublyLL
{
    private:
         node <T3> * first;
         int  size;

    public:
     DoublyLL();
     void InsertFirst(T3);
     void InsertLast(T3);
     void InsertAtPos(T3,int);
     void DeleteFirst();
     void DeleteLast();
     void DeleteAtPos(int);
     void Display();
     int  Count();
     int SearchFirstOcc(T3);
     int SearchLastOcc(T3);
     T3 Addition();
     T3 Maximum();
     T3 Minimum();

       

};
         template <class T3> 
         DoublyLL <T3> ::  DoublyLL()
         {
            first=NULL;
            size=0;
         }

         template <class T3>
         void DoublyLL <T3> :: InsertFirst(T3 No)
        {
          node <T3> * newn = new node <T3>;
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

        template <class T3>
        void DoublyLL <T3> :: InsertLast(T3 No)
        {
            node <T3> * newn = new node <T3>;
            newn->data=No;
            newn->next=NULL;
            newn->prev=NULL;

            if(first==NULL)
            {
                first=newn;
            }
            else
            {
                node <T3> * temp=first;
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

         template <class T3>
        void DoublyLL <T3> :: InsertAtPos(T3 No,int pos)
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
              node <T3> * temp=first;
              int i=1;
              node <T3> * newn=new node <T3>;
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

        template <class T3>
        void DoublyLL <T3> :: DeleteFirst()
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

        template <class T3>
        void DoublyLL <T3> :: DeleteLast()
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
                    node <T3> * temp=first;
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

         template <class T3>
        void DoublyLL <T3> :: DeleteAtPos(int pos)
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
                node <T3> * temp=first;
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

         template <class T3>
        void DoublyLL <T3> :: Display()
        {
          node <T3> * temp=first;

          while (temp!=NULL)
          {
              cout<<"|"<<temp->data<<"|->";
              temp=temp->next;
          }
          cout<<"NULL\n";
          
        }

        template <class T3>
        int DoublyLL <T3> :: Count()
        {
            return size;
        }

        template <class T3> 
    int DoublyLL <T3> :: SearchFirstOcc(T3 No)
    {
        if(first!=NULL)
        {
             node <T3> * temp =first;
             int icnt=1;
             while (temp!=NULL)
             {
           
                 if((temp->data)==No)
                 {
                   break;
                 } 
                 icnt++; 
                 temp=temp->next;
             } 

             if(icnt > (size+1)) 
             {
                 return 0;
             } 
             else
             {
                 return icnt;
             }
            
        }
        else
        {
            return -1;
        }

    }

    template <class T3> 
    int DoublyLL <T3> :: SearchLastOcc(T3 No)
    {
        if(first!=NULL)
        {
             node <T3> * temp =first;
             int icnt=1,i=0;
             while (temp!=NULL)
             {
           
                 if((temp->data)==No)
                 {
                   i=icnt;
                 } 
                 icnt++; 
                 temp=temp->next;
             } 

             if(i==0) 
             {
                 return 0;
             } 
             else
             {
                 return i;
             }
            
        }
        else
        {
            return -1;
        }

    }


    template <class T3>
    T3 DoublyLL <T3> :: Addition()
    {
        node <T3> * temp =first;
        T3 iAdd=0;
       while (temp!=NULL)
       {
           iAdd=iAdd+(temp->data);
           temp=temp->next;
       }
       return iAdd;
    }


    template <class T3>
    T3 DoublyLL <T3> :: Maximum()
    {
        node <T3> * temp =first;
        T3 iMax=temp->data;
       while (temp!=NULL)
       {
           if(iMax < (temp->data))
           {
               iMax=(temp->data);
           }
           temp=temp->next;
       }
       return iMax; 
    }

      template <class T3>
    T3 DoublyLL <T3> :: Minimum()
    {
        node <T3> * temp =first;
        T3 iMin=temp->data;
       while (temp!=NULL)
       {
           if(iMin > (temp->data))
           {
               iMin=(temp->data);
           }
           temp=temp->next;
       }
       return iMin; 
    }


int main()
{
       int iSelect=1;


    while(iSelect!=0)
    {
         cout<<"-----Select the Datatype-------\n";
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
            case 0 :  
                         {
                         cout<<"Thank You for Using the application\n";
                         } 
                         break;


            case 1 :
                       {
                             DoublyLL <char> obj;
                             int iRet=0,ichoice=1,ipos=0;
                             char cvalue='\0';

                             while(ichoice!=0)
                             {
                                 cout<<"\n********************************************\n";
                                 cout<<"0 : Terminate the application \n";
                                 cout<<"1 : Insert the node4 at first position \n";
                                 cout<<"2 : Insert the node4 at last position \n";
                                 cout<<"3 : Insert the node4 at desired position \n";
                                 cout<<"4 : Delete the first node4\n";
                                 cout<<"5 : Delete the last node4\n";
                                 cout<<"6 : Delete the node4 at desired position \n";
                                 cout<<"7 : Display the linkedlist \n";
                                 cout<<"8 : Count the node4s int the linked list \n";
                                 cout<<"9 : First Occurance of given element\n";
                                 cout<<"10 : Last Occurance of given element\n";
                                 cout<<"11 : Largest element\n";
                                 cout<<"12 : Smallest element\n";
                                 cin>>ichoice;
                                 cout<<"\n********************************************\n";


                              switch(ichoice)
                              {

                                  case 0 : 
                                             cout<<"Thank You for using th linked list\n";
                                              break;

                                  case 1 : 
                                              cout<<"enter data to insert into the node4\n";
                                              cin>>cvalue;
                                              obj.InsertFirst(cvalue);
                                              break;

                                  case 2 : 
                                              cout<<"enter data to insert into the node4\n";
                                              cin>>cvalue;
                                              obj.InsertLast(cvalue);
                                              break;

                                  case 3 : 
                                             cout<<"enter data to insert into the node4\n";
                                             cin>>cvalue;
                                             cout<<"enter the poistion \n";
                                             cin>>ipos;
                                             obj.InsertAtPos(cvalue,ipos);
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
                                             cout<<"Number of node4s in Linkedlist : "<<iRet<<"\n";
                                             break; 

                                 case 9 :    
                                             cout<<"Enter the element to search\n";
                                             cin>>cvalue;
                                             iRet = obj.SearchFirstOcc(cvalue);
                                             if(iRet==-1)
                                             {
                                                 cout<<"Empty linked list\n";
                                             }
                                             else
                                             {
                                                 cout<<"Element found first at position : "<<iRet<<"\n";
                                             }
                                             break;                       

                                 case 10 :             
                                             cout<<"Enter the element to search\n";
                                             cin>>cvalue;
                                             iRet = obj.SearchLastOcc(cvalue);
                                             if(iRet==-1)
                                             {
                                                 cout<<"Empty linked list\n";
                                             }
                                             else
                                             {
                                                 cout<<"Element found first at position : "<<iRet<<"\n";
                                             }
                                             break;

                                 case 11 : 
                                             cvalue = obj.Maximum();
                                             cout<<"Largest element are :"<<cvalue<<"\n"; 
                                             break;    

                                 case 12 : 
                                             cvalue = obj.Minimum();
                                             cout<<"Smallest element are :"<<cvalue<<"\n"; 
                                             break;                                   
  
                                 default : 
                                             printf("wrong choice\n");
                                             break;     

                                }
                            }         
                        
                       }   break;         


                case 2 :
                       {
                             DoublyLL <int> obj;
                             int iRet=0,ichoice=1,ipos=0,ivalue=0;

                             while(ichoice!=0)
                             {
                                 cout<<"\n********************************************\n";
                                 cout<<"0 : Terminate the application \n";
                                 cout<<"1 : Insert the node4 at first position \n";
                                 cout<<"2 : Insert the node4 at last position \n";
                                 cout<<"3 : Insert the node4 at desired position \n";
                                 cout<<"4 : Delete the first node4\n";
                                 cout<<"5 : Delete the last node4\n";
                                 cout<<"6 : Delete the node4 at desired position \n";
                                 cout<<"7 : Display the linkedlist \n";
                                 cout<<"8 : Count the node4s int the linked list \n";
                                 cout<<"9 : First Occurance of given element\n";
                                 cout<<"10 : Last Occurance of given element\n";
                                 cout<<"11 : Largest element\n";
                                 cout<<"12 : Smallest element\n";
                                 cout<<"13 : Addition of all elements\n";
                                 cin>>ichoice;
                                 cout<<"\n********************************************\n";


                              switch(ichoice)
                              {

                                  case 0 : 
                                             cout<<"Thank You for using th linked list\n";
                                              break;

                                  case 1 : 
                                              cout<<"enter data to insert into the node4\n";
                                              cin>>ivalue;
                                              obj.InsertFirst(ivalue);
                                              break;

                                  case 2 : 
                                              cout<<"enter data to insert into the node4\n";
                                              cin>>ivalue;
                                              obj.InsertLast(ivalue);
                                              break;

                                  case 3 : 
                                             cout<<"enter data to insert into the node4\n";
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
                                             cout<<"Number of node4s in Linkedlist : "<<iRet<<"\n";
                                             break; 

                                 case 9 :    
                                             cout<<"Enter the element to search\n";
                                             cin>>ivalue;
                                             iRet = obj.SearchFirstOcc(ivalue);
                                            if(iRet==-1)
                                             {
                                                 cout<<"Empty linked list\n";
                                             }
                                             else
                                             {
                                                 cout<<"Element found first at position : "<<iRet<<"\n";
                                             }
                                             break;                       

                                 case 10 :             
                                             cout<<"Enter the element to search\n";
                                             cin>>ivalue;
                                             iRet = obj.SearchLastOcc(ivalue);
                                             if(iRet==-1)
                                             {
                                                 cout<<"Empty linked list\n";
                                             }
                                             else
                                             {
                                                 cout<<"Element found first at position : "<<iRet<<"\n";
                                             }
                                             break;

                                 case 11 : 
                                             ivalue = obj.Maximum();
                                             cout<<"Largest element are :"<<ivalue<<"\n"; 
                                             break;    

                                 case 12 : 
                                             ivalue = obj.Minimum();
                                             cout<<"Smallest element are :"<<ivalue<<"\n"; 
                                             break; 

                                 case 13 :   
                                             ivalue = obj.Addition();
                                             cout<<"Addition of all elemets are :"<<ivalue<<"\n"; 
                                             break;                                
  
                                 default : 
                                             printf("wrong choice\n");
                                             break;     

                                }
                            }         
                        
                       }   break;                


                 case 3 :
                       {
                             DoublyLL <float> obj;
                             int iRet=0,ichoice=1,ipos=0;
                             float ivalue=0;

                             while(ichoice!=0)
                             {
                                 cout<<"\n********************************************\n";
                                 cout<<"0 : Terminate the application \n";
                                 cout<<"1 : Insert the node4 at first position \n";
                                 cout<<"2 : Insert the node4 at last position \n";
                                 cout<<"3 : Insert the node4 at desired position \n";
                                 cout<<"4 : Delete the first node4\n";
                                 cout<<"5 : Delete the last node4\n";
                                 cout<<"6 : Delete the node4 at desired position \n";
                                 cout<<"7 : Display the linkedlist \n";
                                 cout<<"8 : Count the node4s int the linked list \n";
                                 cout<<"9 : First Occurance of given element\n";
                                 cout<<"10 : Last Occurance of given element\n";
                                 cout<<"11 : Largest element\n";
                                 cout<<"12 : Smallest element\n";
                                 cout<<"13 : Addition of all elements\n";
                                 cin>>ichoice;
                                 cout<<"\n********************************************\n";


                              switch(ichoice)
                              {

                                  case 0 : 
                                             cout<<"Thank You for using th linked list\n";
                                              break;

                                  case 1 : 
                                              cout<<"enter data to insert into the node4\n";
                                              cin>>ivalue;
                                              obj.InsertFirst(ivalue);
                                              break;

                                  case 2 : 
                                              cout<<"enter data to insert into the node4\n";
                                              cin>>ivalue;
                                              obj.InsertLast(ivalue);
                                              break;

                                  case 3 : 
                                             cout<<"enter data to insert into the node4\n";
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
                                             cout<<"Number of node4s in Linkedlist : "<<iRet<<"\n";
                                             break; 

                                 case 9 :    
                                             cout<<"Enter the element to search\n";
                                             cin>>ivalue;
                                             iRet = obj.SearchFirstOcc(ivalue);
                                            if(iRet==-1)
                                             {
                                                 cout<<"Empty linked list\n";
                                             }
                                             else
                                             {
                                                 cout<<"Element found first at position : "<<iRet<<"\n";
                                             }
                                             break;                       

                                 case 10 :             
                                             cout<<"Enter the element to search\n";
                                             cin>>ivalue;
                                             iRet = obj.SearchLastOcc(ivalue);
                                             if(iRet==-1)
                                             {
                                                 cout<<"Empty linked list\n";
                                             }
                                             else
                                             {
                                                 cout<<"Element found first at position : "<<iRet<<"\n";
                                             }
                                             break;

                                 case 11 : 
                                             ivalue = obj.Maximum();
                                             cout<<"Largest element are :"<<ivalue<<"\n"; 
                                             break;    

                                 case 12 : 
                                             ivalue = obj.Minimum();
                                             cout<<"Smallest element are :"<<ivalue<<"\n"; 
                                             break; 

                                 case 13 :   
                                             ivalue = obj.Addition();
                                             cout<<"Addition of all elemets are :"<<ivalue<<"\n"; 
                                             break;                                
  
                                 default : 
                                             printf("wrong choice\n");
                                             break;     

                                }
                            }         
                        
                       }   break;


                  case 4 :
                       {
                             DoublyLL <double> obj;
                             int iRet=0,ichoice=1,ipos=0;
                             double ivalue=0;

                             while(ichoice!=0)
                             {
                                 cout<<"\n********************************************\n";
                                 cout<<"0 : Terminate the application \n";
                                 cout<<"1 : Insert the node4 at first position \n";
                                 cout<<"2 : Insert the node4 at last position \n";
                                 cout<<"3 : Insert the node4 at desired position \n";
                                 cout<<"4 : Delete the first node4\n";
                                 cout<<"5 : Delete the last node4\n";
                                 cout<<"6 : Delete the node4 at desired position \n";
                                 cout<<"7 : Display the linkedlist \n";
                                 cout<<"8 : Count the node4s int the linked list \n";
                                 cout<<"9 : First Occurance of given element\n";
                                 cout<<"10 : Last Occurance of given element\n";
                                 cout<<"11 : Largest element\n";
                                 cout<<"12 : Smallest element\n";
                                 cout<<"13 : Addition of all elements\n";
                                 cin>>ichoice;
                                 cout<<"\n********************************************\n";


                              switch(ichoice)
                              {

                                  case 0 : 
                                             cout<<"Thank You for using th linked list\n";
                                              break;

                                  case 1 : 
                                              cout<<"enter data to insert into the node4\n";
                                              cin>>ivalue;
                                              obj.InsertFirst(ivalue);
                                              break;

                                  case 2 : 
                                              cout<<"enter data to insert into the node4\n";
                                              cin>>ivalue;
                                              obj.InsertLast(ivalue);
                                              break;

                                  case 3 : 
                                             cout<<"enter data to insert into the node4\n";
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
                                             cout<<"Number of node4s in Linkedlist : "<<iRet<<"\n";
                                             break; 

                                 case 9 :    
                                             cout<<"Enter the element to search\n";
                                             cin>>ivalue;
                                             iRet = obj.SearchFirstOcc(ivalue);
                                             if(iRet==-1)
                                             {
                                                 cout<<"Empty linked list\n";
                                             }
                                             else
                                             {
                                                 cout<<"Element found first at position : "<<iRet<<"\n";
                                             }
                                             break;                       

                                 case 10 :             
                                             cout<<"Enter the element to search\n";
                                             cin>>ivalue;
                                             iRet = obj.SearchLastOcc(ivalue);
                                             if(iRet==-1)
                                             {
                                                 cout<<"Empty linked list\n";
                                             }
                                             else
                                             {
                                                 cout<<"Element found first at position : "<<iRet<<"\n";
                                             }
                                             break;

                                 case 11 : 
                                             ivalue = obj.Maximum();
                                             cout<<"Largest element are :"<<ivalue<<"\n"; 
                                             break;    

                                 case 12 : 
                                             ivalue = obj.Minimum();
                                             cout<<"Smallest element are :"<<ivalue<<"\n"; 
                                             break; 

                                 case 13 :   
                                             ivalue = obj.Addition();
                                             cout<<"Addition of all elemets are :"<<ivalue<<"\n"; 
                                             break;                                
  
                                 default : 
                                             printf("wrong choice\n");
                                             break;     

                                }
                            }         
                        
                       }   break;   


                 default :
                           {
                          cout<<"Wrong choice";
                            } break;
                                                            
     
         }

    }    


    return 0;
}
