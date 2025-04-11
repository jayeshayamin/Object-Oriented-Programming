#include<iostream>
#include<string>
using namespace std;

class Currency{
	public:
		float moneyvalue;
		
		Currency(float r):moneyvalue(r){}
		
		float operator-()
		{
			moneyvalue=-moneyvalue;
			return moneyvalue;
		}
		Currency operator+(Currency c1)
		{
			return Currency(moneyvalue+c1.moneyvalue);
		}
		Currency operator-(Currency c1)
		{
			return Currency(moneyvalue-c1.moneyvalue);
		}
		Currency operator+=(Currency c1)
		{
			moneyvalue+=c1.moneyvalue;
			return moneyvalue;
		}
		Currency operator-=(Currency c1)
		{
			moneyvalue-=c1.moneyvalue;
			return moneyvalue;
		}
		friend ostream&  operator<<(ostream& out,Currency c)
		{
			out<<"Currency Money value: "<<c.moneyvalue<<endl;
			return out;
		}
};
int main()
{
	Currency c1(50);
	Currency c2(90);
	cout<<"-c1: "<<-c1<<endl;
	Currency c3=c1+c2;
	cout<<"c1+c2: "<<c3<<endl;
	Currency c4=c1-c2;
	cout<<"c1-c2: "<<c4<<endl;
	Currency c5=c1+=c2;
	cout<<"c1+=c2: "<<c5<<endl;
	Currency c6=c1-=c2;
	cout<<"c1-=c2: "<<c6<<endl;
	return 0;
}