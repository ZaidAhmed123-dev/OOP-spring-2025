#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

class InventoryItem{
	public:
		int ItemID;
		char ItemName[20];
		
		InventoryItem(){
		}
		
		InventoryItem(int id,char name[]):ItemID(id){
			for(int i=0;i<20;i++)
			{
				ItemName[i]=name[i];
			}
		}
};


int main(){
	char name[]={'p','h','o','n','e'};
	
	InventoryItem item(500,name);
	
	ofstream out("inventory.dat",ios::binary);
	
	out.write((char*)&item,sizeof(item));
	
	out.close();
	
	ifstream in("inventory.dat",ios::binary);
	
	InventoryItem item2;
	
	in.read((char*)&item2,sizeof(item2));
	
	cout<<"item 2 id: "<<item2.ItemID<<endl<<"item 2 name: "<<item2.ItemName;
	
	in.close();
}
