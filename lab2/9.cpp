#include<iostream>
using namespace std;

struct students{
	string name;
	int rollnumber;
	float subjectmarks;
};
students* dynamicallocation(int size)
{
	students* students1=new students[size];
	return students1;
}
void input(students* students,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<"Enter data for Student "<<i+1<<":"<<endl;
		cout<<"Name: ";
		cin>>students[i].name;
		cout<<"Roll Number: ";
		cin>>students[i].rollnumber;
		cout<<"Marks: ";
		cin>>students[i].subjectmarks;
		}
	}
int highest(students* students,int size)
{
	int max=0;
	for(int i=0;i<size;i++)
	{
		if(students[i].subjectmarks>max)
		{
			max=students[i].subjectmarks;
		}
	}
	return max;
}
void display(int max,int size,students* students)
{
	for(int i=0;i<size;i++)
	{
		if(max==students[i].subjectmarks)
		{
		cout<<"Student with Highest Marks: "<<endl;
		cout<<"Name: "<<students[i].name<<endl;
		cout<<"Roll Number: "<<students[i].rollnumber<<endl;
		cout<<"Marks: "<<students[i].subjectmarks<<endl;
		}
}}
void del(students* students)
{
	delete[] students;
	cout<<"Memory Freed."<<endl;
}
int main()
{
	int n;
	cout<<"Enter the number of students."<<endl;
	cin>>n;
	int max;
	students* student=dynamicallocation(n);
	input(student,n);
	max=highest(student,n);
	display(max,n,student);
	del(student);
	return 0;
}