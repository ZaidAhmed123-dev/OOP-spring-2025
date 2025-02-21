#include<iostream>
using namespace std;

class car{
	int regnum;
	string m_name;
	string o_name;
	
	public:
	car(int r,string mn,string on){
		regnum=r;
		m_name=mn;
		o_name=on;
	}
	
	car(car &obj,string n)
	{
		regnum=obj.regnum;
		m_name=obj.m_name;
		o_name=n;
	}
	
	void display()
	{
		cout<<"registration number: "<<regnum<<endl;
		cout<<"model name: "<<m_name<<endl;
		cout<<"owner name: "<<o_name<<endl;
		cout<<"___________________________\n";
	}
};

int main()
{
	car c1(500,"toyota","zaid");
	car c2(c1,"fzayl");
	
	c1.display();
	c2.display();
}
