#include<iostream>
#include<string>
using namespace std;

class Humidity;
class Temperature{
	private:
	float temperature;//celsius
	
	public:
	Temperature(float t):temperature(t){}
	friend float calculateheatindex(Humidity h,Temperature t);
};
class Humidity{
	private:
	float humidity;//%
	
	public:
		Humidity(float s):humidity(s){}
		
		friend float calculateheatindex(Humidity h,Temperature t);
};
float calculateheatindex(Humidity h,Temperature t)
{
	float T = t.temperature;
    float R = h.humidity;

    float heatindex = -42.379 + 2.04901523*T + 10.14333127*R - 0.22475541*T*R - 0.00683783*T*T - 0.05481717*R*R + 0.00122874*T*T*R + 0.00085282*T*R*R - 0.00000199*T*T*R*R;
    return heatindex;
}
int main()
{
	Temperature t1(85.3);
	Humidity h1(78);
	cout<<"The heat index is: "<<calculateheatindex(h1,t1);
	return 0;
}