#include<iostream>
#include<stdbool.h>
using namespace std;

template <typename T7>
struct node7 
{
   int data;
   struct node7 * right;
   struct node7 * left;
};

template <class T7>
class BST
{
   private:
      node7 <T7> * first;
      int size;

   public:
       
       BST();
       void Insert(T7);
       bool Search(T7);
       void PreOrder();
       void InOrder();
       void PostOrder();
       int Count();

    private :
        void PreOrderF(node7 <T7>*);
        void InOrderF(node7 <T7>*);
        void PostOrderF(node7 <T7>*);
        int CountF(node7 <T7>*);
};

template <class T7>
BST <T7> :: BST()
{
   first=NULL;
   size=0;
  
}

template <class T7>
void BST <T7> :: Insert(T7 No)
{
   node7 <T7> * newn = new node7 <T7>;
   newn->data=No;
   newn->left=NULL;
   newn->right=NULL;

   if(first==NULL)
   {
      first=newn;
   }
   else
   {
      node7<T7> * temp = first;

      while(1)
      {
         if(No == (temp->data))
         {
            delete newn;
            break;
         }
         else if(No > (temp->data))
         {
            if((temp->right)==NULL)
            {
               temp->right=newn;
               break;
            }
             temp=temp->right ; 
         }
         else if (No < (temp->data))
         {
            if((temp->left)==NULL)
            {
               temp->left=newn;
               break;
            }
            temp=temp->left;
         }
         
      }
   }
}

template <class T7>
bool BST <T7> :: Search(T7 No)
{
   if(first!=NULL)
   {
      node7 <T7>* temp=first;
      bool flag=false;
      while(temp!=NULL)
      {
         if(No == (temp->data))
         {
            flag=true;
            break;
         }
         else if(No > (temp->data) )
         {
            temp=temp->right;
         }
         else if(No < (temp->data))
         {
            temp=temp->left;
         }
      }
      if(temp==NULL)
      {
         return false;
      }
      else
      {
         return flag;
      }

   }
   else
   {
      return false;
   }
}

template <class T7>
void BST <T7> ::PreOrderF(node7 <T7> * temp)
{ 
    if(temp!=NULL)
     {
         if(temp!=NULL)
         {
             cout<<temp->data<<"\t";  
             PreOrderF(temp->left);
             PreOrderF(temp->right);
         }

     }
     else
     {
         return;
     }
}

template <class T7>
void BST<T7> ::InOrderF(node7 <T7> * temp)
{ 
     if(temp!=NULL)
     {
         if(temp!=NULL)
         {
             InOrderF(temp->left);
             cout<<temp->data<<"\t";
             InOrderF(temp->right);
         }
     }
     else
     {
         return;
     }
}

template <class T7>
void BST<T7> ::PostOrderF(node7 <T7> * temp)
{ 
     if(temp!=NULL)
     {
         if(temp!=NULL)
         {
             PostOrderF(temp->left);
             PostOrderF(temp->right);
             cout<<temp->data<<"\t";  
         }
     }
     else
     {
         return;
     }
}

template <class T7>
void BST <T7> :: PreOrder()
{
   PreOrderF(first);
} 
template <class T7>
void BST <T7> :: InOrder()
{
   InOrderF(first);
} 
template <class T7>
void BST <T7> :: PostOrder()
{
   PostOrderF(first);
} 

template <class T7>
int BST <T7> :: CountF(node7 <T7> * temp)
{
     static int icnt=0;
   if(temp!=NULL)
   {
     
      if(temp!=NULL)
      {
          icnt++;
          CountF(temp->left);
          CountF(temp->right);
      } 
   }
   return icnt;
}

