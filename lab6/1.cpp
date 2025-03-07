#include<iostream>
#include<string>
using namespace std;

class Employee{
	protected:
	string name;
	float salary;
	
	public:
		Employee(string name,float salary):name(name),salary(salary){}
		
		void displaydetails()
		{
			cout<<"Name: "<<name<<endl;
			cout<<"Salary: "<<salary<<endl;
		}
};

class Manager:public Employee{
	public:
		float bonus;
		
	Manager(string name,float salary,float bonus):Employee(name,salary),bonus(bonus){
	}
	
	void displaydetails()
	{
		Employee::displaydetails();
		cout<<"Bonus: "<<bonus<<endl;
	}
};
int main()
{
	Manager m1("Ali",234,244);
	m1.displaydetails();
	return 0;
}