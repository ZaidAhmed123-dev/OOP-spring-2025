#include<iostream>
#include<string>
using namespace std;

class Laptop{
	private:
	string brand,model,processor;
	int RAM;
	int storage;
	int isOn=0;
	
	public:
		Laptop(string b,string m,string p,int r,int s)
		{
			brand=b;
			model=m;
			processor=p;
			RAM=r;
			storage=s;
		}
		
		void turnOn()
		{
			if(isOn)
			cout<<"Laptop is already on.\n";
			else
			{isOn=1;
			cout<<"laptop turned on\n";}
		}
		
		void turnOff()
		{
			if(isOn)
			{
				isOn=0;
				cout<<"laptop turned off\n";
			}
			else
			cout<<"laptop is already turned off\n";
		}
		
		void runprogram()
		{
			if(isOn)
			{
				cout<<"running program on "<<brand<<endl;
			}
			else
			cout<<"turn on the laptop first\n";
		}
		
		void checkSpecifications()
		{
			cout<<"brand: "<<brand<<endl<<"model: "<<model<<endl<<"processor: "<<processor<<endl<<"RAM (GB): "<<RAM<<endl<<"storage (GB): "<<storage<<endl;
		}
		
		void compare(Laptop l1,Laptop l2)
		{
			if(l1.RAM>l2.RAM)
			cout<<"laptop: "<<l1.model<<" has more RAM.\n";
			else if(l1.RAM<l2.RAM)
			cout<<"laptop: "<<l2.model<<" has more RAM.\n";
			else
			cout<<"both have the same RAM.\n";
			
			if(l1.storage>l2.storage)
			cout<<"laptop: "<<l1.model<<" has more storage capacity.\n";
			else if(l1.storage<l2.storage)
			cout<<"laptop: "<<l2.model<<" has more storage capacity.\n";
			else
			cout<<"both have the same storage capacity.\n";			
		}
};

int main()
{
	string b,m,p;
	int r,s;
	
	cout<<"enter specifications for Ayesha's Laptop: \n";
	cout<<"brand: ";
	cin>>b;
	cout<<"model: ";
	cin>>m;
	cout<<"processor: ";
	cin>>p;
	cout<<"RAM (GBs): ";
	cin>>r;
	cout<<"storage (GBs): ";
	cin>>s;
	
	Laptop l1(b,m,p,r,s);
	
	cout<<"enter specifications for Bilal's Laptop: \n";
	cout<<"brand: ";
	cin>>b;
	cout<<"model: ";
	cin>>m;
	cout<<"processor: ";
	cin>>p;
	cout<<"RAM (GBs): ";
	cin>>r;
	cout<<"storage (GBs): ";
	cin>>s;
	
	Laptop l2(b,m,p,r,s);
	
	while(1)
	{
		int op;
		cout<<"\t\t\nLaptop Options\n1. turn on\n2. turn off\n3. run program\n4. check specifications\n5. exit\n";
		cout<<"choose an option: ";
		cin>>op;	
		
		switch(op)
		{
			case 1:
				int ch;
				cout<<"which laptop to turn on? press 1 for ayesha's and 2 for bilal's: ";
				cin>>ch;
				if(ch==1)
				l1.turnOn();
				else if(ch==2)
				l2.turnOn();
				else
				cout<<"press 1 or 2 only.\n";
				break;
			case 2:
				cout<<"which laptop to turn off? press 1 for ayesha's and 2 for bilal's: ";
				cin>>ch;
				if(ch==1)
				l1.turnOff();
				else if(ch==2)
				l2.turnOff();
				else
				cout<<"press 1 or 2 only.\n";
				break;
			case 3:
				cout<<"which laptop to run program on? press 1 for ayesha's and 2 for bilal's: ";
				cin>>ch;
				if(ch==1)
				l1.runprogram();
				else if(ch==2)
				l2.runprogram();
				else
				cout<<"press 1 or 2 only.\n";
				break;
			case 4:
				cout<<"\t Bilal's Laptop specifications\n";
				l2.checkSpecifications();
				cout<<"\t Ayesha's Laptop specifications\n";
				l1.checkSpecifications();
				
				cout<<"\n\t\t SUMMARY\n";
				l1.compare(l1,l2);
				break;
			case 5:
				return 0;
				break;
			default:
				cout<<"wrong option!.\n";
				break;
		}	
	}
	return 0;
}
