#include<iostream>
#include<string>
using namespace std;

class Vehicle{
	protected:
	string name;
	int speed;
	
	public:
		Vehicle(string name,int speed):name(name),speed(speed){}
		
		void displaydetails()
		{
			cout<<"Name: "<<name<<endl;
			cout<<"Speed: "<<speed<<endl;
		}
};

class Car:public Vehicle{
	public:
		int seats;
		
	Car(string name,int speed,int seats):Vehicle(name,speed),seats(seats){
	}
	
	void displaydetails()
	{
		Vehicle::displaydetails();
		cout<<"Seats: "<<seats<<endl;
	}
};

class ElectricCar:public Car{
	public:
		int batterylife;
		
	ElectricCar(string name,int speed,int seats,int batterylife):Car(name,speed,seats),batterylife(batterylife){
	}
	
	void displaydetails()
	{
		Car::displaydetails();
		cout<<"batterylife: "<<batterylife<<endl;
	}
};
int main()
{
	ElectricCar m1("mhr342",234,2,23);
	m1.displaydetails();
	return 0;
}