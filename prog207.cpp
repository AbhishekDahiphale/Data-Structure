#include<iostream>
using namespace std;

void DisplayI(int iNo)
{
    int i=0;
    while(i!=iNo)
    {
        cout<<"Marvellosu Infosystem\n";
        i++;
    }
}



void DisplayR(int iNo)
{
  static int icnt=0;
  if(icnt!=iNo)
    {
         cout<<"Marvellosu Infosystem\n";
         icnt++;
         DisplayR(iNo);
    }  

}


int main()
{
    int ivalue=0;
    cout<<"How many times display";
    cin>>ivalue;
    DisplayR(ivalue);
    return 0;
}
