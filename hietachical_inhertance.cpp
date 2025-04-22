#include <iostream>
using namespace std;
class A{
	public:
	int a, b;
		void get(){
			cout<<"\nEnter two numbers "<<endl;
			cin>>a>>b;
		}
};
class B: public A{
	public:
		int prdt;
		void product(){
			prdt = a * b;
			cout<<"\nProduct is "<<prdt;
		}
};
class C: public A{
	public:
		int sub;
		
		void subs(){
			cout<<a<<b<<endl;
			sub = a - b;
			cout<<"\nSubstraction is "<<sub;
		}
};
int main(){
	A obj;
	obj.get();
	B objj;
	objj.product();
	C obj1;
	obj1.subs();
	return 0;
}
