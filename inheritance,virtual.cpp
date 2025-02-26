#include<iostream>
using namespace std;
class Base{
	public:
	Base(){
		cout<<"cosntructor of base"<<endl;
	}
	void virtual display(){
		cout<<"function of Base Class"<<endl;
	}
};
class Derived:public Base{
	public:
	Derived(){
		cout<<"constructor of Derived"<<endl;
	}
	void display(){
		cout<<"function of Derived Class"<<endl;
	}
	~Derived(){
		cout<<"Destructor of Derived"<<endl;
	}
};
int main(){
	Base* b;
	Base b1;
	Derived d;
	b = &d;
	b->display();
	b = &b1;
	b->display();
	return 0;
}
