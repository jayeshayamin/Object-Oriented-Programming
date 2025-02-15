#include <iostream>
#include<string>
using namespace std;

void registration(char event1[5][15],char event2[5][15])
{	
	int row,sum=0;
	cout<<"Event 1 Registration: "<<endl;
	for(row=0;row<5;row++)
	{
		cout<<"Enter name "<<row+1<<":"<<endl;
		cin>>event1[row];
	}
	cout<<"Registration completed.Thankyou!";
	cout<<"\nEvent 2 Registration: "<<endl;
	for(row=0;row<5;row++)
	{
		cout<<"Enter name "<<row+1<<":"<<endl;
			cin>>event2[row];
	}
	cout<<"Registration completed.Thankyou!"<<endl;
}
int donation()
{
	int sum=0;
	for(int i=0;i<2;i++)
	{
		//5 participants in each event
		 sum+=10*5;
	}
	return sum;
}
void finding(char event1[5][15],char event2[5][15])
{
	char find[15];
	cout<<"Enter name to find: "<<endl;
	cin>>find;
	int found=0,row;
	for(row=0;row<5;row++)
	{
		if(strcmp(event1[row],find)==0)
		{
			cout<<"Participant found in event 1 position: "<<row+1<<endl;
			found=1;
		break;}
	}
	for(row=0;row<5;row++)
	{
		if(strcmp(event2[row],find)==0)
		{
			cout<<"Participant found in event 2 position: "<<row+1<<endl;
			found=1;
		break;
		}
	}
	if(!found)
	{
		cout<<"participant not found."<<endl;
	}
	
}
void reverse(char event1[5][15],char event2[5][15])
{
	int row;
	cout<<"Event 1 Participants reversed: "<<endl;
	for(row=4;row>=0;row--)
	{
		cout<<event1[row]<<endl;
	}
	cout<<"Event 2 Participants reversed: "<<endl;
	for(row=4;row>=0;row--)
	{
		cout<<event2[row]<<endl;
	}
}
void barchart()
{
	int row;
	cout<<"\nBar Chart:"<<endl;
	cout<<"Event 1 Participants|";
	for(row=0;row<5;row++)
	{
		cout<<" *";
	}
	cout<<"\nEvent 2 Participants|";
	for(row=0;row<5;row++)
	{
		cout<<" *";
	}
}
int main()
{
	char event1[5][15];
	char event2[5][15];
	registration(event1,event2);
	cout<<"Total Donation collected is: "<<donation()<<endl;
	finding(event1,event2);
	reverse(event1,event2);
	barchart();
    return 0;
}