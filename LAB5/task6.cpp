#include<iostream>
using namespace std;


class Movie{
	public:
		string title;
		string director;
		string duration;
		
		Movie(){}
		
		Movie(string t,string di,string du):title(t),director(di),duration(du){}

};

class Cinema{
	Movie m[5];
	string name;
	int count;
	
	public:	
		Cinema(Movie mo[],int c,string n):count(c),name(n){
			
			for(int i=0;i<count;i++)
			{
				m[i]=mo[i];
			}
		}
		
		void display(){
			cout<<"\t\t"<<name<<endl;
			cout<<"\nMovies curently being screened: \n";
			cout<<"_______________________\n";
			
			
			for(int i=0;i<count;i++)
			cout<<"\ntitle: "<<m[i].title<<endl<<"director: "<<m[i].director<<endl<<"duration: "<<m[i].duration<<endl<<"___________________________\n";
		}
};

int main(){
	
	
	Movie List[]={
		
	Movie("Godzilla","tom hanks","2 hours"),
	Movie("Logan","hugh jackman","2.5 hours"),
	Movie("Avengers Endgame","Russo brothers","3 hours"),
	};
	
	Cinema c(List,3,"NUPLEX CINEMA");
	
	c.display();
	
}
