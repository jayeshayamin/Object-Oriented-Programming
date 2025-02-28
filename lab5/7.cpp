#include<iostream>
#include<string>
using namespace std;

class Product{
	int ID;
	string name;
	float price;
	static int count;
	
	public:
		Product(string s,float p)
		{
			this->ID=++count;
			this->name=s;
			this->price=p;
			cout<<"Product made."<<endl;
		}
		void display()const
		{
			cout<<"ID: "<<this->ID<<" |Name: "<<this->name<<" |Price: "<<this->price<<endl;
		}
		float getprice()
		{
			return price;
		}
		string getname()
		{
			return this->name;
		}
		~Product()
		{
			//delte product.
		}
};
	int Product::count=0;
class Inventory{
	public:
	Product** products;
	int count;
	
	Inventory(){
        count=0;
        products=nullptr;
    }
	void addproduct(Product* product)
	{
		Product** storing=new Product*[count+1];
		for(int i=0;i<count;i++)
		{
			storing[i]=products[i];
		}
		storing[count]=product;
		delete[] products;
		products=storing;
		count++;
	}
	
	void bubblesort()
	{
		if(count<2)
		{
			return;
		}
		else
		{
			for(int i=0;i<count-1;i++)
			{
				for(int j=0;j<count-i-1;j++)
				{
					if(products[j]->getprice()>products[j+1]->getprice())
					{
						Product* temp=products[j];
						products[j]=products[j+1];
						products[j+1]=temp;
					}
				}
			}
		}
	}
	
	void search(string s)const
	{
		int found=0;
		for(int i=0;i<count;i++)
		{
			if(s==products[i]->getname())
			{
				products[i]->display();
				found=1;
			}
		}
		cout<<"Search complete."<<endl;
		if(!found)
		{
			cout<<"Product not found."<<endl;
		}
	}
	 void display()const{
        if(count==0){
            cout<<"No products in inventory.\n";
            return;
        }
        cout<<"Product List:\n";
        for(int i=0;i<count;i++){
            products[i]->display();
        }
    }
    
    ~Inventory()
    {
    	for(int i=0;i<count;i++)
	{
		delete products[i];//since inventory is responsible for storing products it should also dlete them
	}
		delete[] products;
	}
};
int main() {
    Inventory inventory;
    int choice;
    string name;
    float price;

    do{
        cout << "\n--- Store Inventory Menu ---\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Sort by Price\n";
        cout << "4. Search Product\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter product name: ";
                cin >> name;
                cout << "Enter price: ";
                cin >> price;
                inventory.addproduct(new Product(name, price));
                cout << "Product added successfully.\n";
                break;
            case 2:
                inventory.display();
                break;
            case 3:
                inventory.bubblesort();
                break;
            case 4:
                cout<<"Enter product name to search: ";
                cin>>name;
                inventory.search(name);
                break;
            case 5:
                cout<<"Exiting program.\n";
                break;
            default:
                cout<<"Invalid choice! Try again.\n";
        }
    } while (choice!=5);
    return 0;
}