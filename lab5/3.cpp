#include<iostream>
#include<string>
using namespace std;

class Professor{
	public:
	string name;
	string department;

	Professor(string n,string d):name(n),department(d){};
	
	void display()
	{
		cout<<"Name: "<<name<<endl;
		cout<<"Department: "<<department<<endl;
	}
};

class University{
	private:
	Professor** prof;
	int count;
	public:
		University()
		{
			count=0;
			prof=nullptr;
		}
		void display()const
		{
			cout<<"University: FAST NUCES"<<endl;
			for(int i=0;i<count;i++)
			{
				prof[i]->display();
				cout<<"\n";
			}
		}
		void addprofessor(Professor* o)
		{
			Professor** p=new Professor*[count+1];
			for(int i=0;i<count;i++)
			{
				p[i]=prof[i];
			}
			p[count]=o;
			delete[] prof;
			prof=p;
			count++;
		}
		~University()
		{
			delete[] prof;
		}
};
int main() {
   Professor* p1=new Professor("Ali","Computer Science");
    Professor* p2=new Professor("Sara","AI");
    Professor* p3=new Professor("Zain","Software Engineering");
    University u;
    u.addprofessor(p1);
    u.addprofessor(p2);
    u.addprofessor(p3);

    u.display();
    delete p1;
    delete p2;
    delete p3;
}