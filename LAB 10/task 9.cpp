#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
	ifstream log;
	log.open("large_log.txt");
	
	string s1,s2;
	
	getline(log,s1);
	
	cout<<"current position: "<<log.tellg()<<endl;
	
	getline(log,s2);
	
	cout<<"new position: "<<log.tellg()<<endl;
}
