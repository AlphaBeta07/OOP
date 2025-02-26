#include<iostream>
using namespace std;
class circle{
	int r;
	float area;
	public:
		circle(){
			cout<<"enter radius";
			cin>>r;
			area=3.142*r*r;
			cout<<"area 1 = "<<area;
		}
		circle(int r1){
			r=r1;
			area=3.142*r*r;
			cout<<"area 2 = "<<area;
		}
		circle(circle&obj){
			r=obj.r;
			area=3.142*r*r;
			cout<<"area 3 = "<<area;
		}
		~circle(){
			cout<<"destructor run";
		}
};
int main(){
	circle c1;
	circle c2(100);
	circle c3(c2);
	cout<<"main over";
}
