#include<iostream>
#include<string>
using namespace std;

class Book{
    private:
    static int count;//cannot initialize in class as it needs to be static amongst all objects for uniqu id
    int *BookID;
    string title;
    double *price;
    int *stocks;
    double *totalcost;
    public:
    
    Book(string newtitle,double newprice,int newstocks):BookID(new int(count++)),title(newtitle),price(new double(newprice)),stocks(new int(newstocks)),totalcost(new double(0.0)){}
    
    Book(const Book &originalbook):BookID(new int(count++)),title(originalbook.title),price(new double(*originalbook.price)),stocks(new int(*originalbook.stocks)),totalcost(new double(*originalbook.totalcost)){}

    void update(string newtitle,double newprice,int newstocks)
	{
		title=newtitle;
        *(this->price)=newprice;
        *(this->stocks)=newstocks;
        cout<<"Book Updated."<<endl;
}
    void purchase(int quantity)
    {
	if(quantity>*(this->stocks))
		{
            cout<<"Stock too low for bulk purchase. Update stock."<<endl;
            return;
        }
    else if(quantity<=*(this->stocks))
		{
        double Cost=(*(this->price))*quantity;
        double discount=0;

   			 if(quantity>5&&quantity<10)
        			discount=Cost*0.05;
   			 else if(quantity>=10)
    			    discount=Cost*0.10;

    	*(this->totalcost)=Cost-discount;

		cout<<"Original Price: "<<(*(this->price)*quantity)<<endl;
    	cout<<"Discount Applied: Rs."<<discount<<endl;
	   	cout<<"Final Payment: Rs."<<*(this->totalcost)<<endl;
		*(this->stocks)-=quantity;
			if(*(this->stocks)<5)
			{
			cout<<"Bulk is low."<<endl;
			}
	}
    }

    void display()const
    {
        cout<<"Inventory: "<<endl;
        cout<<"Book ID: "<<*BookID<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<*(this->price)<<endl;
        cout<<"Stocks: "<<*(this->stocks)<<" Units"<<endl;
        cout<<"\n"<<endl;
    }
    
    ~Book()
    {
    	delete BookID;
    	delete price;
    	delete stocks;
    	delete totalcost;
    	cout<<"Destructor called for book: "<<this->title<<endl;
	}
};

		int Book::count=1;//cannot initialize inside main as it would end up belonging to fuciton 
int main()
{
    Book b1("1984", 250.0, 45);
    b1.display();

    b1.purchase(10);
    b1.display();

    b1.purchase(31);
    b1.display();

    b1.purchase(10);
    b1.display();

    b1.update("Tuesdays With Morrie", 490.0, 15);
    b1.display();

    b1.purchase(13);

    Book b2(b1);
    b2.display();

    b1.update("1984", 250.0, 35);
    b1.display();

    b2.purchase(14);
    b2.display();

    return 0;
}