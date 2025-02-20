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
	Battery** bat;
	int count;
	public:
	Smartphone()
	{
		count=0;
		bat=nullptr;
	}
	void addsmartphone(string b,string m,float s)
	{
		this->brand=b;
		this->model=(m);
		Battery** n=new Battery*[count+1];
		for(int i=0;i<count;i++)
		{
			n[i]=bat[i];
		}
		n[count]=new Battery(s);
		delete[] bat;
		bat=new Battery*[count+1];
		bat=n;
		count++;
		for(int i=0;i<count;i++)
		{
			bat[i]=n[i];
		}
	}
	void display()const{
		cout<<"\n\nSpecifications: "<<endl;
		cout<<"Brand: "<<this->brand<<endl;
		cout<<"Model: "<<this->model<<endl;
		for(int i=0;i<count;i++)
		{
			bat[i]->display();
		}
	}
	
	~Smartphone()
	{
		for(int i=0;i<count;i++)
		{
			delete bat[i];
		}
		delete[] bat;
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