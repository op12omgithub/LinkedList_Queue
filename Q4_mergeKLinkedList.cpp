#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int item;
    struct ListNode* next;
};

struct ListNode* createListNode(int data)
{
    struct ListNode *newnode= (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->item=data;
    newnode->next=NULL;
    return newnode;
}
struct ListNode* createNode(struct ListNode* head, int data)
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
void copyList(struct ListNode** destNode, struct ListNode** sourceNode)
{
    struct ListNode* newNode = *sourceNode;
    if(newNode != NULL);
    *sourceNode = newNode->next;
    newNode->next = *destNode;
    *destNode = newNode;
}

struct ListNode* mergeList(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode tmp,*result;
    result = &tmp;
    tmp.next = NULL;
    while(1)
    {
    if (list1 == NULL)
    {
       result->next = list2;
       break;
    }

    else if(list2 == NULL)
    {
        result->next = list1;
        break;
    }

    else
        //while(list1->next !=NULL && list2->next !=NULL)
        //{
            if(list1->item <= list2->item)
                copyList(&result->next,&list1);
            else
                    copyList(&result->next,&list2);
            result = result->next ;
        }
    return tmp.next;
}

void displayList(struct ListNode* listN)
{
    while (listN != NULL)
    {
        printf("%d\t", listN->item);
        listN = listN->next;
    }
    printf("\n");
}

int main() {
    //we can create k different list like below
    // here 3 lists are created
    struct ListNode* listNode1 = NULL;
    struct ListNode* listNode2 = NULL;
    struct ListNode* listNode3 = NULL;

    struct ListNode* result;
    int i;
    printf("Print First list\n");
    for (i = 1; i < 10; i++)
        listNode1 = createNode(listNode1, i * 10);
    displayList(listNode1);

    printf("Print Second List\n");
    for (i = 1; i < 10; i++)
        listNode2 = createNode(listNode2, i * 5);
    displayList(listNode2);

    printf("Print Third List\n");
    for (i = 1; i < 10; i++)
        listNode3 = createNode(listNode3, i * 4);
    displayList(listNode3);


    result = mergeList(listNode1,listNode2);//merge list1 and list2
    result = mergeList(result,listNode3);//merge list3 into already added list
   //in the similar way many list can be merged in sorted order.
    printf("Print Merged List\n");
    displayList(result);
    return 0;
}
