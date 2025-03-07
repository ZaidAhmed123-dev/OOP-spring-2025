#include<iostream>
using namespace std;

class Person{
	protected:
		string name;
		int age;
		
	public:
		Person(string name,int age):name(name),age(age){}
		
		void displayDetails()
		{
			cout<<"name: "<<name<<endl;
			cout<<"age: "<<age<<endl;
		}
};

class Teacher:public Person{
	protected:
		string subject;
		
	public:
		Teacher(string name,int age,string subject):Person(name,age),subject(subject){}
		
		void displayDetails()
		{
			Person::displayDetails();
			cout<<"subject: "<<subject<<endl;
		}
};

class Researcher:public Person{
	protected:
		string researchArea;
		
	public:
		Researcher(string name,int age,string rA):Person(name ,age),researchArea(rA){}
		
		void displayDetails()
		{
			Person::displayDetails();
			cout<<"Research Area: "<<researchArea<<endl;
		}
};

class Professor:public Person,public Teacher,public Researcher{
	int Publications;
	
	public:
		Professor(string name,int age,string subject,string rA,int pub):Person(name,age),Teacher(name,age,subject),Researcher(name,age,rA),Publications(pub){}
		
		void displayDetails()
		{
			Teacher::displayDetails();
			cout<<"Research Area: "<<researchArea<<endl;
			cout<<"Number of publications: "<<Publications<<endl;
		}
};

int main()
{
	Professor p1("sir Khalid",30,"Calculus","Mathematical Physics",4);
	
	p1.displayDetails();
}
