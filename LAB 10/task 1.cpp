#include<iostream>
#include<fstream>
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
	
	while(getline(vin,st))
	{
		cout<<st<<endl;
	}
	
	vin.close();
}
