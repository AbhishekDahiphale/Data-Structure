#include<iostream>
#include<stdio.h>
using namespace std;

int CountCapI(char *str)
{
   int icnt=0;

   while(*str!='\0')
   {
      if(((*str)>='A') && ((*str)<='Z'))
      {
        icnt++;
      }
      str++;
   }
   return icnt;  

}


int CountCapR(char *str)
{
  static int icnt=0;

   if(*str!='\0')
   {
      if(((*str)>='A') && ((*str)<='Z'))
      {
        icnt++;
      }
      str++;
      CountCapR(str);
   }
   return icnt;  

}


int main()
{
    char Arr[20];
    int iRet=0;

    cout<<"Eneter the string";
    scanf("%[^\n]s",Arr);
   
   iRet=CountCapR(Arr);
   cout<<"Capital letters are : "<<iRet<<"\n";
 
    return 0;
}
