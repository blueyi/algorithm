#include <stdio.h>

void QuitSort(int *pArray,int left,int right);
int main()
{
	int SortArray[]={11,0,1111,-333,44,2,45,67,89,23,1,23};
	int n =12;
	int i;
    QuitSort(SortArray,0,n);
	for (i =0;i< n;i++)
	{
		printf("%d ",SortArray[i]);
	}

}

void QuitSort(int *pArray,int left,int right)
{
  int i =left;
  int j = right;
  int prvot = pArray[left];

  while ( i < j)
  {
     while (( i < j) && pArray[j] >= prvot ) j--;
	 if ( i < j)
	 {
		 int temp = pArray[i];
		 pArray[i] = pArray[j];
		 pArray[j] = temp;
	 }
     
	 while (( i < j ) && pArray[i] <= prvot ) i++;
	 if ( i < j)
	 {
		 int temp = pArray[i];
		 pArray[i] = pArray[j];
		 pArray[j] = temp;
	 }
	 if ( i != left) QuitSort(pArray,left,i-1);
	 if ( j != right) QuitSort(pArray,j+1,right);

  }

}