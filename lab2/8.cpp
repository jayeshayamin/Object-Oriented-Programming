#include<iostream>
using namespace std;

struct Product{
	int productID;
	string name;
	int quantity;
	float price;
};
Product* memoryall(int size)
{
	Product* product=new Product[size];
	return product;
}
void add(Product* product,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<"Product ID: ";
		cin>>product[i].productID;
		cin.ignore();
		cout<<"Name: ";
		cin>>product[i].name;
		cout<<"Quantity: ";
		cin>>product[i].quantity;
		cout<<"Price: ";
		cin>>product[i].price;
	}
}
void removing(Product* &product,int &size)
{
	int rem,found=0;
	cout<<"Enter ProductID to be removed: ";
	cin>>rem;
	
	 for(int i=0;i<size;i++){
        if(product[i].productID == rem) {
            found = 1;
            for(int j=i;j<size-1;j++){
                product[j] = product[j+1];
            }
			size-=1;
			return;
		}
	}
		if(!found)
		{
			cout<<"Incorrect ProductID."<<endl;
		}
}
void update(Product *product,int size)
{
	int search,found=0;
	cout<<"Enter ProductID to search: ";
	cin>>search;
	for(int i=0;i<size;i++)
	{
		if(product[i].productID==search)
		{
		cout<<"Product ID: ";
		cin>>product[i].productID;
		cin.ignore();
		cout<<"Name: ";
		cin>>product[i].name;
		cout<<"Quantity: ";
		cin>>product[i].quantity;
		cout<<"Price: ";
		cin>>product[i].price;
		found=1;
		break;
		}
	}
	if(!found){
		cout<<"Product not Available."<<endl;
	}
}
void display(Product* product,int size)
{
	float inventory[size];
	cout<<"Displaying total value of inventory: "<<endl;
	for(int i=0;i<size;i++)
	{
		inventory[i]=product[i].price*product[i].quantity;
	}
	for(int i=0;i<size;i++)
	{
		cout<<"Product "<<i+1<<" Total Value: "<<inventory[i]<<endl;
	}
	
}
void freeing(Product* product)
{
	delete[] product;
}
int main()
{
	int n;
	cout<<"Enter number of products to be added: ";
	cin>>n;
	Product* product=memoryall(n);
	add(product,n);
	removing(product,n);
	update(product,n);
	display(product,n);
	freeing(product);
	return 0;
}