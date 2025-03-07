#include<iostream>
#include<string>
using namespace std;

class Person{
	public:
	string name;
	int age;
	
	Person(string name,int age):name(name),age(age){
	}
	void displaydetails()
	{
		cout<<"Name: "<<name<<endl;
		cout<<"Age: "<<age<<endl;
	}
};
class Teacher:virtual public Person{
	public:
	string subject;
	
	Teacher(string name,int age,string subject):Person(name,age),subject(subject){
	}
	void displaydetails()
	{
		Person::displaydetails();
		cout<<"Subject: "<<subject<<endl;
	}
};

class Researcher:virtual public Person
{
	public:
	string researcharea;
	
	Researcher(string name,int age,string researcharea):Person(name,age),researcharea(researcharea){
	}
	void displaydetails()
	{
		Person::displaydetails();
		cout<<"Research Area: "<<researcharea<<endl;
	}	
};
class Professor:public Researcher,public Teacher{
	public:
		int publications;
		
		Professor(string name,int age,string subject,string researcharea,int publications):Person(name,age),Researcher(name,age,researcharea),Teacher(name,age,subject),publications(publications){}
		void displaydetails()
	{
		Person::displaydetails();
		cout<<"Publications: "<<publications<<endl;
		cout<<"Subject: "<<subject<<endl;
		cout<<"Research Area: "<<researcharea<<endl;
	}
};
int main()
{
	Professor p("Ali Ahmed",35,"Maths","ABC",8);
	p.displaydetails();
	return 0;
}