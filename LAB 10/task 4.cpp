#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
		ifstream vin;
	vin.open("Vehicles.txt");
	
	if(!vin.is_open())
	{
		cout<<"error opening the file!\n";
	}
	string st;
	
	getline(vin, st);
	
	istringstream sin(st);
	
	string type,id,name,year,extraData,certificationInfo;
	
	getline(sin,type,',');
	getline(sin,id,',');
	getline(sin,name,',');
	getline(sin,year,',');
	getline(sin,extraData,',');
	getline(sin,certificationInfo,',');
	
	size_t cpos = extraData.find(':');
	
	if(cpos == string::npos)
	{
		cout<<"invalid extradata format\n";
	}
	
	if(type == "AutonomousCar")
	{
		float sv = stof(extraData.substr(cpos + 1));
		cout<<"Vehicle id: "<<id<<"\nSofware version: "<<sv<<endl;
	}
	
	else if(type == "ElectricVehicle")
	{
		int bc = stoi(extraData.substr(cpos + 1));
		cout<<"Vehicle id: "<<id<<"\nBattery Capacity: "<<bc<<endl;
	}
	else{
		cout<<"unknown vehicle\n";
	}
	
	vin.close();	
}
