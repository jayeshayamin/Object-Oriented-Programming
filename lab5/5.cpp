#include<iostream>
#include<string>
using namespace std;

class Tourguide{
	private:
	string name;
	float experience;
	string specialization;
	
	public:
	Tourguide(string n,float e,string s)
	{
		this->name=n;
		this->experience=e;
		this->specialization=s;
	}
	
	void display()const
	{
		cout<<"|Name: "<<this->name;
		cout<<" |Experience: "<<this->experience<<" Years ";
		cout<<"|Specialization: "<<this->specialization<<endl;
	}
};

class Travelagency{
	public:
	Tourguide** guide;
	int count;
	
	Travelagency()
	{
		count=0;
		guide=nullptr;
	}
	void addguide(Tourguide* tourguide)
	{
		Tourguide** store=new Tourguide*[count+1];
		for(int i=0;i<count;i++)
		{
			store[i]=guide[i];
		}
		store[count]=tourguide;
		delete[] guide;
		guide=store;
		count++;
	}
	
	void display()const
	{
		cout<<"Displaying details: "<<endl;
		for(int i=0;i<count;i++)
		{
			guide[i]->display();
		}
	}
	
	~Travelagency()
	{
		delete[] guide;
	}

};

int main()
{
	Tourguide* guide1 = new Tourguide("Ali",5,"Pyramids of Giza");
    Tourguide* guide2 = new Tourguide("Clara",8,"Adventure");
    Tourguide* guide3 = new Tourguide("John",4,"Historicsl Culture");

    Travelagency agency;

    agency.addguide(guide1);
    agency.addguide(guide2);
    agency.addguide(guide3);

    agency.display();

    delete guide1;
    delete guide2;
    delete guide3;

    return 0;
}