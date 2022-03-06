//#include "mainwindow.h"
#include<iostream>
#include<stack>

using namespace std;
stack<int>deleteButtomElement(stack<int>stck)
{
    int size = stck.size();
    int arr[size],i;
    for(i=0;i<size;i++)
    {
        arr[i]=stck.top();
        stck.pop();
    }
    for(i=size-2;i>=0;i--)
    {
        stck.push(arr[i]);
    }
   return stck;
}


int main(int argc, char *argv[])
{
    stack<int>st,output;
    int i=1;
    for(i=1;i<10;i++)
        st.push(i*10);

    output = deleteButtomElement(st);

    cout<<"Input stack "<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<'\t';
        st.pop();
    }
    cout<<endl;

    cout<<"Output stack"<<endl;
    while(!output.empty())
    {
        cout<<output.top()<<'\t';
        output.pop();
    }
    cout<<endl;

    return 0;
}
