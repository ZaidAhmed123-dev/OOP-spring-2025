#include<iostream>
using namespace std;

class patient{
	int ID;
	string name;
	char *arr=new char[3];
	
	public:
		patient(int i,string o)
		{
			ID=i;
			name=o;
		}
		
		void addTests(){
			for(int i=0;i<3;i++)
			{
				cout<<"enter test result (p or n)";
				cin>>arr[i];
			}
		}
		
		patient(patient &obj){
			ID=obj.ID;
			name=obj.name;
			arr=new char[3];
			for(int i=0;i<3;i++)
			{
				arr[i]=obj.arr[i];
			}
			
		}
		
		void display(){
			cout<<"ID: "<<ID<<endl;
			cout<<"name: "<<name<<endl;
			for(int i=0;i<3;i++)
			{
				cout<<"result "<<i+1<<": "<<arr[i]<<endl;
			}
		}
};

int main()
{
	patient p1(500,"zaid");
	p1.addTests();
	p1.display();
	patient p2(p1);
	cout<<"\nupdated reports..\n";
	p2.addTests();
	p2.display();
}
