#include<iostream>
using namespace std;

int sumI(int Arr[],int isize)
{
    int i=0,isum=0;
     for(i=0;i<isize;i++)
    {
        isum=isum+Arr[i];
    }
    return isum;
 
   
}

int main()
{
     int x=0,iRet=0,i=0,isum=0;
     int *p=NULL;

     cout<<"How many numbers\n";
     cin>>x;
  
     p=new int [x];
     
    cout<<"Eneter the elements\n";

    for(i=0;i<x;i++)
    {
        cin>>p[i];
    }
 
     iRet=sumI(p,x);
     cout<<"Summation of all elements : "<<iRet<<"\n";

     delete []p;

    return 0;
}
