#include<iostream>
#include<string>
using namespace std;

class Patient{
	public:
	int *id;
	string name;
	int *testresults;
	int countresults;
	
	Patient(int id,string name,int countresults,int tests[])
	{
		this->id=new int(id);
		this->name=name;
		this->countresults=countresults;
		testresults=new int[countresults];
		for(int i=0;i<countresults;i++)
		{
			testresults[i]=tests[i];
		}
	}
	void display()const
	{
		cout<<"Patient details: "<<endl;
		cout<<"ID: "<<*this->id<<endl;
		cout<<"Name: "<<this->name<<endl;
		cout<<"Test Results: "<<endl;
		cout<<"{ ";
		for(int i=0;i<countresults;i++)
		{
			cout<<testresults[i]<<" ";
		}
		cout<<"}"<<endl;
	}
	
	Patient(Patient &obj,int newcount,int newresults[])
	{
		this->id=new int(*obj.id);
		this->name=obj.name;
		this->countresults=newcount;
		this->testresults=new int[countresults];
		for(int i=0;i<newcount;i++)
		{
			testresults[i]=newresults[i];
		}
	}
	
	~Patient()
	{
		delete id;
		delete[] testresults;
	}
};

int main()
{
	int tests[3]={2,6,3};
	Patient p1(1,"ali",3,tests);
	
	p1.display();
	int t2[4]={1,9,4,6};
	Patient p2(p1,4,t2);
	
	p2.display();
	p1.display();
	return 0;
}