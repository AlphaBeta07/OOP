#include <iostream>
using namespace std;
void minCoins(int coins[], int n, int amount){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(coins[j]<coins[j+1]){
                int temp=coins[j];
                coins[j]=coins[j+1];
                coins[j+1]=temp;
            }
        }
    }
    int count=0;
    int usedCoins[100], index=0;
    for(int i=0; i<n; i++){
        while(amount>=coins[i]){
            amount-=coins[i];
            usedCoins[index++]=coins[i];
            count++;
        }
    }
    cout<<"Minimum coins required:"<<count<<endl;
    cout<<"Coins used:";
    for(int i=0; i<count; i++){
        cout<<usedCoins[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int coins[]={1,5,10,25};
    int n=sizeof(coins)/sizeof(coins[0]);
    int amount=63;
    minCoins(coins, n, amount);
    return 0;
}
