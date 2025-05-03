#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
	ofstream con("config.txt");
	
	if(!con.is_open())
	cout<<"error opening file!\n";
	
	con<<"AAAAABBBBBCCCCC";
	
	con.close();
	
	fstream io("config.txt",ios::in|ios::out);	
	
	io.seekp(5);
	
	io<<"XXXXX";
	
	io.close();
	
	ifstream in("config.txt");
	
	string st;
	
	getline(in,st);
	
	cout<<"string after changing: "<<st;
	
}
