#include<iostream>
#include<string>
using namespace std;

class GroceryStore{
	
	private:
		string items[100];
		int prices[100]={0};
		int itemcount;
	
	public:
		GroceryStore(){
			itemcount=0;
		}
		
		void addItem()
		{
			if(itemcount<100)
			{
				cout<<"enter item name: ";
				cin>>items[itemcount];
				cout<<"enter item price: ";
				cin>>prices[itemcount];
				
				cout<<"item added successfully!\n";
				itemcount++;
			}
			
			else
			cout<<"inventory full!\n";
		}
		
		void UpdateItem()
		{
			string name;
			cout<<"enter item name to update: ";
			cin>>name;
			
			for(int i=0;i<itemcount;i++)
			{
				if(name==items[i])
				{
					cout<<"enter updated price: ";
					cin>>prices[i];
					break;
				}
			}
			cout<<"price updated successfully!\n";
		}
		
		void viewInventory()
		{
			for(int i=0;i<itemcount;i++)
			{
				cout<<"item "<<i+1<<" name: "<<items[i]<<endl;
				cout<<"item "<<i+1<<" price: "<<prices[i]<<endl;
			}
		}
		
		void generateReciept()
		{
			int total=0;
			int n,index;
			cout<<"enter the number of items: ";
			cin>>n;
			
			string Name[n];
			int q[n];
				
			for(int i=0;i<n;i++)
			{
				cout<<"enter item "<<i+1<<" name: ";
				cin>>Name[i];
				cout<<"enter item "<<i+1<<" quantity: ";
				cin>>q[i];
			}
			
			cout<<"\t\tRECIEPT:\n";
			cout<<"items\t\tQuantity\t\tPrice\n";
			cout<<"______________________________\n";
						
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<itemcount;j++)
				{
					if(Name[i]==items[j])
					{
						total+=(prices[j]*q[i]);
						cout<<items[j]<<"\t\t"<<q[i]<<"\t\t\t"<<prices[j]<<" Rs."<<endl;
						break;
					}
				}
			}
			cout<<"total: "<<total<<" Rs."<<endl;

		}
	
};

int main()
{
	GroceryStore G;
	
	while(1)
	{
		int op;
		cout<<"_____________________________________________________________\n";
		cout<<"\n\t\tGrocery Store\n1. add item\n2. update item\n3. view Inventory\n4. generate reciept\n5. exit\n";
		cout<<"choose an option: ";
		cin>>op;
		cout<<endl;
		
		switch(op)
		{
			case 1:
				G.addItem();
				break;
			case 2:
				G.UpdateItem();
				break;
			case 3:
				G.viewInventory();
				break;
			case 4:
				G.generateReciept();
				break;
			case 5:
				return 0;
			default:
				cout<<"choose from the options above.\n";
		}
	}
	
	return 0;
}
