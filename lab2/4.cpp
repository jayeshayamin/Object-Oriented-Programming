#include<iostream>
using namespace std;

struct students{
	string name;
	int rollnumber;
	float subjectmarks[5];
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
		for(int j=0;j<5;j++)
		{
			cout<<"Marks for Subject "<<j+1<<":"<<endl;
			cin>>students[i].subjectmarks[j];
		}
	}
}
float* average(students* students,int size)
{
	float* avg=new float[size];
	float sum[size]={0};
	for(int i=0;i<size;i++)
	{
		cout<<"Student "<<i+1<<"Grade: "<<endl;
		for(int j=0;j<5;j++)
		{
			sum[i]+=students[i].subjectmarks[j];
		}
		if(sum[i]>=85)
		{
			cout<<"A+"<<endl;
		}
		else if(sum[i]>=60&&sum[i]<85)
		{
			cout<<"B"<<endl;
		}
		else if(sum[i]>=40&&sum[i]<60)
		{
			cout<<"C"<<endl;
		}
		else
		{
			cout<<"Fail."<<endl;
		}
		avg[i]=sum[i]/5;
	}	
	return avg;
}
void display(float *avg,int size,students* students)
{
	for(int i=0;i<size;i++)
	{
		cout<<"The average of student "<<i+1<<" is: ";
		cout<<avg[i]<<endl;
	}
}
void del(students* students,float* avg)
{
	delete[] avg;
	delete[] students;
	cout<<"Memory Freed."<<endl;
}
int main()
{
	int n;
	cout<<"Enter the number of students."<<endl;
	cin>>n;
	float* avg;
	students* student=dynamicallocation(n);
	input(student,n);
	avg=average(student,n);
	display(avg,n,student);
	del(student,avg);
	return 0;
}