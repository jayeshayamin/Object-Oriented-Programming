#include<iostream>
#include<string>
using namespace std;

class Book{
    private:
    string title;
    float price;
    int *stocks;
   
    public:
    Book(string title,float price,int newstocks)
    {
        this->title=title;
        this->price=price;
        this->stocks=new int;
        *stocks=newstocks;
    }

    void update(string newtitle,float newprice,int newstocks)
    {
        title=newtitle;
        price=newprice;
        *stocks=newstocks;
        cout<<"Book Updated."<<endl;
    }

    void purchase(int quantity)
    {
    	if(quantity<=*stocks){
        float totalCost=(price)*quantity;
        float discount=0;

    if(quantity>5&&quantity<10)
        discount=totalCost*0.05;
    else if(quantity>=10)
        discount=totalCost*0.10;

    cout<<"Discount Applied: Rs."<<discount<<endl;
    cout<<"Final Payment: Rs."<<totalCost-discount<<endl;
    *stocks-=quantity;
    if(*stocks<5)
    {
    	cout<<"Bulk is low."<<endl;
	}
	}
    
    else
    {
    	cout<<"Stock too low for bulk purchase.Update stock."<<endl;
	}
    }
    
    void display()
    {
        cout<<"Inventory: "<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Stocks: "<<*stocks<<" Units"<<endl;
        cout<<"\n"<<endl;
    }
    
    ~Book()
    {
    	delete stocks;
	}
};

int main()
{
    Book b1("1984",250.0,45);
    Book b2("Tuesdays With Morrie",450.0,15);
    b1.display();
    b1.update("1984",100.0,45);
    b2.display();
    b2.update("Tuesdays With Morrie",490.0,15);
    b1.display();
    b1.purchase(39);
    b1.display();
    b1.purchase(5);
    b1.display();
    b2.purchase(9);
    b1.display();
    b1.purchase(5);
    b1.display();

}