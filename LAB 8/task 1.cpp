#include<iostream>
using namespace std;

class Humidity;

class Temperature{
	float temp;
	
	public:
		Temperature(float t):temp(t){
		}
	
	
	friend float calculateHeatIndex(Temperature t,Humidity h);	
};

class Humidity{
	float hum;
	
	public:
		Humidity(float h):hum(h){
		}
		
	friend float calculateHeatIndex(Temperature t,Humidity h);
};

float calculateHeatIndex(Temperature t,Humidity h){
	
    float T = t.temp * 9.0 / 5.0 + 32; 
    float R = h.hum;

    float HI = -42.379 + 2.04901523 * T + 10.14333127 * R - 0.22475541 * T * R - 0.00683783 * T * T - 0.05481717 * R * R + 0.00122874 * T * T * R + 0.00085282 * T * R * R - 0.00000199 * T * T * R * R;

    return (HI - 32) * 5.0 / 9.0; 
}

int main()
{
	Temperature T(32);
	Humidity H(70);
	
	
	
	cout<<"The heat index is: "<<calculateHeatIndex(T, H)<<" degree Celsius. "<<endl;
}
