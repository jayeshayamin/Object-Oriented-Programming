#include<iostream>
using namespace std;

int** memoryallocation(int rows,int cols)
{
	int** array=new int*[rows];
	for(int i=0;i<rows;i++)
	{
		array[i]=new int[cols];
	}
	return array;
}
void input(int** array,int rows,int cols)
{
	for(int i=0;i<rows;i++)
	{
		cout<<"ELements of row "<<i+1<<": "<<endl;
		for(int j=0;j<cols;j++)
		{
			cin>>array[i][j];
		}
	}
}
void transpose(int** array,int rows,int cols)
{
	cout<<"transpose of Matrix: "<<endl;
	for(int i=0;i<cols;i++)
	{
		for(int j=0;j<rows;j++)
		{
			cout<<"|"<<*(*(array+j)+i)<<" ";
		}
		cout<<"|"<<endl;
	}
}
void freeing(int **array,int rows)
{
	for(int i=0;i<rows;i++)
	{
		delete[] array[i];
	}
	delete[] array;
}

int main()
{
	int rows,cols;
	cout<<"Enter rows: ";
	cin>>rows;
	cout<<"Enter columns: ";
	cin>>cols;
	
	int** matrix=memoryallocation(rows,cols);
	input(matrix,rows,cols);
	transpose(matrix,rows,cols);
	freeing(matrix,rows);
}