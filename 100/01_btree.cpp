/**
题目：
输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。
要求不能创建任何新的结点，只调整指针的指向。
***/

#include <iostream>

using namespace std;

struct BSTreeNode
{
	int         m_nvalue;
	BSTreeNode *m_pLeft;    //左结点
	BSTreeNode *m_pRight;   //右结点

};

typedef BSTreeNode DoubleList;  //双向链表
DoubleList  *pHead;             //头结点
DoubleList  *pListIndex;       

//转换函数
void convertToDoubleList(BSTreeNode *pCurrent);

//创建二叉查找树
void addBSTreeNode(BSTreeNode* &pCurrent,int value)
{
	//新建结点
   if ( pCurrent == NULL)
   {
	   BSTreeNode *pBStree = new BSTreeNode();
	   pBStree->m_pLeft = NULL;
	   pBStree->m_pRight = NULL;
	   pBStree->m_nvalue = value;
	   pCurrent = pBStree;
   } 
   //左右结点
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
		   cout<<"重复加入节点"<<endl;
		   exit(0);
	   }

   }

}

//遍历二叉查找树 中序
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
