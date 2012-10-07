#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>

using namespace std;

int sort_num=10000000;
int memory_size=250000;

int read_data(FILE *fp,int *space)
{
	int index=0;
	while (index < memory_size && fscanf(fp,"%d",&space[index]) != EOF)
		index++;
	
	return index;
}

void write_data(FILE *fp,int *space,int num)
{
	int index=0;
	while(index < num)
	{
      fprintf(fp,"%d ",space[index]);
	  index++;
	}
}

void check_up(FILE *fp)
{
	if( fp == NULL)
	{
		cout<<"file pointer is invalid"<<endl;
		exit(1);
	}
}

int compare(const void *first_num,const void *second_num)
{
	return *(int*)first_num - *(int*)second_num;
}

string new_file_name(int n)
{
	char file_name[20];
	sprintf(file_name,"data%d.txt",n);
	
	return file_name;
}

int memory_sort()
{
	FILE *fp_in_file=fopen("data.txt","r");
	check_up(fp_in_file);
	int counter=0;
	while(1)
	{
		int *space= new int[memory_size];
		
		int num=read_data(fp_in_file,space);
		if ( num == 0)
			break;

		qsort(space,num,sizeof(int),compare);
		
		string file_name=new_file_name(++counter);
		FILE *fp_aux_file = fopen(file_name.c_str(),"w");
		check_up(fp_aux_file);
        
		write_data(fp_aux_file,space,num);
		
		fclose(fp_aux_file);

		delete[] space;
	}

	fclose(fp_in_file);

	return counter;

}

void merge_sort(int file_num)
{
	if (file_num <= 0)
	  return;
	
	FILE *fp_out_file=fopen("result.txt","w");
	check_up(fp_out_file);

	FILE **fp_array= new FILE* [file_num];
	int i;
	for (i=0; i<file_num; i++)
	{
		string file_name= new_file_name(i+1);
		fp_array[i] =fopen(file_name.c_str(),"r");
		check_up(fp_array[i]);
	}

	int *first_data= new int[file_num];
	bool *finish = new bool[file_num];
	memset(finish,false,sizeof(bool)*file_num);

	for (i=0;i<file_num;i++)
	{
		fscanf(fp_array[i],"%d",&first_data[i]);
	}

	while(1)
	{
		int index=0;
		while(index < file_num && finish[index])
			index++;

		if ( index >= file_num)
			break;
		
		int min_data = first_data[index];
		for(i=index+1; i<file_num;i++)
		{
			if (min_data > first_data[i] && !finish[i])
			{
				min_data=first_data[i];
			}

		}

		fprintf(fp_out_file,"%d",min_data);
		if ( fscanf(fp_array[index],"%d",&first_data[index]) == EOF)
		{
			finish[index] = true;
		}


	}

	fclose(fp_out_file);
	delete[] finish;
	delete[] first_data;
	for (i=0;i<file_num;i++)
	{
		fclose(fp_array[i]);
	}

	delete[] fp_array;
}

int main()
{

	clock_t start_memory_sort=clock();
	int  aux_file_num=memory_sort();
	clock_t end_memory_sort=clock();
	cout<<"the time needs in memory sort:"<<end_memory_sort-start_memory_sort<<endl;

	clock_t start_merge_sort = clock();
	merge_sort(aux_file_num);
	clock_t end_merge_sort=clock();
	cout<<"the time needs in merge sort:"<<end_merge_sort-start_merge_sort<<endl;

	return 0;
}