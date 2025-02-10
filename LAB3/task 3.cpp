#include<iostream>
#include<string>
using namespace std;

class Planner{
	string task[12][31];
	
	public:
	void addTask()
	{
		int i,j;
		cout<<"enter the month number to add task to: ";
		cin>>i;
		cout<<"enter date to add task to: ";
		cin>>j;
		
		if(i>12||i<1||j>31)
		{
			cout<<"enter the correct date.\n";
		}
		else if((i==4||i==6||i==9||i==11)&&j>30)
		{
			cout<<"this month has 30 days!\n";
		}
		else if(i==2&&j>29)
		{
			cout<<"this month has 29 days!\n";
		}
		else
		{
			cout<<"enter the task for this day: ";
			cin>>task[i-1][j-1];
			cout<<"task added successfully!\n";
		}
	}
	
	void removeTask()
	{
		int i,j;
		cout<<"enter the month number to remove task from: ";
		cin>>i;
		cout<<"enter date to remove task from: ";
		cin>>j;
		
		if(i>12||i<1||j>31)
		{
			cout<<"enter the correct date.\n";
		}
		else if(task[i-1][j-1].empty())
		{
			cout<<"no task added for this day.\n";
		}
		else
		{
			task[i-1][j-1]="";
			cout<<"task removed successfully!\n";
		}
	}
	
	void display()
	{
		int flag=0;
		for(int i=0;i<12;i++)
		{
			cout<<"\ntask for month "<<i+1<<endl;
			for(int j=0;j<31;j++)
			{
				if(task[i][j].empty())
				{
					flag=1;
					continue;
				}
				else
				{
					cout<<"day "<<j+1<<": "<<task[i][j]<<endl;
					flag=0;
				}
			}
			if(flag)
			cout<<"no tasks!\n";
		}
	}
};

int main()
{
	Planner p;
	
	while(1)
	{
		int op;
		cout<<"___________________________________________________________________\n";
		cout<<"\t\tEvent Planner\n1. add or update task\n2. remove task\n3. display tasks\n4. exit\n";
		cout<<"choose an option: ";
		cin>>op;
		cout<<endl;
		
		switch(op)
		{
			case 1:
				p.addTask();
				break;
			case 2:
				p.removeTask();
				break;
			case 3:
				p.display();
				break;
			case 4:
				return 0;
				break;
			default:
				cout<<"choose from the options above.\n";
		}
	}
return 0;

}
