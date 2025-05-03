#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
	ofstream fileout("sensor_log.txt");
	
	string s1 = "Sensor 1 : 25.5 C\n";
	string s2 = "Sensor 2 : 98.1 %RH\n";
	fileout<<s1;
	
	cout<<"position is: "<< fileout.tellp()<<endl;

	fileout<<s2;
	
	cout<<"position is: "<< fileout.tellp()<<endl;
	
	fileout.close();
}
