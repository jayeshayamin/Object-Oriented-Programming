#include<iostream>
#include<string>
using namespace std;

class Book{
    private:
    string title;
    double *price;
    int *stocks;
    double *totalcost;
    public:
    
    Book(string newtitle,double newprice,int newstocks)
    {
        this->title=newtitle;
        this->price=new double(newprice);
        this->stocks=new int(newstocks);
        this->totalcost=new double;
        *(this->totalcost)=0.0;
    }
    
    Book(Book &originalbook)
    {
        this->title=originalbook.title;
        this->price=new double(*originalbook.price);
        this->stocks=new int(*originalbook.stocks);
        this->totalcost=new double(*originalbook.totalcost);
    }

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

    void display()
    {
        cout<<"Inventory: "<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<*(this->price)<<endl;
        cout<<"Stocks: "<<*(this->stocks)<<" Units"<<endl;
        cout<<"\n"<<endl;
    }
    
    ~Book()
    {
    	delete price;
    	delete stocks;
    	delete totalcost;
    	cout<<"Destructor called for book: "<<this->title<<endl;
	}
};

int main()
{
    Book b1("1984",250.0,45);
    b1.display();
    b1.purchase(10);
    b1.display();
    b1.purchase(31);
    b1.display();
    b1.purchase(10);
    b1.display();
    b1.update("Tuesdays With Morrie",490.0,15);
    b1.display();
    b1.purchase(13);
    Book b2(b1);
    b2.display();
    b1.update("1984",250.0,35);
    b1.display();
    b2.purchase(14);
    b2.display();

return 0;
}