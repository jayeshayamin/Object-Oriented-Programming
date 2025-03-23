#include<iostream>
#include<string>
using namespace std;

class Media{
	public:
	string title;
	int publicationdate;
	static int uniqueid;
	string publisher;
	bool available; 
	
	Media(string t,int p,string i):title(t),publicationdate(p),publisher(i),available(1)
	{
		uniqueid++;	
	}
	
	virtual void displayinfo()
	{
		cout<<"ID: "<<uniqueid<<" | Title: "<<title<<" | Publication Date: "<<publicationdate<<" | Publisher: "<<publisher<<"Available: "<<(available?"YES":"NO")<<endl;
	}
	void checkout()
	{
		if(available)
		{
			available=0;
			cout<<"Media: "<<title<<"  borrowed successfully!"<<endl;
		}
		else
		{
			cout<<"Failed. Media: "<<title<<" already borrowed."<<endl;
		}
	}
	
	void returnitem()
	{
		if(!available)
		{
			available=1;
			cout<<"Media: "<<title<<"  returned successfully!"<<endl;
		}
		else
		{
			cout<<"Failed.Media: "<<title<<" already returned."<<endl;
		}
	}
	virtual ~Media(){
	}
};
int Media::uniqueid=0;

class Book:public Media{
	public:
		string author;
		int isbn;
		int nopages;
		
		Book(string t,int p,string q,string a,int isbn,int pages):Media(t,p,q),author(a),isbn(isbn),nopages(pages){}
		
		void displayinfo()
		{
			Media::displayinfo();
			cout<<"Author: "<<author<<" | ISBN: "<<isbn<<" | Number of Pages: "<<nopages<<endl;
			cout<<"********************************************************************"<<endl;
		}
};

class DVD:public Media{
	public:
		string director;
		float duration;
		float rating;
		
		DVD(string t,int p,string q,string a,float d,float r):Media(t,p,q),director(a),duration(d),rating(r){}
		
		void displayinfo()
		{
			Media::displayinfo();
			cout<<"Director: "<<director<<" | Duration: "<<duration<<" | Rating: "<<rating<<endl;
			cout<<"********************************************************************"<<endl;
		}
};

class CD:public Media{
	public:
		string artist;
		int notracks;
		string genre;
		
		CD(string t,int p,string q,string a,int d,string r):Media(t,p,q),artist(a),notracks(d),genre(r){}
		
		void displayinfo()
		{
			Media::displayinfo();
			cout<<"Artist: "<<artist<<" | Number of Tracks: "<<notracks<<" | Genre: "<<genre<<endl;
			cout<<"********************************************************************"<<endl;
		}
};
int main() {
    Book book1("The Great Gatsby", 1925, "Scribner", "F. Fitzgerald", 123456, 180);
    DVD dvd1("Inception", 2010, "Warner Bros", "C. Nolan", 148.0, 8.8);
    CD cd1("Thriller", 1982, "Epic Records", "M. Jackson", 9, "Pop");

    book1.displayinfo();
    dvd1.displayinfo();
    cd1.displayinfo();

    book1.checkout();
    dvd1.checkout();
    cd1.checkout();

    book1.returnitem();
    dvd1.returnitem();
    cd1.returnitem();
	book1.returnitem();
    return 0;
}