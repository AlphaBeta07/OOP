#include <iostream>
using namespace std;
class Point{
	private:
		int xc;
		int yc;
	public:
		void setCoordinates();
		void displayCoordinates();
		Point();
		Point(int,int);
		Point operator -(Point &obj);
};
Point::Point(int x,int y){
	xc=x;
	yc=y;
}
Point Point::operator -(Point &obj){
	return Point(xc-obj.xc, yc-obj.yc);
}
void Point::setCoordinates(){
	cout<<"\n Enter x-coordinates : ";
	cin>>xc;
	cout<<"\n Enter y-coordinates : ";
	cin>>yc;
}
void Point::displayCoordinates(){
	cout<<"\n The x coordinates are "<<xc;
	cout<<"\n The y coordinates are "<<yc;
}
Point::Point(){
	xc=0;
	yc=0;
}
int main(){
	Point P1,P2;
	P1.setCoordinates();
	P2.setCoordinates();
	
	cout<<"\nThe coordinates of P1 are : ";
	P1.displayCoordinates();
	cout<<"\n";
	
	cout<<"\nThe coordinates of P2 are : ";
	P2.displayCoordinates();
	cout<<"\n";
	
	Point P3 = P2 - P1;
	cout<<"\nThe coordinates of P3 are : ";
	P3.displayCoordinates();
	return 0;
}
