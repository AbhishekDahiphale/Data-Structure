

#include<iostream>
using namespace std;

//specific function
void Swap(char *cNo1,char *cNo2)
{
    char temp=(*cNo1); 
    (*cNo1)=(*cNo2);
    (*cNo2)=temp;

}

//Generic function
template <class T>
void SwapX(T *No1,T *No2)
{
    T temp=(*No1); 
    (*No1)=(*No2);
    (*No2)=temp;
}


int main()
{
    {
         char x='\0',y='\0';

         cout<<"enter the first character\n";
         cin>>x;

         cout<<"enter the second  character\n";
         cin>>y;

         cout<<"---------Before the swapping---------\n";
         cout<<"First number : "<<x<<"\n";
         cout<<"Second number : "<<y<<"\n";

         SwapX(&x,&y);

         cout<<"---------After the swapping---------\n";
         cout<<"First number : "<<x<<"\n";
         cout<<"Second number : "<<y<<"\n";
    } 

     {
         int x=0,y=0;

         cout<<"enter the first Number\n";
         cin>>x;

         cout<<"enter the second  Number\n";
         cin>>y;

         cout<<"---------Before the swapping---------\n";
         cout<<"First number : "<<x<<"\n";
         cout<<"Second number : "<<y<<"\n";

        SwapX(&x,&y);

         cout<<"---------After the swapping---------\n";
         cout<<"First number : "<<x<<"\n";
         cout<<"Second number : "<<y<<"\n";
     }

     {
         float x=0.0,y=0.0;

         cout<<"enter the first float Number\n";
         cin>>x;

         cout<<"enter the second float Number\n";
         cin>>y;

         cout<<"---------Before the swapping---------\n";
         cout<<"First number : "<<x<<"\n";
         cout<<"Second number : "<<y<<"\n";

         SwapX(&x,&y);

         cout<<"---------After the swapping---------\n";
         cout<<"First number : "<<x<<"\n";
         cout<<"Second number : "<<y<<"\n";
     }


  return 0;
}
