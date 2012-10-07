#include <iostream>

using namespace std;

int binary_search(int array[],int n,int value);
int main()
{
	int array[9]={1,2,3,4,5,6,7,8,9};
    cout<<binary_search(array,9,9)<<endl;
	return 0;
}

int binary_search(int array[],int n,int value)
{
	int left=0;
	int right = n-1;

    while(left <= right)
	{ 
		int middle = left+((right-left) >> 1);

		if ( array[middle] > value)
		{
			right = middle -1;
		}
		else if(array[middle] < value)
		{
			left = middle + 1;
		}
		else
			return middle;

	}

	return -1;
}
