#include<iostream>
using namespace std;
int main()
{
	int aqi[4][28];
	cout<<"Air Quality Index(AQI): "<<endl;
	int r,c;
	for(r=0;r<4;r++)
	{
		cout<<"City "<<r+1<<endl;
		for(c=0;c<28;c++)
		{
			cout<<"Day "<<c+1<<": ";
			cin>>aqi[r][c];
		}
	}
	//total avg
	int sum[4];
	for(r=0;r<4;r++)
	{
		sum[r]=0;
		for(c=0;c<28;c++)
		{
			sum[r]+=aqi[r][c];
		}
	}
	float avg[4];
	for(int i=0;i<4;i++)
	{
		avg[i]=sum[i]/28;
	}
	float max=0;
	for(int i=0;i<4;i++)
	{
		if(avg[i]>max)
		{
			max=avg[i];
		}
	}
	cout<<"\nMonthly Average AQI for each city:"<<endl;
    for(r=0;r<4;r++){
        cout<<"City "<<r+1<<": "<<avg[r]<<endl;
    }
	for(int i=0;i<4;i++)
	{
		if(max==avg[i])
		{
			cout<<"The city with the worst air quality is: CITY "<<i+1<<endl;
		}
	}
	//week1 and last week avg
	float wk1[4],wk2[4],wk3[4],wkl[4];
	for(int i=0;i<4;i++)
	{	int sum1=0,sum2=0,sum3=0,suml=0;
		for(int j=0;j<7;j++)
		{
			sum1+=aqi[i][j];
		}
		wk1[i]=sum1/7;
		
		for(int j=7;j<14;j++)
		{
			sum2+=aqi[i][j];
		}
		wk2[i]=sum2/7;
		
		for(int j=14;j<21;j++)
		{
			sum3+=aqi[i][j];
		}
		wk3[i]=sum3/7;
		
		for(int j=21;j<28;j++)
		{
			suml+=aqi[i][j];
		}
		wkl[i]=suml/7;
	}
	float compare[4]={0};
	for(int i=0;i<4;i++)
	{
		compare[i]=wkl[i]-wk1[i];
	}
	max=0;
	for(int i=0;i<4;i++)
	{
		if(compare[i]>max)
		{
			max=compare[i];
		}
	}
	for(int i=0;i<4;i++)
	{
		if(max==compare[i])
		{
			cout<<"The city with the most improved air quality is: CITY"<<i+1<<endl;
		}
	}
		//TASK #3
	for(int i=0;i<4;i++)
	{
		int ast=avg[i]/50;
		cout<<"\nCITY "<<i+1<<"|";
		for(int j=0;j<=ast;j++)
		{
			cout<<"*";
		}
	}
	cout<<"\nREPORT: \n"<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<"CITY "<<i+1<<endl;
		cout<<"Week 1 Average:"<<wk1[i]<<endl;
		cout<<"Week 2 Average:"<<wk2[i]<<endl;
		cout<<"Week 3 Average:"<<wk3[i]<<endl;
		cout<<"Week 4 Average:"<<wkl[i]<<endl;
	}
	cout<<"\n";
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<28;j++)
		{
			if(aqi[i][j]>150)
			{
				cout<<"Critical Pollution Day: CITY "<<i+1<<" DAY "<<j+1<<endl;
			}
		}
	}
	int min[4]={100000},maxaq[4]={0};
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<28;j++)
		{
			if(aqi[i][j]>maxaq[i])
			{
				maxaq[i]=aqi[i][j];
			}
			if(aqi[i][j]<min[i])
			{
				min[i]=aqi[i][j];
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		cout<<"The max AQI in city"<<i+1<<": "<<maxaq[i]<<endl;
		cout<<"The min AQI in city"<<i+1<<": "<<min[i]<<endl;
	}
	return 0;
}
