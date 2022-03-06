//#include "mainwindow.h"
#include<stack>
#include<iostream>
#include<string.h>

using namespace std;
int parseInput(char in[],int len)
{
  int i;
  stack<string> st;
  st.push("-1");
  int counter=0;
  for(i=0;i<len;i++)
  {
      if(in[i]=='(')
          st.push("(");
      else if(in[i]==')' )
         {
          st.push(")");
          st.pop();
          string tp=st.top();
          if(strcmp(tp.c_str(),"(")==0)
          {
          st.pop();
          counter++;
          }
      }

  }
  return counter*2;
}

int main(int argc, char *argv[])
{
 char input[]="((()()))";
 int length,output;
 length= strlen(input);
 output = parseInput(input,length);
 cout<<"Largest substring parenthesis length is "<<output<<endl;

    return 0;
}
