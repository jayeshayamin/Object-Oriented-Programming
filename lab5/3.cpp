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
		void addprofessor(string n,string d)
		{
			Professor** p=new Professor*[count+1];
			for(int i=0;i<count;i++)
			{
				p[i]=prof[i];
			}
			p[count]=new Professor(n,d);
			delete[] prof;
			prof=new Professor*[count+1];
			for(int i=0;i<=count;i++)
			{
				prof[i]=p[i];
			}
			count++;
		}
		~University()
		{
			for(int i=0;i<count;i++)
			delete prof[i];
			
			delete[] prof;
		}
};
int main() {
    University u1;
    u1.addprofessor("Ali","CS");
    u1.addprofessor("Sara","Mathematics");

    u1.display();

    return 0;
}