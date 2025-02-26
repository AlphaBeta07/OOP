#include<iostream>
using namespace std;
int fact(int num) {
    int i, total = 1;
    for(i = 1; i <= num; i++) {
        total = total * i;
    }
    return total;
}
int main() {
    int num;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Factorial of " << num << " is " << fact(num) << endl;
    return 0;
}
