/**
 * ��Ŀ�� 
����һ��������������������е�����k�����,
����ĵ�����0�����Ϊ�����βָ�롣

��������ָ��p1,p2
����p1��p2��ָ��head
Ȼ��p2��ǰ��n��������p1��p2֮��ͼ��k���ڵ�
Ȼ��p1��p2ͬ����
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


