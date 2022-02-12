#include<iostream>
#include<stdlib.h>
using namespace std;


template <typename T2>
struct node2
{
    T2 data;
    struct node2 * next;
};

template <class T2>
class ScircularLL
{
    private:
         node2 <T2> * Head;
         node2 <T2> * Tail;
         int size;

    public:
         ScircularLL();
         void InsertFirst(T2);
         void InsertLast(T2);
         void InsertAtPos(T2,int);
         void DeleteFirst();
         void DeleteLast();
         void DeleteAtPos(int);
         void Display();
         int  Count();
         int SearchFirstOcc(T2);
         int SearchLastOcc(T2);
         T2 Addition();
         T2 Maximum();
         T2 Minimum();
};
        template <class T2>
        ScircularLL <T2> :: ScircularLL()
         {
             Head=NULL;
             Tail=NULL;
             size=0;
         }   

         template <class T2>
         void ScircularLL <T2> :: InsertFirst(T2 No)
         {
             node2 <T2> * newn =new node2 <T2>;
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

         template <class T2>
         void ScircularLL <T2> :: InsertLast(T2 No)
         {
              node2 <T2> * newn =new node2 <T2>;
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
 
         template <class T2> 
         void ScircularLL <T2> :: InsertAtPos(T2 No,int pos)
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
                 node2 <T2> * newn=new node2 <T2>;
                 newn->data=No;
                 newn->next=NULL;

                 node2 <T2> * temp=Head;
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

         template <class T2>
         void ScircularLL <T2> :: DeleteFirst()
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

         template <class T2>
         void ScircularLL <T2> :: DeleteLast()
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
                     node2 <T2> * temp=Head;
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

         template <class T2>
         void ScircularLL <T2> :: DeleteAtPos(int pos)
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
                 node2 <T2> * temp=Head;
                 node2 <T2> * target=NULL;
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
          
         template <class T2>
         void ScircularLL <T2> :: Display()
         {
             if(size!=0)
             {
                 node2 <T2> * temp=Head;
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

         template <class T2>
         int ScircularLL <T2> :: Count()
         {
             return size;
         }

             template <class T2> 
             int ScircularLL <T2> :: SearchFirstOcc(T2 No)
            {
                 if(Head!=NULL)
                 {
                     node2 <T2> * temp =Head;
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

             template <class T2> 
             int ScircularLL <T2> :: SearchLastOcc(T2 No)
            {
                 if(Head!=NULL)
                 {
                     node2 <T2> * temp =Head;
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


             template <class T2> 
             T2 ScircularLL <T2> :: Addition()
            {
                 if(Head!=NULL)
                 {
                     node2 <T2> * temp =Head;
                     T2 Add;
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

            template <class T2> 
             T2 ScircularLL <T2> :: Maximum()
            {
                 if(Head!=NULL)
                 {
                     node2 <T2> * temp =Head;
                     T2 iMax;
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

            template <class T2> 
             T2 ScircularLL <T2> :: Minimum()
            {
                 if(Head!=NULL)
                 {
                     node2 <T2> * temp =Head;
                     T2 iMin;
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
                             ScircularLL <char> obj;
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
                             ScircularLL <int> obj;
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
                             ScircularLL <float> obj;
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
                             ScircularLL <double> obj;
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
