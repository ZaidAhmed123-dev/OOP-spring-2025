#include<iostream>
using namespace std;

class Librarian;

class Book{
	string title;
	float price;
	
	public:
		Book(string t,float p):title(t),price(p){
		}
		
		friend class Librarian;
};

class Librarian{
	
	public:
		
		void display(Book B){
			cout<<"title: "<<B.title<<endl;
			cout<<"price: "<<B.price<<" Rs."<<endl;
		}
		
		float applyDiscount(float discount,Book B){
			return B.price-((discount/100)*B.price); 
		}
};

int main()
{
	Book B("Death toll",4000);
	
	Librarian L;
	
	L.display(B);
	
	cout<<"The price after 20% discount is :"<<L.applyDiscount(20,B)<<" Rs."<<endl;
}
