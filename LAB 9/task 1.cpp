#include <iostream>
using namespace std;

class vehicle{
	protected:
		string model;
		double rate;
	
	public:
		vehicle(string m,double r):model(m),rate(r){}
		
		virtual double getDailyRate()=0;
		virtual void displayDetails()=0;
				
};

class Car:public vehicle{
	public:
		Car(string m,double r):vehicle(m,r){
		}
		
		double getDailyRate(){
			return rate;
		}
		
		void displayDetails(){
			cout<<"Car Model: "<<model<<endl;
			cout<<"Car Daily rate:  $";
		}
};

class Bike:public vehicle{
	public:
		Bike(string m,double r):vehicle(m,r){
		}
		
		double getDailyRate(){
			return rate;
		}
		
		void displayDetails(){
			cout<<"Bike Model: "<<model<<endl;
			cout<<"Bike Daily rate:  $";
		}
};

int main()
{
	Car c("Elantra",50);
	Bike b("YBR",25);
	
	vehicle* V[2];
	V[0]=&c;
	V[1]=&b;
	
	for(int i=0;i<2;i++)
	{
		V[i]->displayDetails();
		cout<<V[i]->getDailyRate()<<endl;
	}
}
