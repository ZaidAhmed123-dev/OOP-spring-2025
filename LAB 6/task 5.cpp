#include<iostream>
using namespace std;

class Device{
	protected:
		int DeviceID;
		bool status;
		
	public:
		Device(){}
		
		Device(int id,bool s):DeviceID(id),status(s){}
		
		void displayDetails()
		{
			cout<<"Device ID: "<<DeviceID<<endl;
			if(status)
			cout<<"Status: ON\n";
			else
			cout<<"Status: Off\n";
		}
};

class SmartPhone:virtual public Device
{
	protected:
		float screenSize;
	
	public: 
		SmartPhone(int id,bool s,float ss):Device(id,s),screenSize(ss){}
		
		void displayDetails()
		{
			cout<<"Screen Size: "<<screenSize<<endl;
		}
};

class SmartWatch:virtual public Device{
	protected:
		bool heartRateMonitor;
		
	public:
		SmartWatch(int id,bool s,bool hrm):Device(id,s),heartRateMonitor(hrm){}
		
		void displayDetails()
		{
			cout<<"Heart Rate Monitor: "<<heartRateMonitor<<endl;
		}
};

class SmartWearable:public SmartPhone,public SmartWatch{
	int stepCounter;
	
	public:
		SmartWearable(int id,bool s,float ss,bool hrm,int sc):SmartPhone(id,s,ss),SmartWatch(id,s,hrm),stepCounter(sc){}
		
		void displayDetails()
		{
			Device::displayDetails();
			SmartPhone::displayDetails();
			SmartWatch::displayDetails(); 
			cout<<"step count: "<<stepCounter<<endl;
		}
};

int main()
{
	SmartWearable sw(123,true,5.5,false,200);
	
	sw.displayDetails();
}
