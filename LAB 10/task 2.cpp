#include<iostream>
#include<fstream>
#include<sstream>
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
	
	cout<<"Type: "<<type<<endl<<"ID: "<<id<<endl<<"Name: "<<name<<endl<<"Year: "<<year<<endl<<"Extra Data: "<<extraData<<endl<<"Certification Information: "<<certificationInfo<<endl;
	
	vin.close();
}
