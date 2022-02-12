#include<iostream>
using namespace std;

void DisplayI()
{
    int i=1;
    while(i!=5)
    {
        cout<<"Marvellosu Infosystem\n";
        i++;
    }
}

void DisplayR()
{
  static int icnt=1;
  if(icnt!=5)
    {
         cout<<"Marvellosu Infosystem\n";
         icnt++;
         DisplayR();
    }  

}


int main()
{
    DisplayR();
    return 0;
}