template <class T7>
int BST <T7> :: Count()
{
   int iRet = CountF(first);
   return iRet;
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
                             BST <char> obj;
                             int iRet=0,ichoice=1;
                             bool bRet=false;
                             char cvalue='\0';

                             while(ichoice!=0)
                             {
                                 cout<<"\n********************************************\n";
                                 cout<<"0 : Terminate the application \n";
                                 cout<<"1 : Insert the node at tree \n";
                                 cout<<"2 : Search the element in the tree\n";
                                 cout<<"3 : Display PreOrder \n";
                                 cout<<"4 : Display InOrder\n";
                                 cout<<"5 : Display PostOrder\n";
                                 cout<<"6 : count the all elements \n";
                                 cin>>ichoice;
                                 cout<<"\n********************************************\n";


                              switch(ichoice)
                              {

                                  case 0 : 
                                             cout<<"Thank You for using th Binary Search Tree\n";
                                              break;

                                  case 1 : 
                                              cout<<"enter data to insert into the node\n";
                                              cin>>cvalue;
                                              obj.Insert(cvalue);
                                              break;

                                  case 2 : 
                                              cout<<"enter data to Search\n";
                                              cin>>cvalue;
                                              bRet = obj.Search(cvalue);
                                              if(bRet == true)
                                              {
                                                  cout<<"Number is Present";
                                              }
                                              else
                                              { 
                                                  cout<<"Number is Not Present";
                                              }
                                              break;

                                  case 3 : 
                                             obj.PreOrder();
                                              break;                       

                                  case 4 : 
                                             obj.InOrder();
                                             break;

                                  case 5 : 
                                             obj.PostOrder();
                                              break;   

                                 case 6 : 
                                             iRet = obj.Count();
                                             cout<<"Number of elements are :"<<iRet<<"\n";
                                             break;                
  
                                 default : 
                                             printf("wrong choice\n");
                                             break;     

                                }
                            }         
                        
                       }   break;         


                case 2 :
                       {
                             BST <int> obj;
                             int iRet=0,ichoice=1,ipos=0,ivalue=0;
                             bool bRet=false;

                             while(ichoice!=0)
                             {
                                 cout<<"\n********************************************\n";
                                 cout<<"0 : Terminate the application \n";
                                 cout<<"1 : Insert the node at tree \n";
                                 cout<<"2 : Search the element in the tree\n";
                                 cout<<"3 : Display PreOrder \n";
                                 cout<<"4 : Display InOrder\n";
                                 cout<<"5 : Display PostOrder\n";
                                 cout<<"6 : count the all elements \n";
                                 cin>>ichoice;
                                 cout<<"\n********************************************\n";


                              switch(ichoice)
                              {

                                  case 0 : 
                                             cout<<"Thank You for using th Binary Search Tree\n";
                                              break;

                                  case 1 : 
                                              cout<<"enter data to insert into the node\n";
                                              cin>>ivalue;
                                              obj.Insert(ivalue);
                                              break;

                                  case 2 : 
                                              cout<<"enter data to Search\n";
                                              cin>>ivalue;
                                              bRet = obj.Search(ivalue);
                                              if(bRet == true)
                                              {
                                                  cout<<"Number is Present";
                                              }
                                              else
                                              { 
                                                  cout<<"Number is Not Present";
                                              }

                                              break;

                                  case 3 : 
                                             obj.PreOrder();
                                              break;                       

                                  case 4 : 
                                             obj.InOrder();
                                             break;

                                  case 5 : 
                                             obj.PostOrder();
                                              break;   

                                 case 6 : 
                                             iRet = obj.Count();
                                             cout<<"Number of elements are :"<<iRet<<"\n";
                                             break;                
  
                                 default : 
                                             printf("wrong choice\n");
                                             break;     

                                }
                            }         
                        
                       }   break;                


                 case 3 :
                       {     BST <float> obj;
                             int iRet=0,ichoice=1;
                             bool bRet=false;
                             float fvalue=0.00;

                             while(ichoice!=0)
                             {
                                 cout<<"\n********************************************\n";
                                 cout<<"0 : Terminate the application \n";
                                 cout<<"1 : Insert the node at tree \n";
                                 cout<<"2 : Search the element in the tree\n";
                                 cout<<"3 : Display PreOrder \n";
                                 cout<<"4 : Display InOrder\n";
                                 cout<<"5 : Display PostOrder\n";
                                 cout<<"6 : count the all elements \n";
                                 cin>>ichoice;
                                 cout<<"\n********************************************\n";


                              switch(ichoice)
                              {

                                  case 0 : 
                                             cout<<"Thank You for using th Binary Search Tree\n";
                                              break;

                                  case 1 : 
                                              cout<<"enter data to insert into the node\n";
                                              cin>>fvalue;
                                              bRet = obj.Search(fvalue);
                                              if(bRet == true)
                                              {
                                                  cout<<"Number is Present";
                                              }
                                              else
                                              { 
                                                  cout<<"Number is Not Present";
                                              }
                                              break;

                                  case 2 : 
                                              cout<<"enter data to Search\n";
                                              cin>>fvalue;
                                              obj.Search(fvalue);
                                              break;

                                  case 3 : 
                                             obj.PreOrder();
                                              break;                       

                                  case 4 : 
                                             obj.InOrder();
                                             break;

                                  case 5 : 
                                             obj.PostOrder();
                                              break;   

                                 case 6 : 
                                             iRet = obj.Count();
                                             cout<<"Number of elements are :"<<iRet<<"\n";
                                             break;                
  
                                 default : 
                                             printf("wrong choice\n");
                                             break;     

                                }
                            }         
                        
                       }   break;   


                 case 4 :
                       {     BST <double> obj;
                             int iRet=0,ichoice=1;
                             bool bRet=false;
                             double dvalue=0.00;

                             while(ichoice!=0)
                             {
                                 cout<<"\n********************************************\n";
                                 cout<<"0 : Terminate the application \n";
                                 cout<<"1 : Insert the node at tree \n";
                                 cout<<"2 : Search the element in the tree\n";
                                 cout<<"3 : Display PreOrder \n";
                                 cout<<"4 : Display InOrder\n";
                                 cout<<"5 : Display PostOrder\n";
                                 cout<<"6 : count the all elements \n";
                                 cin>>ichoice;
                                 cout<<"\n********************************************\n";


                              switch(ichoice)
                              {

                                  case 0 : 
                                             cout<<"Thank You for using th Binary Search Tree\n";
                                              break;

                                  case 1 : 
                                              cout<<"enter data to insert into the node\n";
                                              cin>>dvalue;
                                              obj.Insert(dvalue);
                                              break;

                                  case 2 : 
                                              cout<<"enter data to Search\n";
                                              cin>>dvalue;
                                              bRet = obj.Search(dvalue);
                                              if(bRet == true)
                                              {
                                                  cout<<"Number is Present";
                                              }
                                              else
                                              { 
                                                  cout<<"Number is Not Present";
                                              }
                                              break;

                                  case 3 : 
                                             obj.PreOrder();
                                              break;                       

                                  case 4 : 
                                             obj.InOrder();
                                             break;

                                  case 5 : 
                                             obj.PostOrder();
                                              break;   

                                 case 6 : 
                                             iRet = obj.Count();
                                             cout<<"Number of elements are :"<<iRet<<"\n";
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
