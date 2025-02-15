#include<iostream>
using namespace std;

void input(int aqi[4][28])
{
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
}
void average(int aqi[4][28],float avg[4])
{
	int sum[4];
	for(int r=0;r<4;r++)
	{
		sum[r]=0;
		for(int c=0;c<28;c++)
		{
			sum[r]+=aqi[r][c];
		}
	}
	for(int i=0;i<4;i++)
	{
		avg[i]=(float)sum[i]/28;
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
    for(int r=0;r<4;r++){
        cout<<"City "<<r+1<<": "<<avg[r]<<endl;
    }
	for(int i=0;i<4;i++)
	{
		if(max==avg[i])
		{
			cout<<"The city with the worst air quality is: CITY "<<i+1<<endl;
		}
	}
}
void improved(int aqi[4][28],float wk1[4],float wk2[4],float wk3[4],float wkl[4])
{
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
	int max=0;
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
}
void cpd(int aqi[4][28])
{
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
}
void barchart(float avg[4])
{
		for(int i=0;i<4;i++)
	{
		int ast=(int)avg[i]/50;
		cout<<"\nCITY "<<i+1<<"|";
		for(int j=0;j<=ast;j++)
		{
			cout<<"*";
		}
	}
}
void report(int aqi[4][28],float wk1[4],float wk2[4],float wk3[4],float wkl[4])
{
	for(int i=0;i<4;i++)
	{
		cout<<"CITY "<<i+1<<endl;
		cout<<"Week 1 Average:"<<wk1[i]<<endl;
		cout<<"Week 2 Average:"<<wk2[i]<<endl;
		cout<<"Week 3 Average:"<<wk3[i]<<endl;
		cout<<"Week 4 Average:"<<wkl[i]<<endl;
	}
	cout<<"\n";
	cpd(aqi);
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
}
int main()
{
	int aqi[4][28];
	float avg[4];
	float wk1[4],wk2[4],wk3[4],wkl[4];
	input(aqi);
	average(aqi,avg);
	improved(aqi,wk1,wk2,wk3,wkl);
	cout<<"\nREPORT: \n"<<endl;
	report(aqi,wk1,wk2,wk3,wkl);
	barchart(avg);
	return 0;
}
