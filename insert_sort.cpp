#include <iostream>
#include <vector>
using namespace std;

class InsertSort
{
 public:
   InsertSort(vector<int> _list,int _len);
   void insert_sort();
   void out();
private:
  int len;
  vector<int> list;
};

InsertSort::InsertSort(vector<int> _list,int _len)
{ 
  for( int i = 0; i < _len; i++)
  list.push_back(_list[i]);

  this->len = _len;
}

void InsertSort::insert_sort()
{
  int insertNum;
  for( int i = 1; i < len; i++ )
 {
   insertNum= list[i];
   int j = i;
   while( j > 0 && insertNum < list[j-1])
   {
     list[j] = list[j-1];
      j--;
   }
  list[j] = insertNum;
 }
  
}

void InsertSort::out()
{
  for( int i = 0; i < len; i++ )
 {
    cout<<list[i]<<" ";
    if((i+1)%10 == 0)
    cout<<endl;
 }

}

int main()
{
  vector<int> list1; 
  list1.push_back(-3);
  list1.push_back(-100);
  list1.push_back(99);
  list1.push_back(234);
  list1.push_back(0);
  
 InsertSort  sort(list1,5); 
 sort.insert_sort();
 sort.out();

 return 0;
}

