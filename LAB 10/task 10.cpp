#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
	ofstream out("data_records.txt");
	if(!out)
	cout<<"error opening file!\n";
	
	out<<"Record 1\n";
	out<<"Record 2\n";
	out<<"Record 3\n";
	out<<"Record 4\n";
	
	out.close();
	
	ifstream in("data_records.txt");
	
	if(!in)
	cout<<"cant open file!\n";
	
	in.seekg(20,ios::beg);
	
	string st;
	getline(in, st);

	cout<<st;
	
	in.close();
}
