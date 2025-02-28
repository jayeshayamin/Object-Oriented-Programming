#include<iostream>
#include<string>
using namespace std;

class Car{
	public:
	int *registrationnumber;
	string model;
	string owner;
	
	Car(int r,string m,string o):registrationnumber(new int(r)),model(m),owner(o){};
	
	void display()const
	{
		cout<<"Car Details: "<<endl;
		cout<<"Registration number: "<<*this->registrationnumber<<endl;
		cout<<"Model: "<<this->model<<endl;
		cout<<"Owner: "<<this->owner<<endl;
		cout<<"\n";
		
	}
	
	Car(Car &obj,string ownernew)
	{
		this->registrationnumber=obj.registrationnumber;
		this->model=obj.model;
		this->owner=ownernew;
		cout<<"Car rented."<<endl;
	}
	
	~Car()
	{
	}
};
int main()
{
	Car c1(1,"X20","Ali");
	c1.display();
	
	Car c2(c1,"taha");
	c2.display();
	return 0;
}