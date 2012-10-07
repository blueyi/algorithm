/**
 * 题目： 
输入一个单向链表，输出该链表中倒数第k个结点,
链表的倒数第0个结点为链表的尾指针。

设置两个指针p1,p2
首先p1和p2都指向head
然后p2向前走n步，这样p1和p2之间就间隔k个节点
然后p1和p2同……
**/

#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    char data;
    ListNode* next;
};
ListNode* head,*p,*q;
ListNode *pone,*ptwo;

ListNode* fun(ListNode *head,int k)
{
    pone = ptwo = head;
    for(int i=0;i<=k-1;i++)
        ptwo=ptwo->next;
    while(ptwo!=NULL)
    {
        pone=pone->next;
        ptwo=ptwo->next;
    }
    return pone;
}

int main()
{
    char c;
    head = (ListNode*)malloc(sizeof(ListNode));
    head->next = NULL;
    p = head;
    while(c !='0')
    {
        q = (ListNode*)malloc(sizeof(ListNode));
        q->data = c;
        q->next = NULL;
        p->next = q;
        p = p->next;
        c = getchar();
    }
    cout<<"---------------"<<endl;
    cout<<fun(head,2)->data<<endl;

    return 0;
}


