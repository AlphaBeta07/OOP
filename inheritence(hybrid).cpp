#include<iostream>
using namespace std;
class A{
    public:
        int a,b;
        void get(){
            cout<<"Enter two numbers:";
            cin>>a>>b;
        }
};
class B : virtual public A{
    public:
        int add;
        void adding(){
            add=a+b;
            cout << "\nSum:"<<add;
        }
};
class C : virtual public A{
    public:
        int subs;
        void sub(){
            subs=a-b;
            cout<<"\nSubtraction:"<<subs;
        }
};
class D : public B, public C{
    public:
        void dis(){
            cout<<"\nSum from class B:"<<add;
            cout<<"\nSubtraction from class C:"<<subs;
        }
};
int main(){
    D obj;
    obj.get();
    obj.adding();
    obj.sub();
    obj.dis();
    return 0;
}
