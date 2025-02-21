#include<iostream>
using namespace std;

class Battery{
	public:
		int capacity;
		string type;
		
		Battery(){}
		
		Battery(int c,string t):capacity(c),type(t){}
		
		void dis()
		{
			cout<<"Battery capacity: "<<capacity<<endl<<"Battery type: "<<type<<endl;
		}
};

class Smartphone{
	Battery b;
	string model;
	int storage;
	
	public:
		Smartphone(int c,string t,string m,int s):b(c, t),model(m),storage(s){}
		
		void display(){
			cout<<"model: "<<model<<endl;
			cout<<"storage (GB): "<<storage<<endl;
			b.dis();
		}
};

int main(){
	
	Smartphone S1(5000,"li-ion","A51",64);
	Smartphone S2(6000,"li-ion","A31",128);
	Smartphone S3(3500,"li-po","S20",64);
	
	S1.display();
	cout<<"___________________________\n";
	S2.display();
	cout<<"___________________________\n";
	S3.display();
	
}
