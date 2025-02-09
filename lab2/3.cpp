#include<iostream>
using namespace std;

struct employee{
	int employeeID;
	string name;
	string department;
	float salary;
};
employee* dynamicallocation(int size)
{
	 employee* employees=new struct employee[size];
	 return employees;
}
employee* input(int size,employee* employee)
{
	for(int i=0;i<size;i++)
	{
		cout<<"Enter employee ID: "<<endl;
		cin>>employee[i].employeeID;
		cout<<"Enter name: "<<endl;
		cin>>employee[i].name;
		cout<<"Enter department name: "<<endl;
		cin>>employee[i].department;
		cout<<"Enter salary: "<<endl;
		cin>>employee[i].salary;
	}
	return employee;
	}
void display(int size,employee* employee)
{
	for(int i=0;i<size;i++)
	{
		cout<<"Employee ID: "<<employee[i].employeeID<<endl;
		cout<<"Name: "<<employee[i].name<<endl;
		cout<<"Department name: "<<employee[i].department<<endl;
		cout<<"Salary: "<<employee[i].salary<<endl;
	}
}
void search(employee* employee,int size)
{
	int id,found=0;
	cout<<"Enter Employee ID to search: "<<endl;
	cin>>id;
	for(int i=0;i<size;i++){
	if(id==employee[i].employeeID)
	{
		cout<<"Employee ID: "<<employee[i].employeeID<<endl;
		cout<<"Name: "<<employee[i].name<<endl;
		cout<<"Department name: "<<employee[i].department<<endl;
		cout<<"Salary: "<<employee[i].salary<<endl;
		found=1;
	}}
	if(!found)
	cout<<"Invalid Employee ID.Not found.";
}
void del(employee* employee)
{
	delete[] employee;
}
int main()
{
	int n;
	cout<<"Enter the number of employees whose data will be added: "<<endl;
	cin>>n;
    employee* employee=dynamicallocation(n);
	input(n,employee);
	display(n,employee);
	search(employee,n);
	del(employee);
	return 0;
}