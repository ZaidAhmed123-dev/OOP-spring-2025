#include<iostream>
using namespace std;

class Employee{
	protected:
		string name;
		float salary;
		
	public:
		Employee(string en, float es):name(en),salary(es){}
		
		void displayDetails(){
			cout<<"name: "<<name<<endl;
			cout<<"salary: "<<salary<<endl;
		}
};

class Manager:public Employee{
	private:
		float bonus;
		
	public:
		Manager(string en,float es, float b):Employee(en,es),bonus(b){}
		
		void displayDetails(){
			Employee::displayDetails();
			cout<<"bonus: "<<bonus<<endl;
		}
};

int main()
{
	Manager m1("Ahmed",25000.00,5000.00);
	m1.displayDetails();
}
