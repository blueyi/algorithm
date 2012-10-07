/**题目：
   输入： 一个最多有n个不重复的正整数的文件，其中每个数都小于n，且n=10^7
   输出： 得到按小到大升序排列的包含所有输入的整数列表
   要求： 最多有1MB内存空间可用，但磁盘空间足够。要求运行时间10秒为佳。
**/
#include <iostream>
#include <bitset>
#include <assert.h>
#include <time.h>

using namespace std;

const int max_each_scan=5000000;

int main()
{
	clock_t begin=clock();
	bitset<max_each_scan> bit_map;
	bit_map.reset();

	FILE *fp_unsort_file=fopen("data.txt","r");
	assert(fp_unsort_file);

	int num;
	while(fscanf(fp_unsort_file,"%d ",&num) != EOF)
	{
           if(num < max_each_scan)
	   {
	      bit_map.set(num,1);
	   }
	}

	FILE *fp_sort_file = fopen("sort.txt","w");
	assert(fp_sort_file);

	for(int i=0; i<max_each_scan;i++)
	{
		if(bit_map[i] ==1)
		{
			fprintf(fp_sort_file,"%d  ",i);
		}
	}
   
	int result=fseek(fp_unsort_file,0,SEEK_SET);
	if (result)
	{
		cout<<"fseek faild"<<endl;
	}
	else
	{
		bit_map.reset();
		while (fscanf(fp_unsort_file,"%d",&num) != EOF)
		{
			if ( num >= max_each_scan && num < 1000000)
			{
				num -= max_each_scan;
				bit_map.set(num,1);
			}
		}

	}
	for (int i=0;i<max_each_scan;i++)
	{
		if (bit_map[i] == 1)
		{
			fprintf(fp_sort_file,"%d",i+max_each_scan);
		}
	}

	clock_t end=clock();

	cout<<"bitmap time:"<<endl;
	cout<<(end - begin)/CLK_TCK <<"s"<<endl;

	fclose(fp_sort_file);
	fclose(fp_unsort_file);

	return 0;

}