#include<iostream>
using namespace std;
class Date{
    int date,month,year;
public:
    friend istream &operator>>(istream &in, Date &obj);
    friend ostream &operator<<(ostream &out, const Date &obj);
};
istream &operator>>(istream &in, Date &obj) {
    cout<<"Enter Date(DD MM YYYY):";
    in>>obj.date>>obj.month>>obj.year;
    return in;
}
ostream &operator<<(ostream &out, const Date &obj){
    out<<"Entered Date:"<<obj.date<<"/"<<obj.month<<"/"<<obj.year;
    return out;
}
int main(){
    Date d1;
    cin>>d1;
    cout<<d1;
    return 0;
}

