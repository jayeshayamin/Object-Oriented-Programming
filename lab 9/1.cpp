#include<iostream>
#include<string>
using namespace std;

class Vehicle{
	public:
		string model;
		double rate;
		
		Vehicle(string m,double r):model(m),rate(r){}
		virtual double getdisplayrate()=0;
		virtual void displaydetails()=0;
};

class Car:public Vehicle{
	public:
		Car(string m,double r):Vehicle(m,r){}
		double getdisplayrate() override
		{
			return rate;
		}
		void displaydetails()override
		{
			cout<<"Car: "<<endl;
			cout<<"Model: "<<model;
			cout<<" Rate: "<<rate<<endl;
		}
};

class Bike:public Vehicle{
	public:
		Bike(string m,double r):Vehicle(m,r){}
		double getdisplayrate()override
		{
			return rate;
		}
		void displaydetails()override
		{
			cout<<"Bike: "<<endl;
			cout<<"Model: "<<model;
			cout<<" Rate: "<<rate<<endl;
		}
};
int main()
{
	Car c("NSI23",249.34);
	Bike b("WR244",345.45);
	c.displaydetails();
	b.displaydetails();
	cout<<"Car daily rate: "<<c.getdisplayrate()<<endl;
	cout<<"Bike daily rate: "<<b.getdisplayrate()<<endl;
	return 0;
}