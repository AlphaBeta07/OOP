#include<iostream>
//operator overloading
using namespace std;
class point{
    private:
        int x,y;
    public:
        point(int xc=0,int yc=0):x(xc),y(yc){
		}
        point operator-(const point&obj){
            return point(x-obj.x,y-obj.y);
        }
        void display(){
            cout<<x<<y<<endl;
        }
};
int main(){
    point p1(5,6); 
    point p2(2,3);
    point p3=p1-p2;
    p3.display();
    return 0;
}
