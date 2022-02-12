

#include<iostream>
using namespace std;

void Swap(char *iNo1,char *iNo2)
{
    char temp=(*iNo1); 
    (*iNo1)=(*iNo2);
    (*iNo2)=temp;

}

int main()
{
     char x='\0',y='\0';

     cout<<"enter the first character\n";
     cin>>x;

     cout<<"enter the second character\n";
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
