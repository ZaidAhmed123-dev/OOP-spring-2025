#include<iostream>
using namespace std;

class tourguide{
	public:
	string name;
	int experience;
	string specialization;
	
	tourguide(){}
	
	tourguide(string n,int e,string s):name(n),experience(e),specialization(s){}
	
	void dis()
	{
		cout<<"name: "<<name<<endl<<"years of experience: "<<experience<<endl<<"specialization: "<<specialization<<endl;
	}
};

class travelagency{
	string a_name;
	int count;
	int limit;
	tourguide *tg;
	
	public:
		travelagency(string an,int l):a_name(an),limit(l),count(0)
		{
				tg=new tourguide[limit];			
		}	
	
		~travelagency(){
			delete[] tg;
		}
		
		void addguide(tourguide *t){
			
			if(count<limit)
			{
				tg[count++]=*t;
				
			}
			else{
				cout<<"limit reached!\n";
			}
		}
		
		void display()
		{
			cout<<"agency name: "<<a_name<<endl<<"_____________________\n";
			cout<<"List of tour guides: \n";
			
			for(int i=0;i<count;i++)
			{
				cout<<"\ntour guide "<<i+1<<endl;
				tg[i].dis();
			}
		}
};

int main()
{
	travelagency TA("alfa agency",5);
	
	tourguide t1("Ahmed",5,"historical places");
	tourguide t2("Unas",7,"adventure");
	tourguide t3("Ali",4,"cultural guide");
	
	TA.addguide(&t1);
	TA.addguide(&t2);
	TA.addguide(&t3);
	
	TA.display();
}
