#include<iostream>
using namespace std;

struct Book{
	int bookID;
	string title;
	string author;
	bool isavailable;
};
Book* memoryall(int size)
{
	Book* book=new Book[size];
	return book;
}
void add(Book * book,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<"BOOK ID: ";
		cin>>book[i].bookID;
		cin.ignore();
		cout<<"Title: ";
		getline(cin,book[i].title);
		cout<<"Author: ";
		getline(cin,book[i].author);
		book[i].isavailable=true;
	}
}
void removing(Book* &book,int &size)
{
	int rem,found=0;
	cout<<"Enter BookID to be removed: ";
	cin>>rem;
	
	 for(int i=0;i<size;i++){
        if(book[i].bookID == rem) {
            found = 1;
            for(int j=i;j<size-1;j++){
                book[j] = book[j+1];
            }
			size-=1;
			return;
		}
	}
		if(!found)
		{
			cout<<"Incorrect BOOKID."<<endl;
		}
}
void search(Book *book,int size)
{
	int search,found=0;
	cout<<"Enter BookID to search: ";
	cin>>search;
	for(int i=0;i<size;i++)
	{
		if(book[i].bookID==search)
		{
			cout<<"BookID: "<<book[i].bookID<<endl;
			cout<<"Title: "<<book[i].title<<endl;
			cout<<"Author: "<<book[i].author<<endl;
			cout<<"Available: "<<book[i].isavailable<<endl;
			found=1;
			break;
		}
	}
	if(!found){
		cout<<"Book not Available."<<endl;
	}
}
void display(Book* book,int size)
{
	cout<<"Displaying all available books: "<<endl;
	for(int i=0;i<size;i++)
	{
		if(book[i].isavailable==true)
		{
			cout<<"BookID: "<<book[i].bookID<<endl;
			cout<<"Title: "<<book[i].title<<endl;
			cout<<"Author: "<<book[i].author<<endl;
			cout<<"Available: "<<book[i].isavailable<<endl;
		}
	}
}
void freeing(Book* book)
{
	delete[] book;
}
int main()
{
	int n;
	cout<<"Enter number of books to be added: ";
	cin>>n;
	Book* book=memoryall(n);
	add(book,n);
	removing(book,n);
	search(book,n);
	display(book,n);
	freeing(book);
	return 0;
}