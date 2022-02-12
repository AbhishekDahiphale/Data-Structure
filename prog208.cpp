#include<iostream>
using namespace std;

int SumI(int iNo)
{
    int isum=0;

    while(iNo!=0)
    {
        isum=isum+(iNo%10);
        iNo=iNo/10;
    }
    return isum;
}


int SumR(int iNo)
{
  static int isum=0;

    if(iNo!=0)
    {
        isum=isum+(iNo%10);
        iNo=iNo/10;
        SumR(iNo);
    }
    return isum;
}


int main()
{
   int x=0,iRet=0;

   cout<<"Enter the number\n";
   cin>>x;

   iRet=SumR(x);

   cout<<"Summation of digits are : "<<iRet<<"\n";
    return 0;
}
