#include<iostream>
using namespace std;

class TeaMug{
	private:
		string brand;
		string color;
		int capacity=10;
		int currentFillLevel=capacity;
		
	public:
		void displayinfo()
		{
			brand="Tapal";
			color="red";
			cout<<"Tea mug brand: "<<brand<<endl;
			cout<<"Tea mug color: "<<color<<endl;
		}
		void sipTea()
		{
			int count;
			cout<<"how many sips did you take: ";cin>>count;
			currentFillLevel-=count;
		}
		
		void refill()
		{
			if(currentFillLevel<10)
			currentFillLevel=capacity;
			else
			cout<<"cant refill. Cup is not empty\n";
		}
		
		void check()
		{
			if(currentFillLevel==0)
			{
				cout<<"the cup is empty. Its time for a fresh cup!"<<endl;
			}
			else
				cout<<"the cup is not empty. Cup's fill level is "<<currentFillLevel<<endl;
		}
};

int main()
{
	TeaMug T;
	int op;
	T.displayinfo();
	
	while(1)
	{
		cout<<"________________________________________\n";
		cout<<"\t\tOptions\n1. sip\n2. check if empty\n3. refill\n4. exit\n";
		cout<<"choose an option: ";
		cin>>op;
	
		switch(op)
		{
			case 1:
				T.sipTea();
				cout<<"fill level decreased!\n";
				break;
			case 2:
				T.check();
				break;
			case 3:
				T.refill();
				cout<<"cup refilled\n";
				break;
			case 4:
				return 0;	
		}	
	}	
	return 0;
}

