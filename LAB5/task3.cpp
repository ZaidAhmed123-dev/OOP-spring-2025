#include<iostream>
using namespace std;

class Professor{
	public:
		string name;
		string department;
		
		Professor(){}
		
		Professor(string n,string dep): name(n),department(dep) {}
};

class University{
	Professor *pr;
	string uni_name;
	int campuses;
	int profcount=0;
	
	public:
		University(string un,int c):uni_name(un),campuses(c){
		pr=new Professor[10];
		}
		
		void addprof(Professor *p)
		{
			pr[profcount++]=*p;
		}
		
		void display()
		{
			cout<<"University name: "<<uni_name<<endl;
			cout<<"number of campuses: "<<campuses<<endl;
			cout<<"list of professors: \n";
			for(int i=0;i<profcount;i++)
			{
				cout<<"name: "<<pr[i].name<<", ";
				cout<<"department: "<<pr[i].department<<endl;
			}
			
		}
		
		~University() { 
        delete[] pr;
    }
};


int main(){
	
	Professor p1("shahid","computerscience"),p2("ahmed","PHYSICS"),p3("rahim","EE");
	
	University uni("FAST",5);
	
	uni.addprof(&p1);
	uni.addprof(&p2);
	uni.addprof(&p3);
	
	uni.display();
}
