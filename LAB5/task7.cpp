#include<iostream>
using namespace std;

class Product{
	public:
	int id;
	string name;
	float price;
	int a=0;
	
	Product(){}
	
	Product(string n,float p):id(++a),name(n),price(p){}
};

class Store{
	Product pr[50];
	int count;
	
	public:
	Store():count(0){}
	
	void addprod(string n,float p){
		if(count<50)
		{
			pr[count++]=Product(n,p);
			cout<<"product added.\n";
		}
		else
		cout<<"inventory full!\n";
	}
	
	void search(string n)
	{
		int f=0;
		for(int i=0;i<count;i++)
		{		
			if(n==pr[i].name)
			{
				cout<<"item found\n";
				cout<<"....item details....\n";
				cout<<"product name: "<<pr[i].name<<endl;
				cout<<"product id: "<<pr[i].id<<endl;
				cout<<"product price: "<<pr[i].price<<endl;
				f=1;
			}			
		}
		if(f==0)
		cout<<"item not found!\n";
		
	}
	
	void sort()
	{
            for (int i = 0; i < count - 1; i++){
                for (int j = 0; j < count - i - 1; j++){
                    if (pr[j].price > pr[j + 1].price){
                        Product temp = pr[j + 1];
                        pr[j + 1] = pr[j];
                        pr[j] = temp;
                    }
                }
            }
            cout<<"list sorted.\n";
    }
    
    void display()
    {
    	cout<<"...Product List...\n";
    	
    	for(int i=0;i<count;i++)
    	{
    		cout<<"Product "<<i+1<<" :\n";
    		cout<<"ID: "<<pr[i].id<<endl<<"name: "<<pr[i].name<<endl<<"price: "<<pr[i].price<<" $"<<endl;
		}
	} 
	
};

int main()
{
	Store s;
	
	while(1)
	{
		int op;
		cout<<"\t\t Inventory Options\n___________________________________________________________\n";
		cout<<"1.Add product\n2.sort by price\n3.search\n4.Display\n5.exit\n";
		cout<<"\nchoose an option: ";cin>>op;
		
		switch(op)
		{
			case 1:
			{
				string n;
				float p;
				cout<<"enter name of product: ";cin>>n;
				cout<<"enter price of product: ";cin>>p;
				s.addprod(n,p);
				break;
			}
			case 2:
			{
				s.sort();
				s.display();
				break;
			}
			case 3:
			{
				string n;
				cout<<"enter name of product to search for: ";cin>>n;
				s.search(n);
				break;
			}
			case 4:
			{
				s.display();
				break;
			}
			case 5:
				cout<<"exiting...";
				return 0;
			default:
				cout<<"enter correct option>\n";
		}
	}
	
	
}
