#include<iostream>
#include<string>
using namespace std;

class Battery{
	public:
	float capacity;
	
	Battery()
	{
		capacity=0;
	}
	Battery(float n):capacity(n){};
	
	void display() const
	{
		cout<<"Battery Capacity: "<<this->capacity<<" mAh"<<endl;
	}
};

class Smartphone{
	private:
	string brand;
	string model;
	Battery bat;
	public:
	Smartphone()
	{
		brand=" ";
		model=" ";
		bat.capacity=0;
	}
	void addsmartphone(string b,string m,float s)
	{
		this->brand=b;
		this->model=(m);
		bat.capacity=s;
	}
	void display()const{
		cout<<"\n\nSpecifications: "<<endl;
		cout<<"Brand: "<<this->brand<<endl;
		cout<<"Model: "<<this->model<<endl;
		bat.display();
	}
	
	~Smartphone()
	{
	}
};
int main()
{
	Smartphone s1;
	s1.addsmartphone("Samsung","A54",4500);
	s1.display();
	
	Smartphone s2;
	s2.addsmartphone("Pixel","Y22",2900);
	s2.display();
}