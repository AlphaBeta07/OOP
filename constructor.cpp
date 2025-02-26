#include<iostream>
using namespace std;
class Num{
	int a,b;
	public:
		Num(){
			a=10;
			b=20;
			cout<<"default constructor is called";
		}
		Num(int x, int y){
			a=x;
			b=y;
			cout<<"parametarised constructor is called";
		}
		Num(const Num& obj){
			cout<<"copy constructor is called";
		}
		void Display(){
			cout<<a<<b;
		}
};
int main(){
	Num n;
	n.Display();
	Num n1(4,6);
	n1.Display();
	Num n2(n);
	n2.Display();
	return 0;
}
