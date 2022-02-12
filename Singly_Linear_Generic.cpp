#include<iostream>
#include<stdlib.h>
using namespace std;

template <typename T1>
struct node1
{
    T1 data;
    struct node1 * next;
};


template <class T1>
class SinglyLL
{
   private:
     node1 <T1> * first;
     int size;

   public:
      SinglyLL();
     void InsertFirst(T1);
     void InsertLast(T1);
     void InsertAtPos(T1,int);
     void DeleteFirst();
     void DeleteLast();
     void DeleteAtPos(int);
     void Display();
     int  Count();
     int SearchFirstOcc(T1);
     int SearchLastOcc(T1);
     T1 Addition();
     T1 Maximum();
     T1 Minimum();
 
};

  template <class T1>
  SinglyLL <T1> :: SinglyLL()
    {
        first=NULL;
        size=0;
    }  

    template <class T1>  
    void SinglyLL <T1> :: InsertFirst(T1 No)
    {
      node1 <T1> * newn=new node1 <T1>;
      
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

    template <class T1>
    void SinglyLL <T1> :: InsertLast(T1 No)
    {
       node1 <T1> * newn=new node1 <T1>;

        newn->data=No;
        newn->next=NULL;

      if(first==NULL)
      {
          first=newn;
      }
      else
      {
         node1 <T1> * temp = first;
         
         while(temp->next!=NULL)
         {
             temp=temp->next;
         }
         temp->next=newn;
      }
      size++;

    }

    template <class T1>
    void SinglyLL <T1> :: InsertAtPos(T1 No,int pos)
    {
       if( (pos < 1) || (pos > (size +1)) )
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
           node1 <T1> * newn=new node1 <T1>;
           newn->data=No;
           newn->next=NULL;

           node1 <T1> * temp = first;
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

    template <class T1>
    void SinglyLL <T1> :: DeleteFirst()
    {
       node1 <T1> * temp=first;

        if(first!=NULL)
        {
            if((first->next)==NULL)
            {
                  delete (first);
                  first=NULL;
            }
            else
            {
                 first=first->next;
                 delete temp;
                 size--;

            }
            
        }
        else
        {
            return;
        }
    }

    template <class T1>
    void SinglyLL <T1> :: DeleteLast()
    {
       node1 <T1> * temp=first;

      if(first!=NULL)
      {
         if(first->next==NULL)
         {
             delete first;
             first=NULL;
             size--;
         }
         else
         {
             int i=1;
             while(i!=(size-1))
             {
               i++;
               temp=temp->next;
             }
             delete(temp->next);
             temp->next=NULL;
             size--;
         }
      }
      else
      {
          return;
      }
    }

    template <class T1>
    void SinglyLL <T1> :: DeleteAtPos(int pos)
    {
        if( (pos < 1) || (pos > (size+1)) )
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
             node1 <T1> * temp=first;
             node1 <T1> * target=NULL;
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

    template <class T1>
    void SinglyLL <T1> :: Display()
    {
        if(first==NULL)
        {
            cout<<"Linked list is empty\n";
        }
       else
       {
           node1 <T1> * temp =first;

              while (temp!=NULL)
             {
                 cout<<"|"<<temp->data<<"|->";
                 temp=temp->next;
              }
                 cout<<"NULL\n";
       }
       
    }

    template <class T1>
    int SinglyLL <T1> :: Count()
    {
       return size;
    }

    template <class T1> 
    int SinglyLL <T1> :: SearchFirstOcc(T1 No)
    {
        if(first!=NULL)
        {
             node1 <T1> * temp =first;
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

    template <class T1> 
    int SinglyLL <T1> :: SearchLastOcc(T1 No)
    {
        if(first!=NULL)
        {
             node1 <T1> * temp =first;
             int icnt=1,i=0;;
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

    template <class T1>
    T1 SinglyLL <T1> :: Addition()
    {
        node1 <T1> * temp =first;
        T1 iAdd=0;
       while (temp!=NULL)
       {
           iAdd=iAdd+(temp->data);
           temp=temp->next;
       }
       return iAdd;
    }

    template <class T1>
    T1 SinglyLL <T1> :: Maximum()
    {
        node1 <T1> * temp =first;
        T1 iMax=temp->data;
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

    template <class T1>
    T1 SinglyLL <T1> :: Minimum()
    {
         node1 <T1> * temp =first;
         T1 iMin=temp->data;
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




///////////////////////////////////////

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
                             SinglyLL <char> obj;
                             int iRet=0,ichoice=1,ipos=0;
                             char cvalue='\0';

                             while(ichoice!=0)
                             {
                                 cout<<"\n********************************************\n";
                                 cout<<"0 : Terminate the application \n";
                                 cout<<"1 : Insert the node1 at first position \n";
                                 cout<<"2 : Insert the node1 at last position \n";
                                 cout<<"3 : Insert the node1 at desired position \n";
                                 cout<<"4 : Delete the first node1\n";
                                 cout<<"5 : Delete the last node1\n";
                                 cout<<"6 : Delete the node1 at desired position \n";
                                 cout<<"7 : Display the linkedlist \n";
                                 cout<<"8 : Count the node1s int the linked list \n";
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
                                              cout<<"enter data to insert into the node1\n";
                                              cin>>cvalue;
                                              obj.InsertFirst(cvalue);
                                              break;

                                  case 2 : 
                                              cout<<"enter data to insert into the node1\n";
                                              cin>>cvalue;
                                              obj.InsertLast(cvalue);
                                              break;

                                  case 3 : 
                                             cout<<"enter data to insert into the node1\n";
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
                                             cout<<"Number of node1s in Linkedlist : "<<iRet<<"\n";
                                             break;          

                                 case 9 :    
                                             cout<<"Enter the element to search\n";
                                             cin>>cvalue;
                                             iRet = obj.SearchFirstOcc(cvalue);
                                             cout<<"Element found first at position : "<<iRet<<"\n";
                                             break;                       

                                 case 10 :             
                                             cout<<"Enter the element to search\n";
                                             cin>>cvalue;
                                             iRet = obj.SearchLastOcc(cvalue);
                                             cout<<"Element found Last at position : "<<iRet<<"\n";
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
                             SinglyLL <int> obj;
                             int iRet=0,ichoice=1,ipos=0,ivalue=0;

                             while(ichoice!=0)
                             {
                                 cout<<"\n********************************************\n";
                                 cout<<"0 : Terminate the application \n";
                                 cout<<"1 : Insert the node1 at first position \n";
                                 cout<<"2 : Insert the node1 at last position \n";
                                 cout<<"3 : Insert the node1 at desired position \n";
                                 cout<<"4 : Delete the first node1\n";
                                 cout<<"5 : Delete the last node1\n";
                                 cout<<"6 : Delete the node1 at desired position \n";
                                 cout<<"7 : Display the linkedlist \n";
                                 cout<<"8 : Count the node1s int the linked list \n";
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
                                              cout<<"enter data to insert into the node1\n";
                                              cin>>ivalue;
                                              obj.InsertFirst(ivalue);
                                              break;

                                  case 2 : 
                                              cout<<"enter data to insert into the node1\n";
                                              cin>>ivalue;
                                              obj.InsertLast(ivalue);
                                              break;

                                  case 3 : 
                                             cout<<"enter data to insert into the node1\n";
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
                                             cout<<"Number of node1s in Linkedlist : "<<iRet<<"\n";
                                             break;

                                 case 9 :    
                                             cout<<"Enter the element to search\n";
                                             cin>>ivalue;
                                             iRet = obj.SearchFirstOcc(ivalue);
                                             cout<<"Element found first at position : "<<iRet<<"\n";
                                             break;                       

                                 case 10 :             
                                             cout<<"Enter the element to search\n";
                                             cin>>ivalue;
                                             iRet = obj.SearchLastOcc(ivalue);
                                             cout<<"Element found Last at position : "<<iRet<<"\n";
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
                             SinglyLL <float> obj;
                             int iRet=0,ichoice=1,ipos=0;
                             float ivalue=0;

                             while(ichoice!=0)
                             {
                                 cout<<"\n********************************************\n";
                                 cout<<"0 : Terminate the application \n";
                                 cout<<"1 : Insert the node1 at first position \n";
                                 cout<<"2 : Insert the node1 at last position \n";
                                 cout<<"3 : Insert the node1 at desired position \n";
                                 cout<<"4 : Delete the first node1\n";
                                 cout<<"5 : Delete the last node1\n";
                                 cout<<"6 : Delete the node1 at desired position \n";
                                 cout<<"7 : Display the linkedlist \n";
                                 cout<<"8 : Count the node1s int the linked list \n";
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
                                              cout<<"enter data to insert into the node1\n";
                                              cin>>ivalue;
                                              obj.InsertFirst(ivalue);
                                              break;

                                  case 2 : 
                                              cout<<"enter data to insert into the node1\n";
                                              cin>>ivalue;
                                              obj.InsertLast(ivalue);
                                              break;

                                  case 3 : 
                                             cout<<"enter data to insert into the node1\n";
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
                                             cout<<"Number of node1s in Linkedlist : "<<iRet<<"\n";
                                             break;  

                                 case 9 :    
                                             cout<<"Enter the element to search\n";
                                             cin>>ivalue;
                                             iRet = obj.SearchFirstOcc(ivalue);
                                             cout<<"Element found first at position : "<<iRet<<"\n";
                                             break;                       

                                 case 10 :             
                                             cout<<"Enter the element to search\n";
                                             cin>>ivalue;
                                             iRet = obj.SearchLastOcc(ivalue);
                                             cout<<"Element found Last at position : "<<iRet<<"\n";
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
                             SinglyLL <double> obj;
                             int iRet=0,ichoice=1,ipos=0;
                             double ivalue=0;

                             while(ichoice!=0)
                             {
                                 cout<<"\n********************************************\n";
                                 cout<<"0 : Terminate the application \n";
                                 cout<<"1 : Insert the node1 at first position \n";
                                 cout<<"2 : Insert the node1 at last position \n";
                                 cout<<"3 : Insert the node1 at desired position \n";
                                 cout<<"4 : Delete the first node1\n";
                                 cout<<"5 : Delete the last node1\n";
                                 cout<<"6 : Delete the node1 at desired position \n";
                                 cout<<"7 : Display the linkedlist \n";
                                 cout<<"8 : Count the node1s int the linked list \n";
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
                                              cout<<"enter data to insert into the node1\n";
                                              cin>>ivalue;
                                              obj.InsertFirst(ivalue);
                                              break;

                                  case 2 : 
                                              cout<<"enter data to insert into the node1\n";
                                              cin>>ivalue;
                                              obj.InsertLast(ivalue);
                                              break;

                                  case 3 : 
                                             cout<<"enter data to insert into the node1\n";
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
                                             cout<<"Number of node1s in Linkedlist : "<<iRet<<"\n";
                                             break;

                                 case 9 :    
                                             cout<<"Enter the element to search\n";
                                             cin>>ivalue;
                                             iRet = obj.SearchFirstOcc(ivalue);
                                             cout<<"Element found first at position : "<<iRet<<"\n";
                                             break;                       

                                 case 10 :             
                                             cout<<"Enter the element to search\n";
                                             cin>>ivalue;
                                             iRet = obj.SearchLastOcc(ivalue);
                                             cout<<"Element found Last at position : "<<iRet<<"\n";
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
