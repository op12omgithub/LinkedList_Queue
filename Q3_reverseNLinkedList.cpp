//#include "mainwindow.h"
#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int item;
    ListNode *next;
};

struct ListNode* createListNode(int data)
{
    struct ListNode *newnode= (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->item=data;
    newnode->next=NULL;
    return newnode;
}
struct ListNode*  createList(struct ListNode* head,int data)
{
    struct ListNode *tmp,*tmp1;
    if(head == NULL)
    {
        tmp = createListNode(data);
        head = tmp;
    }
    else
    { tmp = head;
        while(tmp->next !=NULL)
            tmp = tmp->next;
        tmp1 = createListNode(data);
        tmp->next = tmp1;
    }

    return head;
}

void reverseNList(struct ListNode* head,int n)
{
    int count=0,arr[n];
    struct ListNode* original=NULL;
    while(count!=n)
    {
        if(head!=NULL)
        {
        arr[count]=head->item;
        count++;
        head=head->next;
        }
        else
        {
            printf("Value of N is more than the size of Linked list\n");
           return;
        }
    }
    for(int i=count-1;i>=0;i--)
    {
        original = createList(original,arr[i]);
    }
    while(original!=NULL)
    {
        printf("%d\t",original->item);
        original= original->next;

    }
    while(head!=NULL)
    {
        original=head;
        printf("%d\t",original->item);
        head=head->next;
    }
    printf("\n");
}

void printList(struct ListNode* head)
{
    while(head !=NULL)
    {
        printf("%d\t",head->item);
        head=head->next;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int k;
    struct ListNode* head=NULL;
    for(k=1;k<10;k++)
        head=createList(head,k*10);  //LinkedList is created upto length k;
    printf("Input Linked List\n");
    printList(head);
    printf("Print Output list\n");
    reverseNList(head,5); //Enter input for reverse the list upto n, here n=5;

    return 0;
}
