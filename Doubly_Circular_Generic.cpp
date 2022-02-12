#include<iostream>
#include<stdlib.h>
using namespace std;

template <typename T4>
struct node4
{
     T4 data;
     struct node4 *next;
     struct node4 *prev;
};


template <class T4>
class DcircularLL
{
   private :
         node4 <T4> * Head;
         node4 <T4> * Tail;
         int size;

    public:
          DcircularLL();
          void InsertFirst(T4); 
          void InsertLast(T4);
          void InsertAtPos(T4,int);
          void DeleteFirst();
          void DeleteLast();
          void DeleteAtPos(int);
          void Display();
          int Count();
          int SearchFirstOcc(T4);
         int SearchLastOcc(T4);
         T4 Addition();
         T4 Maximum();
         T4 Minimum(); 
};   
        
         template <class T4>  
         DcircularLL <T4> :: DcircularLL()
          {
              Head=NULL;
              Tail=NULL;
              size=0;
          }  


          template <class T4>  
          void DcircularLL <T4> :: InsertFirst(T4 No)
          {
               node4 <T4> * newn=new node4 <T4>;
               newn->data=No;
               newn->next=NULL;
               newn->prev=NULL;

              if((Head==NULL) && (Tail==NULL))
               {
                   Head=newn;
                   Tail=newn;
               }
               else
               {
                   newn->next=Head;
                   Head->prev=newn;
                   Head=newn;
               }
                 Head->prev=Tail;
                 Tail->next=Head;
                 size++;
          }  
          
          template <class T4>  
          void DcircularLL <T4> :: InsertLast(T4 No)
          {
                node4 <T4> * newn=new node4 <T4>;
               newn->data=No;
               newn->next=NULL;
               newn->prev=NULL;

               if((Head==NULL) && (Tail==NULL))
               {
                   Head=newn;
                   Tail=newn;
               }
               else
               {
                   Tail->next=newn;
                   newn->prev=Tail;
                   Tail=newn;
               }
                 Head->prev=Tail;
                 Tail->next=Head;
                 size++;
              
          } 
           
          template <class T4>  
          void DcircularLL <T4> :: InsertAtPos(T4 No,int pos)
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
                  InsertLast(No); 
              }
              else
              {
                  node4 <T4> * newn=new node4 <T4>;
                  newn->data=No;
                  newn->next=NULL;
                  newn->prev=NULL;

                  node4 <T4> * temp=Head;
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

                 Head->prev=Tail;
                 Tail->next=Head;
              }
          }

          template <class T4>  
          void DcircularLL <T4> :: DeleteFirst()
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
                      delete(Head->prev);
                      Head->prev=Tail;
                      Tail->next=Head;
                  }
                    
                  size--;
              }
              else
              {
                  return;
              }
          }

          template <class T4>  
          void DcircularLL <T4> :: DeleteLast()
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
                      Tail=Tail->prev;
                      delete(Tail->next);
                      Tail->next=Head;
                      Head->prev=Tail;

                  }
                  size--;
              }
              else
              {
                  return;
              }
          }

          template <class T4>    
          void DcircularLL <T4> :: DeleteAtPos(int pos)
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
                  node4 <T4> * temp=Head;
                  int i=1;
                  while(i!=(pos-1))
                  {
                      i++;
                      temp=temp->next;
                  }
                  temp->next=temp->next->next;
                  delete(temp->next->prev);
                  temp->next->prev=temp;

                  /*
                   while(i!=pos)
                   {
                       temp=temp->next;
                   }
                   temp->prev->next=temp->next;
                   temp->next->prev=temp->prev;
                   delete(temp);

                  */
                  size--;
                      Tail->next=Head;
                      Head->prev=Tail;
              }
          }

          template <class T4>  
          void DcircularLL <T4> :: Display()
          {
              if(size!=0)
             {
                 node4 <T4> * temp=Head;
                 do
                 {
                      cout<<" <-|"<<temp->data<<"|-> ";
                      temp=temp->next;
                  }while(temp!=(Tail->next));
                  cout<<"\n";

                 /*
                   ** using for loop **
                  for(int i=1;i<=size;i++)
                  {
                      cout<<" <-|"<<temp->data<<"|-> ";
                      temp=temp->next;   
                  }
                  cout<<"\n";

                  */
             }
             else
             {
                 return;
             }
               
              
          }

          template <class T4>  
          int DcircularLL <T4> :: Count()
          {
              return size;
          }


          template <class T4> 
             int DcircularLL <T4> :: SearchFirstOcc(T4 No)
            {
                 if(Head!=NULL)
                 {
                     node4 <T4> * temp =Head;
                     int icnt=1;
                     do
                     {
           
                         if((temp->data)==No)
                         {
                             break;
                         } 
                         icnt++; 
                         temp=temp->next;
                     }while (temp!=(Tail->next)); 

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

            template <class T4> 
             int DcircularLL <T4> :: SearchLastOcc(T4 No)
            {
                 if(Head!=NULL)
                 {
                     node4 <T4> * temp =Head;
                     int icnt=1,i=0;
                     do
                     {
           
                         if((temp->data)==No)
                         {
                             i=icnt;
                         } 
                         icnt++; 
                         temp=temp->next;
                     }while (temp!=(Tail->next)); 

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

            template <class T4> 
             T4 DcircularLL <T4> :: Addition()
            {
                 if(Head!=NULL)
                 {
                     node4 <T4> * temp =Head;
                     T4 Add;
                     int icnt=1,i=0;
                     do
                     {
                        Add = Add + (temp->data);  
                        temp=temp->next; 
                     }while (temp!=(Tail->next));

                     return Add; 

                 }
                 else
                 {
                    return -1;
                  }

            }  

            template <class T4> 
             T4 DcircularLL <T4> :: Maximum()
            {
                 if(Head!=NULL)
                 {
                     node4 <T4> * temp =Head;
                     T4 iMax=temp->data;
                     int icnt=1,i=0;
                     do
                     {
                        if(iMax < (temp->data))
                        {
                            iMax = (temp->data);
                        }   
                        temp=temp->next;
                     }while (temp!=(Tail->next));

                     return iMax; 

                 }
                 else
                 {
                    return -1;
                  }

            }  

            template <class T4> 
             T4 DcircularLL <T4> :: Minimum()
            {
                 if(Head!=NULL)
                 {
                     node4 <T4> * temp =Head;
                     T4 iMin= temp->data;
                     int icnt=1,i=0;
                     do
                     {
                        if(iMin > (temp->data))
                        {
                            iMin = (temp->data);
                        }   
                        temp=temp->next;
                     }while (temp!=(Tail->next));

                     return iMin; 

                 }
                 else
                 {
                    return -1;
                  }

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
                             DcircularLL <char> obj;
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
                                 cout<<"9 : First Occurance of givaen element\n";
                                 cout<<"10 : Last Occurance of givaen element\n";
                                 cout<<"11 : Largest Element\n";
                                 cout<<"12 : Smallest Element\n";
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
                             DcircularLL <int> obj;
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
                                 cout<<"9 : First Occurance of givaen element\n";
                                 cout<<"10 : Last Occurance of givaen element\n";
                                 cout<<"11 : Largest Element\n";
                                 cout<<"12 : Smallest Element\n";
                                 cout<<"13 : Addition of all Elements\n";
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
                             DcircularLL <float> obj;
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
                                 cout<<"9 : First Occurance of givaen element\n";
                                 cout<<"10 : Last Occurance of givaen element\n";
                                 cout<<"11 : Largest Element\n";
                                 cout<<"12 : Smallest Element\n";
                                 cout<<"13 : Addition of all Elements\n";
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
                             DcircularLL <double> obj;
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
                                 cout<<"9 : First Occurance of givaen element\n";
                                 cout<<"10 : Last Occurance of givaen element\n";
                                 cout<<"11 : Largest Element\n";
                                 cout<<"12 : Smallest Element\n";
                                 cout<<"13 : Addition of all Elements\n";
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
