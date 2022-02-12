
#include<iostream>
using namespace std;

void Swap(float *iNo1,float *iNo2)
{
    float temp=(*iNo1); 
    (*iNo1)=(*iNo2);
    (*iNo2)=temp;

}

int main()
{
     float x=0,y=0;

     cout<<"enter the first number\n";
     cin>>x;

     cout<<"enter the second number\n";
     cin>>y;

     cout<<"---------Before the swapping---------\n";
     cout<<"First number : "<<x<<"\n";
     cout<<"Second number : "<<y<<"\n";

     Swap(&x,&y);

     cout<<"---------After the swapping---------\n";
     cout<<"First number : "<<x<<"\n";
     cout<<"Second number : "<<y<<"\n";
  
  return 0;
}
