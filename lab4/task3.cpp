#include<iostream>
#include<string>
using namespace std;

class Book{
    private:
    string title;
    double *price;
    int *stocks;
   
    public:
    
    Book(string newtitle,double newprice,int newstocks)
    {
        this->title=newtitle;
        this->price=new double(newprice);
        this->stocks=new int(newstocks);
    }
    
    Book(Book &originalbook)
    {
        this->title=originalbook.title;
        this->price=new double(*originalbook.price);
        this->stocks=new int(*originalbook.stocks);
    }

    void update(string newtitle,double newprice,int newstocks)
    {
        title=newtitle;
        *price=newprice;
        *stocks=newstocks;
        cout<<"Book Updated."<<endl;
    }

    void purchase(int quantity)
    {
        if(quantity<=*stocks){
        double totalCost=(*price)*quantity;
        double discount=0;

    if(quantity>5&&quantity<10)
        discount=totalCost*0.05;
    else if(quantity>=10)
        discount=totalCost*0.10;

    cout<<"Discount Applied: Rs."<<discount<<endl;
    cout<<"Final Payment: Rs."<<totalCost-discount<<endl;
	*stocks-=quantity;
	if(*stocks<5){
	cout<<"Bulk is low.Purchase not possible."<<endl;
	}}
    
    else
    {
    	cout<<"Stock too low for bulk purchase.Update stock."<<endl;
	}
    }

    void display()
    {
        cout<<"Inventory: "<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<*price<<endl;
        cout<<"Stocks: "<<*stocks<<" Units"<<endl;
        cout<<"\n"<<endl;
    }
    
    ~Book()
    {
    	delete price;
    	delete stocks;
    	cout<<"Destructor called for book: "<<title<<endl;
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

}