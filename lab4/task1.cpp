#include<iostream>
using namespace std;

class Book{
    private:
    string title;
    float price;
    int *stocks;
   
    public:
    Book()
    {
        title="Unknown";
        price=0.0;
        stocks=new int;
        *stocks=30;
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
        if(quantity>*stocks)
        {
           cout<<"Low stock.Purchase cannot be made."<<endl;
        }
        else{
           *stocks-=quantity;
           cout<<"Purchase made!"<<endl;
        }

        if(*stocks<5)
        {
            cout<<"Warning! Low Stocks."<<endl;
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
    Book b1;
    Book b2;
    b1.display();
    b1.update("1984",250.0,45);
    b2.display();
    b2.update("Tuesdays With Morrie",450.0,15);
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