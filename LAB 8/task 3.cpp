#include<iostream>
using namespace std;

class Teacher;

class Student{
	string name;
	int grade[3];
	
	public:
		Student(string n,int g[3]):name(n){
			for(int i=0;i<3;i++)
			grade[i]=g[i];
		}
		
		friend class Teacher;
		friend float average(Student s);
};

class Teacher{
	
	public:
		
		void display(Student s)
		{
			cout<<"Student name: "<<s.name<<endl;
			cout<<"Student grades: "<<endl;
			
			for(int i=0;i<3;i++)
			cout<<"Subject "<<i+1<<": "<<s.grade[i]<<endl;
		}
		
		void updateGrade(Student &s)
		{
			int n;
			cout<<"Enter subject number you want to change the grade for?";
			cin>>n;
			
			if(n>3||n<1){
			cout<<"invalid!. Enter again. "<<endl;
			updateGrade(s);
			}
			else{
			cout<<"enter the new grade: ";
			cin>>s.grade[n-1];
			}
		}
};

float average(Student s)
{
	float total=0;
	for(int i=0;i<3;i++){
		total+=s.grade[i];
	}
	
	return total/3;
}

int main(){
	
	int g[3]={82,90,76};
	
	Student s("Ehsan",g);
	
	Teacher T;
	
	T.display(s);
	cout<<endl;
	T.updateGrade(s);
	T.display(s);
	cout<<endl;
	cout<<"The average for this student is: "<<average(s)<<endl;
}
