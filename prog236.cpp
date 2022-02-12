#include<iostream>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;

class ArrayX
{
    public:
      int * Arr;
      int size;

      ArrayX(int size)
      {
         this->size=size;
         Arr = new int[size];
      } 

      void Accept()
      {
          int i=0;
          for(i=0;i<size;i++)
          {
              cin>>Arr[i];
          }
      }

      void Display()
      {
          int i=0;
          for(i=0;i<size;i++)
          {
              cout<<Arr[i]<<"\t";
          }
          cout<<"\n";
      }

      virtual void BubbleSort()=0;
};

class Sorting : public ArrayX
{
    public:

     Sorting(int size) : ArrayX(size)
     {}

     void BubbleSort()
     {
         int pass=0,j=0;
         int temp=0;
         bool flag = false;
         for(pass=0,flag=true;((pass<size) && (flag==true));pass++)
         {
            
            for(j=0,flag=false;j<((size-pass)-1);j++)
            {
                 if(Arr[j] > Arr[j+1])
                 {
                     flag = true;
                    temp = Arr[j];
                    Arr[j] = Arr[j+1];
                    Arr[j+1] = temp;
                 }
            }
            if(flag == false)
                break;            
         }
         
     }
    
};

int main()
{
    int ivalue=0;
    cout<<"Enter the size\n";
    cin>>ivalue;
    ArrayX *obj = new Sorting(ivalue);
    obj->Accept();
    obj->Display();
    obj->BubbleSort();
    cout<<"After the BubbleSort : \n";
    obj->Display();
    return 0;
}