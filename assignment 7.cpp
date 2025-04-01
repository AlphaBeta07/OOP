#include <iostream>
#include <string>
using namespace std;

class bankAccount{
	private:
		string owner_name;
		double balance;
	public:
		bankAccount(string name, double init_balance){
			owner_name = name;
			balance = init_balance;
		}
		
		void deposit(double amount){
			if(amount > 0){
				balance += amount;
				cout<<"deposited amount "<<amount;
			} else {
				cout<<"tnvalid amount";
			}
		}
		void withdraw(double amount){	
			if (amount > balance){
				cout<<"Insufficient funds in account"<<endl;
			} else {
			balance -= amount;
			cout<<"withdraw "<<amount<<endl;
			cout<<"remainging balance is "<<balance<<endl;
			}
		}
		void transfer(bankAccount &to, double amount){
			if(amount > balance){
				cout<<"insufficient balance "<<endl;
			} else {
			balance -= amount;
			to.balance += amount;
			cout<<"tranferred amount is  "<<amount<<" from "<<owner_name<<" to "<<to.owner_name<<endl;
			}
		}
		void divideBalance(double divisor){
			
		}
		void display(){
			cout<<"acc owner "<<owner_name;
			cout<<"balance is "<<balance<<endl;
			
		}
};
int main(){
	bankAccount account1("anish",1000);
	bankAccount account2("abhay",1000);
	account1.display();
	account2.display();
	account1.deposit(200);
	account1.withdraw(300);
	account1.transfer(account2, 400);
	account1.display();
	account2.display();
}	
