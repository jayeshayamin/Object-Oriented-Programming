#include<iostream>
using namespace std;

class Laptop{
	private:
	string brand;
	string model;
	string processor;
	float ram;
	int storage;
	bool status;
	
	public:
		Laptop(string b,string m,string p,float r,int s,bool st)
		{
			brand=b;
			model=m;
			processor=p;
			ram=r;
			storage=s;
			status=st;
		}
		
		void turnon()
		{
			if(!status)
			{
			cout<<"Laptop "<<brand<<" "<<model<<" has been turned on."<<endl;
			status=1;
			}
			else
			{
				cout<<"Laptop "<<brand<<" "<<model<<" is already on."<<endl;
			}
		}
		
		void turnoff()
		{
			if(status==1){
			cout<<"Laptop "<<brand<<" "<<model<<" has been turned off."<<endl;
			status=0;}
			else
			{
				cout<<"Laptop "<<brand<<" "<<model<<" is already off."<<endl;
			}
		}
		
		void runprogram()
		{
			if(status)
			cout<<"Running program on Laptop "<<brand<<" "<<model<<endl;
			else
			{
				cout<<"PRogram cannot be run as Laptop "<<brand<<" "<<model<<" is off."<<endl;
			}
		}
		
		void checkspecifications()
		{
        cout<<"\nLaptop Specifications:\n";
        cout<<"Brand: "<<brand<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Processor: "<<processor<<endl;
        cout<<"RAM: " <<ram<<"GB\n";
        cout<<"Storage: "<<storage<<"GB\n";
        cout<<"Status: "<<(status?"ON":"OFF")<<endl;
        cout<<"---------------------------------\n";
    }
    
    static void compare(Laptop laptop1,Laptop laptop2)
    {
    	cout<<"\n***************************************"<<endl;
    	cout<<"Comparing Laptop "<<laptop1.brand<<" "<<laptop1.model<<" with"<<"Laptop "<<laptop2.brand<<" "<<laptop2.model<<endl;
    	if(laptop1.ram>laptop2.ram)
    	{
    		cout<<"Laptop "<<laptop1.brand<<" "<<laptop1.model<<"has grater RAM."<<endl;
		}
		else
		{
			cout<<"Laptop "<<laptop2.brand<<" "<<laptop2.model<<"has grater RAM."<<endl;
		}
		
		if(laptop1.storage>laptop2.storage)
    	{
    		cout<<"Laptop "<<laptop1.brand<<" "<<laptop1.model<<"has grater storage."<<endl;
		}
		else
		{
			cout<<"Laptop "<<laptop2.brand<<" "<<laptop2.model<<"has grater storage."<<endl;
		}
	}
};
int main(){
	
    Laptop bilallaptop("Dell","XPS 15","Intel Core i7",16,512,false);
    Laptop ayeshalaptop("Apple","MacBook Air","M1",8,256,1);

    bilallaptop.checkspecifications();
    ayeshalaptop.checkspecifications();

    bilallaptop.turnon();
    ayeshalaptop.turnon();

	Laptop::compare(bilallaptop,ayeshalaptop);
	
    bilallaptop.runprogram();
    ayeshalaptop.runprogram();

    ayeshalaptop.turnoff();

    ayeshalaptop.runprogram();

    return 0;
}