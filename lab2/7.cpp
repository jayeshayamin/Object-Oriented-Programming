#include<iostream>
using namespace std;
void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void reversal(int* array,int size)
{
	int* start=array;
	int* last=size+array-1;
	while(start<last)
	{
		swap(start,last);
		start++;
		last--;
	}
	cout<<"Reversed Array: "<<endl;
	for(int i=0;i<size;i++)
	{
	cout<<array[i]<<" "<<endl;	
}
}
void freeing(int* array)
{
	delete[] array;
}
int main()
{
	int n,a,b;
	cout<<"Enter size of array: "<<endl;
	cin>>n;
	int* array=new int[n];
	
	for(int i=0;i<n;i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>array[i];
	}
	swap(a,b);
	reversal(array,n);
	freeing(array);
}