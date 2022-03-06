//#include "mainwindow.h"
#include<iostream>
#include<stack>

using namespace std;
struct Queue
{
    stack<int> st1,st2;

    void displayQ()
    {
        while(!st1.empty())
        {
            cout<<st1.top()<<'\t';
            st1.pop();
        }
        cout<<endl;
    }
    void enQueue(int data)
    {
               while (!st1.empty())
               {
                   st2.push(st1.top());
                   st1.pop();
               }
               st1.push(data);
               while (!st2.empty())
               {
                   st1.push(st2.top());
                   st2.pop();
               }
    }
    void deQueue()
    {
               if (st1.empty())
               {
                   cout << "Queue is Empty";
                   return;
               }
               else
               st1.pop();
    }

};
int main(int argc, char *argv[])
{
    Queue q;
    int i;
    for(i=1;i<10;i++)
        q.enQueue(i*10);  //enque into the queue

        q.deQueue();  //dequeue from the queue
        q.deQueue();  //dequeue from thr queue

        q.displayQ(); //display final queue after enque and deque operation
    return 0;
}
