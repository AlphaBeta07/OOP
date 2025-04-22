#include<iostream>
#include<string>
using namespace std;
class BankAccount{
private:
    string ownerName;
    double balance;
public:
    BankAccount(string name, double initialBalance){
        ownerName=name;
        balance=initialBalance;
    }
    void deposit(double amount){
        if(amount>0){
            balance+=amount;
            cout<<"Deposited:"<<amount<<endl;
        } 
		else{
            cout<<"Invalid deposit amount"<<endl;
        }
    }
    void withdraw(double amount){
        if(amount>balance){
            cout<<"Insufficient Funds Exception"<<endl;
        } 
		else{
            balance-=amount;
            cout<<"Withdrew:"<<amount<<endl;
            cout<<"Remaining balance:"<< balance<<endl;
        }
    }
    void transfer(BankAccount &to, double amount){
        if(amount>balance){
            cout<<"Insufficient funds for transfer"<<endl;
        } 
		else{
            balance-=amount; 
            to.balance+=amount;
            cout<<"Transferred:"<<amount<<"from"<<ownerName<<"to"<<to.ownerName<<endl;
        }
    }
    void display(){
        cout<<"Account owner:"<<ownerName<<endl;
        cout<<"Current balance:"<<balance<<endl;
    }
};
int main() {
    BankAccount account1("atharv",1000);
    BankAccount account2("samarth",500);
    account1.display();
    account2.display();
    account1.deposit(200);
    account1.withdraw(300);
    account1.transfer(account2,400);
    account1.display();
    account2.display();
    return 0;
}
