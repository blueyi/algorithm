#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class Node
{
public:
	Node(int data)
	{
		this->m_nData=data;
	}

	int   m_nData;
	Node *m_pNext;

};

class LinkedList
{
public:
	LinkedList( int array[],int len)
	{
		m_pHead=new Node(array[0]);
		Node *temp = m_pHead;

		for(int i=1; i<len; i++)
		{
			temp->m_pNext= new Node(array[i]);
			temp = temp->m_pNext;
		}

		temp->m_pNext = NULL;
	}


	Node *m_pHead;
};

Node *mergeLinkedList(Node *head1,Node *head2)
{
	Node *temp = NULL;
	if(head1 == NULL && head2 == NULL)
		return temp;
	else if(head1 == NULL)
		return head2;
	else if(head2 == NULL)
		return head1;
	else
	{
		if(head1->m_nData < head2->m_nData)
		{
			temp = head1;
			temp->m_pNext = mergeLinkedList(head1->m_pNext,head2);
		}
		else
		{
			temp = head2;
			temp->m_pNext = mergeLinkedList(head1,head2->m_pNext);
		}

		return temp;
	}

}

void printList(Node *head)
{
	assert(head != NULL);
	Node *temp = head;
	while(temp != NULL)
	{
		cout<<temp->m_nData<<" ";
		temp = temp->m_pNext;
	}

}

int main()
{
	int array1[]={1,3,4,5,6};
	int array2[]={2,3,4,6,8,9};

	LinkedList list1(array1,sizeof(array1)/sizeof(int));
	LinkedList list2(array2,sizeof(array2)/sizeof(int));

	Node *new_head = mergeLinkedList(list1.m_pHead,list2.m_pHead);

	printList(new_head);

	return 0;
}

