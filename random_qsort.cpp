#include <iostream>

using namespace std;

void swap(int &a,int &b)
{
	int temp = a;
	a =b;
	b = temp;

}
int rand(int low,int hight)
{

	int size = hight -low +1;
	return low +rand()%size;
}
int partition(int data[],int low,int hight)
{
   swap(data[rand(low,hight)],data[low]);
   int key = data[low];
   int i = low -1;
   for ( int j = low; j < hight; j++)
   {
	   if ( data[j] <= key)
	   {
		   i++;
		   swap(data[i],data[j]);
	   }
   }

   swap(data[i+1],data[hight]);
   return i+1;

}

void quitsort(int data[],int low,int hight)
{

	if ( low <hight)
	{
        int k = partition(data,low,hight);
		quitsort(data,low,k-1);
		quitsort(data,k+1,hight);
	}
}


int main()
{
	 int a[4] ={5,3,2,1};
	 quitsort(a,0,4);
     for (int i = 0; i < 4; i++)
     {
		 cout<<a[i]<<endl;
     }
	 return 0;
}
