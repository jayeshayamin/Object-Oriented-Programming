#include<iostream>
using namespace std;

class MarkerPen{
	private:
	string brand;
	string color;
	int inklevel;
	bool refillability;
	
	public:
		MarkerPen(string b,string c,int i,bool r)
		{
			brand=b;
			color=c;
			inklevel=i;
			refillability=r;
		}
		void write()
		{
			cout<<"Writing: "<<endl;
			if(inklevel<=0)
			{
				cout<<"Marker is out of ink."<<endl;
			}
			else if(inklevel>0 && inklevel<=100)
			{
				inklevel-=10;
				cout<<"Current marker inklevel status: "<<inklevel<<endl;
			}
		}
		void refill()
		{
			cout<<"Refilling: "<<endl;
			if(inklevel<=100)
			{
				inklevel=100;
				cout<<"Marker has been refilled."<<endl;
				refillability=1;
			}
			else if(inklevel==100)
			{
				cout<<"Marker is filled."<<endl;
			}
		}
		
		void checkstatus()
		{
			cout<<"Brand: "<<brand<<endl;
			cout<<"Color: "<<color<<endl;
			cout<<"Inklevel: "<<inklevel<<endl;
			cout<<"Refillability: "<<refillability<<endl;
			cout<<"****************"<<endl;
		}
};
int main()
{
	MarkerPen marker1("ABC","Black",100,true);
	MarkerPen marker2("123","Red",70,false);
	
	marker1.checkstatus();
	marker2.checkstatus();
	
	marker1.write();
	marker2.write();
	
	
	marker1.checkstatus();
	marker2.checkstatus();
	
	marker1.refill();
	marker2.refill();
}