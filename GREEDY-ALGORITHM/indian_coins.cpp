//We are given an infinite supply of denominations [1,2,5,10,20,100,500,2000]
//Find minimum no of coins to make change for a value V
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int minCoins(vector<int>coins,int v){
    int n=coins.size();
    int ans=0;
    for(int i=n-1;i>=0 && v>0;i--){
        if(v>=coins[i]){
            ans+= v/coins[i];
            v= v%coins[i];
        }
    }
    cout<<"minimum number of coins:"<<ans<<endl;
    return ans;
}
int main(){
    vector<int>coins={1,2,5,10,20,50,100,500,2000};
    int v=590;
    minCoins(coins,v);
    return 0;
}