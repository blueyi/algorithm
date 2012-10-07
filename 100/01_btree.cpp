/**
��Ŀ��
����һ�ö�Ԫ�����������ö�Ԫ������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ����ָ���ָ��
***/

#include <iostream>

using namespace std;

struct BSTreeNode
{
	int         m_nvalue;
	BSTreeNode *m_pLeft;    //����
	BSTreeNode *m_pRight;   //�ҽ��

};

typedef BSTreeNode DoubleList;  //˫������
DoubleList  *pHead;             //ͷ���
DoubleList  *pListIndex;       

//ת������
void convertToDoubleList(BSTreeNode *pCurrent);

//�������������
void addBSTreeNode(BSTreeNode* &pCurrent,int value)
{
	//�½����
   if ( pCurrent == NULL)
   {
	   BSTreeNode *pBStree = new BSTreeNode();
	   pBStree->m_pLeft = NULL;
	   pBStree->m_pRight = NULL;
	   pBStree->m_nvalue = value;
	   pCurrent = pBStree;
   } 
   //���ҽ��
   else
   {
	   if ( pCurrent->m_nvalue > value)
	   {
		   addBSTreeNode(pCurrent->m_pLeft,value);

	   }
	   else if ( (pCurrent->m_nvalue) <  value)
	   {
		   addBSTreeNode(pCurrent->m_pRight,value);
	   }
	   else
	   {
		   cout<<"�ظ�����ڵ�"<<endl;
		   exit(0);
	   }

   }

}

//������������� ����
void ergodicBSTree(BSTreeNode *pCurrent)
{
 
	 if ( pCurrent == NULL)
	 {  
		 return;
	 }

	 if ( pCurrent->m_pLeft != NULL)
	 {
		 ergodicBSTree(pCurrent->m_pLeft);
	 }

	 convertToDoubleList(pCurrent);

	 if ( pCurrent->m_pRight != NULL)
	 {
		 ergodicBSTree(pCurrent->m_pRight);
	 }
}

void convertToDoubleList(BSTreeNode *pCurrent)
{
	pCurrent->m_pLeft = pListIndex;
	if ( pListIndex != NULL)
	{
		pListIndex->m_pRight = pCurrent;
	}
	else
	{
		pHead = pCurrent;
	}

	pListIndex = pCurrent;

	cout<<pCurrent->m_nvalue<<endl;

}

int main()
{
	BSTreeNode *pRoot = NULL;
	pListIndex = NULL;
	pHead = NULL;
	addBSTreeNode(pRoot,10);
	addBSTreeNode(pRoot,4);
	addBSTreeNode(pRoot,6);
	addBSTreeNode(pRoot,8);
	addBSTreeNode(pRoot,12);
	addBSTreeNode(pRoot,14);
	addBSTreeNode(pRoot,15);
	addBSTreeNode(pRoot,16);
	ergodicBSTree(pRoot);

	return 0;

}
