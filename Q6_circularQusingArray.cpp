//#include "mainwindow.h"
#include<iostream>

using namespace std;
int front=0,rear=0;
void insertinQ(int* a,int data,int size)
{
  if(rear < size)
  {
      if(a[rear]==-1)
      {
      a[rear]=data;
      rear++;
      return;
      }
  }
  if(rear==size && front==0)
      cout<<"Queue is full"<<endl;
  else
      if(rear==size && front !=0)
      {
          rear=rear%size;
          if(a[rear]==-1)
          {
          a[rear]=data;
          rear++;
          }
      }
}
void deleteinQ(int* a,int size)
{
  if(front<size)
  {
    if(a[front]!=-1)
    {
    a[front]=-1;
    front++;
    }
  }
  if(front==size)
  {
      front=front%size;
      if(a[front]!=-1)
      {
      a[front]=-1;
      //front++;
      }
  }
  if(front==rear)
  {
      cout<<"Queue is empty"<<endl;
      return;
  }
}
void display(int* a,int size)
{
  for(int i=0;i<size;i++)
  {
      cout<<a[i]<<'\t';
  }
  cout<<endl;
}
int main(int argc, char *argv[])
{
    int arr[]={-1,-1,-1,-1,-1,-1,-1}; //arr[i]=-1 indicates i th location are empty.
   int size = sizeof(arr)/sizeof(arr[0]);
    insertinQ(arr,100,size);
    insertinQ(arr,200,size);
    deleteinQ(arr,size);

    //deleteinQ(arr,size);
    insertinQ(arr,40,size);
    insertinQ(arr,70,size);
    deleteinQ(arr,size);
        insertinQ(arr,80,size);
    cout<<"Front is "<<front<<"  "<<"Rear is "<<rear<<endl;
    display(arr,size);

    return 0;
}
