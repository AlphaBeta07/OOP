#include <iostream>
using namespace std;
void mergeAndCount(int nums[], int result[], int left, int right) {
    if (left>=right) 
	return;
    int mid=left+(right-left)/2;
    mergeAndCount(nums, result, left, mid);
    mergeAndCount(nums, result, mid + 1, right);
    int temp[right-left+1];
    int i=left, j=mid+1, k=0;
    while (i<=mid && j<=right) {
        if (nums[i]<=nums[j]){
            temp[k++]=nums[i++];
        } else {
            result[i]+=(mid-i+1);
            temp[k++]=nums[j++];
        }
    }
    while (i<=mid) {
        temp[k++]=nums[i++];
    }
    while (j<=right) {
        temp[k++]=nums[j++];
    }
    for (int i=0;i<k;i++){
        nums[left+i]=temp[i];
    }
}
void countSmaller(int nums[], int result[], int n) {
    mergeAndCount(nums, result, 0, n - 1);
}
int main(){
    int nums[]={5,2,6,1};
    int n=sizeof(nums)/sizeof(nums[0]);
    int result[n]={0};
    countSmaller(nums, result, n);
    for (int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
