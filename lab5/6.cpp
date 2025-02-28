#include<iostream>
#include<string>
using namespace std;

class Movie{
	string title;
	string director;
	float duration;
	public:
		Movie():title(" "),director(" "),duration(0.0){};
		Movie(string s,string d,float dur):title(s),director(d),duration(dur){}
		
		void display()const
		{
			cout<<"Title: "<<this->title<<" |Director: "<<this->director<<" |Duration: "<<this->duration<<" Hours"<<endl;
		}
		
		~Movie()
		{
			cout<<"Movie Destructor."<<endl;
		}
};

class Cinemahall{
	public:
	string name;
	Movie movie;
	
	Cinemahall(string n1,string n2,string n3,float q):name(n1),movie(n2,n3,q){
	};
	void display()const
	{
		cout<<"Cinemahall: "<<this->name<<endl;
		movie.display();
	}
	
	~Cinemahall()
	{
		cout<<"Cinemahall Destructor."<<endl;
	}
};
int main()
{
	Cinemahall c1("Nueplex","Batman","Zack Snyder",2.5);
	c1.display();
	
	Cinemahall c2("Atrium","Maze Runner","Mitch Albom",3.0);
	c2.display();
}