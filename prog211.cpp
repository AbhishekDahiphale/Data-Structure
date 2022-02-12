#include<iostream>
using namespace std;

class Array
{
    public:
      int isize;
      int * Arr;

     Array(int iNo)
     {
         this->isize=iNo;
         Arr=new int[isize];
     }

     ~Array()
     {    
         delete []Arr;
     }

     void Accept()
     {
         int i=0;
         for(i=0;i < isize;i++)
         {
            cin>>Arr[i];
         }
     }
     
     void Display()
     {
        
         int i=0;
        for(i=0;i<isize;i++)
        {
            cout<<Arr[i]<<"\t";
        }
     }
     
     int sumI()
     {
       int i=0,isum=0;
       for(i=0;i<isize;i++)
       {
        isum=isum+(Arr[i]);
       }
       return isum;
    }
    
    int sumw()
     {
      int i=0,isum=0;
       while(i<isize)
      {
        isum=isum+Arr[i];
        i++;
      }
       return isum; 
    }
    
     int sumR()
     {
      static int i=0,isum=0;
       if(i<isize)
      {
        isum=isum+Arr[i];
        i++;
        sumR();
      }
       return isum; 
    }

};




int main()
{
    int ivalue=0,iRet=0;
    cout<<"How many elements\t";
    cin>>ivalue;

    Array obj(ivalue);
    
    cout<<" enter elements\n";
    obj.Accept();
    cout<<" elements are :\n";
    obj.Display();
    cout<<"\n";

    iRet=obj.sumR();
    cout<<"sum of elements are : "<<iRet<<"\n";
 
   

    return 0;
}
