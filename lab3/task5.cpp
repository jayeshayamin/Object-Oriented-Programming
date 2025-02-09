#include<iostream>
using namespace std;

class GroceryStore{
	private:
	string itemname[100];
	float itemprices[100];
	int count;
	
	public:
		GroceryStore()
		{
			count=0;
		}
		
		void additem(string name,int price)
		{
			if(count>=100)
			{
				return;
			}
			int found=0;
			for(int i=0;i<count;i++)
			{
				if(name==itemname[i])
				{
					cout<<"Item already exists."<<endl;
					found=1;
					return;
				}}
				if(!found)
				{
					itemname[count]=name;
					itemprices[count]=price;
					cout<<"Item added to list."<<endl;
					count++;
					if(count==100)
					{
						cout<<"List is full."<<endl;
					}
				}
		}
		
		void view()
		{
			cout<<"**************"<<endl;
			cout<<"Inventory: "<<endl;
			for (int i=0;i<count;i++)
			{
				cout<<"Item"<<i+1<<" Name: "<<itemname[i]<<endl;
				cout<<"Item"<<i+1<<" Price: "<<itemprices[i]<<endl;	
			}	
		}
		
		void update(string name,int newprice)
		{
			int found=0;
			for(int i=0;i<count;i++)
			{
				if(itemname[i]==name)
				{
					itemprices[i]=newprice;
					cout<<"Item price update!"<<endl;
					found=1;
					break;
				}}
				if(!found)
				{
					cout<<"Item not found."<<endl;
				}
			}
		
		void receipt(int quantity)
		{
			int total,found;
			float sumprices=0;
			string name;
			cin.ignore();
			for(int i=1;i<=quantity;i++)
			{
				found=0;
				cout<<"Enter name of item: ";
				getline(cin,name);
				cout<<"Enter quantity of item: ";
				cin>>total;
				cin.ignore();
				for(int j=0;j<this->count;j++)
				{
					if(itemname[j]==name)
					{
						float sum=0;
						sum+=itemprices[j]*total;
						sumprices+=sum;
						found=1;
						cout<<itemname[j]<<" x "<<total<<" = "<<sum<<" PKR"<<endl;
                		found = 1;
                		break;
					}
				}
				if(!found)
				{
					cout<<"Item not found."<<endl;
				}
			}
		cout<<"************** RECEIPT **************"<<endl;
        cout<<"Total Bill: "<<sumprices<<" PKR"<<endl;
        cout<<"*************************************"<<endl;
		}
		
};

int main()
{
	GroceryStore list;
	int choice,price;
	string name;
	cout<<"Welcome to your Grocery Shop List!"<<endl;
	while(1)
	{
		cout<<"************"<<endl;
		cout<<"MENU: "<<endl;
		cout<<"1.Add item."<<endl;
		cout<<"2.Generate receipt."<<endl;
		cout<<"3.Update price."<<endl;
		cout<<"4.Display items."<<endl;
		cout<<"5.Exit."<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
		switch (choice)
		{
			case 1:
				cout<<"Enter item name: ";
				cin.ignore();
				getline(cin,name);
				cout<<"Enter price: ";
				cin>>price;
				list.additem(name,price);
				break;
			case 2:
				int quantity;
				cout<<"Enter the quantity of different things to buy: ";
				cin>>quantity;
				if(quantity<=100)
				{
					list.receipt(quantity);
				}
				else
				{
					cout<<"Please enter valid quantity."<<endl;
				}
				break;
			case 3:
				cout<<"Enter item name: ";
				cin.ignore();
				getline(cin,name);
				cout<<"Enter price: ";
				cin>>price;
				list.update(name,price);
				break;
			case 4:
				list.view();
				break;
			case 5:
				cout<<"Exiting..."<<endl;
				return 0;
				break;
			default:
				cout<<"Invalid choice."<<endl;
		}
	}
}