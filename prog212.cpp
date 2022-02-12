#include<iostream>
#include<stdio.h>
using namespace std;

int strlen(char * str)
{
  int icnt=0;

  while(*str!='\0')
  {
    icnt++;
    str++;
  }
  return icnt;
}

int strlenR(char * str)
{
  static int icnt=0;

  if(*str!='\0')
  {
    icnt++;
    str++;
    strlenR(str);
  }
  return icnt;
}

int main()
{
    char Arr[20];
    int iRet=0;

    cout<<"Eneter the string";
    scanf("%[^\n]s",Arr);
   
   iRet=strlenR(Arr);
   cout<<"length of string is : "<<iRet<<"\n";
 
    return 0;
}
