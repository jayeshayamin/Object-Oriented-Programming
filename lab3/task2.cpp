#include<iostream>
using namespace std;

class TeaMug{
	private:
	string brand;
	string color;
	int capacity;
	int currentfilllevel;
	
	public:
		TeaMug(string b, string c, int c1, int cf){
			brand=b;
			color=c;
			capacity=c1;
			currentfilllevel=cf;
		}
		
		void siptea()
		{
			cout<<"\n";
			if(currentfilllevel<=0)
			{
				cout<<"No tea in the cup."<<endl;
			}
			else
			{
				cout<<"Sipping tea.Tea is delicious."<<endl;
				currentfilllevel-=10;
			}
		}
		
		void refillcup()
		{
			cout<<"\n";
			if(currentfilllevel==capacity)
			{
				cout<<"Cup is full. Cannot add more tea."<<endl;
			}
			else
			{
				cout<<"Refilling..."<<endl;
				cout<<"Cup refilled."<<endl;
				currentfilllevel=capacity;
			}
		}
		
		void check()
		{
			if(currentfilllevel<=0)
			{
				cout<<"Cup is empty.It is time for a fresh cup of tea."<<endl;
			}
			else{
				cout<<"Current fill level: "<<currentfilllevel<<endl;
			}
		}
};

int main()
{
	TeaMug mug1("ABC","Blue",150,150);
	TeaMug mug2("QWE","Red",90,30);
	
	mug1.check();
	mug2.check();
	
	mug1.siptea();
	mug2.siptea();
	
	mug1.check();
	mug2.check();
	
	mug1.refillcup();
	mug2.refillcup();
	
	mug1.check();
	mug2.check();
}