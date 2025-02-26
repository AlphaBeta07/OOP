#include<iostream>
using namespace std;
class BankAccount
{
	private:
		string AccountHolder;
		double AccountNumber;
		string AccountType;
		double Balance;
	public:
		void getAccountHolder()
		{
			cout<<AccountHolder<<endl;
		}	
		void getAccountNumber()
		{
			cout<<AccountNumber<<endl;
		}
		void getAccountType()
		{
			cout<<AccountType<<endl;
		}
		void getBalance()
		{
			cout<<Balance<<endl;
		}
		void setAccountType(string Saving)
		{
			AccountType = Saving;
		}
		void Deposit(int deposit)
		{		
			Balance += deposit;
			cout<<"\nDeposited Amount : "<<deposit;
			cout<<"\nNew Balance : "<<Balance;
		}
		void Withdraw(int withdraw)
		{
			if(Balance > withdraw)
			{
				Balance = Balance - withdraw;
				cout<<"\nWithdrawing Amount : "<<withdraw;
				cout<<"\nNew Balance : "<<Balance;
			}
			else
			{
				cout<<"\nAmount is greater than balance";
			}	
		}
		BankAccount()
		{
			cout<<"\n\nEnter the name of Account holder : ";
			cin>>AccountHolder;
			cout<<"Enter the Account Number : ";
			cin>>AccountNumber;
			cout<<"Enter the Account Type : ";
			cin>>AccountType;
			cout<<"Enter the Balance : ";
			cin>>Balance;	
		}
		BankAccount(string name,int number,string type,double amount)
		{
			AccountHolder = name;
			AccountNumber = number;
		 	AccountType = type;
			Balance = amount;
		}
		void displayAccountDetails()
		{
			cout<<"\n\nAccount Holder : "<<AccountHolder;
			cout<<"\nAccount Number : "<<AccountNumber;
			cout<<"\nAccount Type : "<<AccountType;
			cout<<"\nBalance : "<<Balance;
		}
};
int main()
{
	BankAccount b1;
	b1.displayAccountDetails();
	b1.Deposit(5000);
	b1.Withdraw(2000);
	BankAccount b2("abhay",420,"saving",100000);
	b2.displayAccountDetails();
	b2.Deposit(10000);
	b2.Withdraw(5000);
}
