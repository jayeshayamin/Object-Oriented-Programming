#include<iostream>
#include<string>
using namespace std;

class Account{
	public:
	int accountNumber;
	float balance;
	
	Account(int a,float b):accountNumber(a),balance(b){}
	void displaydetails()
	{
		cout<<"Account Number: "<<accountNumber<<endl;
		cout<<"Balance: "<<balance<<endl;
	}
};

class SavingsAccount:public Account{
	public:
		float interestrate;
	
	SavingsAccount(int accountnumber,float balance,float interestrate):Account(accountnumber,balance),interestrate(interestrate){}
	void displaydetails()
	{
		Account::displaydetails();
		cout<<"Interest Rate: "<<interestrate<<endl;
	}
};

class CheckingAccount:public Account{
	public:
		float overdraftlimit;
	
	CheckingAccount(int accountnumber,float balance,float overdraftlimit):Account(accountnumber,balance),overdraftlimit(overdraftlimit){}
	void displaydetails()
	{
		Account::displaydetails();
		cout<<"Overdraft Limit: "<<overdraftlimit<<endl;
	}
};
int main()
{
	CheckingAccount c(1029,5000,10000);
	c.displaydetails();
	
	SavingsAccount s(1028,382793,337832);
	s.displaydetails();
	
	return 0;
}