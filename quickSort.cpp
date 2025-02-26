#include <iostream>
using namespace std;
int Partition(int a[], int p, int q) {
    int v = a[p];
    int i = p;
    int j = q;
    while (true){
        while (a[i] <= v && i <= q) i++;
        while (a[j] > v && j >= p) j--;
        if (i<j){
            swap(a[i], a[j]);
        } else {
            break;
        }
    }
    swap(a[p], a[j]);
    return j;
}
void QuickSort(int a[], int p, int q) {
    if (p<q){
        int j = Partition(a, p, q);
        QuickSort(a, p, j - 1);
        QuickSort(a, j + 1, q);
    }
}
void printArray(int a[], int n){
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int a[]={-8, 15, 60, 17, 31, 47, 13, -5};
    int n = sizeof(a) / sizeof(a[0]);
    cout<<"Original array: ";
    printArray(a, n);
    QuickSort(a, 0, n - 1);
    cout<<"Sorted array: ";
    printArray(a, n);
    return 0;
}
