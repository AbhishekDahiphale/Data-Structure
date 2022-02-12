#include<iostream>
using namespace std;

int factI(int iNo)
{
    int ifact=1;

    while(iNo!=0)
    {
        ifact=ifact*(iNo);
        iNo--;
    }
    return ifact;
}


int factR(int iNo)
{
   static int ifact=1;

    if(iNo!=0)
    {
        ifact=ifact*(iNo);
        iNo--;
        factR(iNo);
    }
    return ifact;
}



int main()
{
   int x=0,iRet=0;

   cout<<"Enter the number\n";
   cin>>x;

   iRet=factR(x);

   cout<<"factorial of number : "<<iRet<<"\n";
    return 0;
}
