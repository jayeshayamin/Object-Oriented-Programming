#include<iostream>
#include<string>
using namespace std;

class Device{
	public:
	int deviceID;
	bool status;

	Device(int id,bool status):deviceID(id),status(status){}
	
	void displaydetails()
	{
		cout<<"Device ID: "<<deviceID<<endl;
		cout<<"Status: "<<(status?"ON":"OFF")<<endl;
	}
};

class SmartPhone:virtual public Device{
	public:
		float screensize;
	
	SmartPhone(int id,bool status,float screensize):Device(id,status),screensize(screensize){}
	void displaydetails()
	{
		Device::displaydetails();
		cout<<"Screen Size: "<<screensize<<endl;
	}
};

class SmartWatch:virtual public Device{
	public:
		bool heartratemonitor;
	
	SmartWatch(int id,bool status,bool heart):Device(id,status),heartratemonitor(heart){
	}
	void displaydetails()
	{
		Device::displaydetails();
		cout<<"Heart Rate Monitor: "<<(heartratemonitor?"ON":"OFF")<<endl;
	}
};

class SmartWearable:public SmartWatch,public SmartPhone{
	public:
		int stepcounter;
	
	SmartWearable(int id,bool status,int steps,float screen,bool heartrate):SmartWatch(id,status,heartrate),SmartPhone(id,status,screen),Device(id,status),stepcounter(steps){}
	void displaydetails()
	{
		Device::displaydetails();
		cout<<"Step Counter: "<<stepcounter<<endl;
	}
};

int main()
{
	SmartWearable sw(101,1,15,25.5,1);
	sw.displaydetails();
	return 0;
}