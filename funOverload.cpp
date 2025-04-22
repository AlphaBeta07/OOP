#include<iostream>
using namespace std;
class shape{
	public:
		void area(int r){
			cout<<"area of circle ="<<3.14*r*r<<endl;
		}
		void area(int l,int b){
			cout<<"area of rectangle ="<<l*b<<endl;
		}
};
int main(){
	shape s;
	s.area(10);
	s.area(5,6);
	return 0;
}
