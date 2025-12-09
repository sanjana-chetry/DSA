#include<iostream>
#include<climits>
using namespace std;
void maxProfit(int *prices,int n)
{
    int bestBuy[100000];
    bestBuy[0]=INT_MAX;
    for(int i=0;i<n;i++)
    {
        bestBuy[i]=min(bestBuy[i-1],prices[i-1]);
    }
    int maxProfit=0;
    for(int i=0;i<n;i++)
    {
        int currProfit=prices[i]-bestBuy[i];
        maxProfit=max(maxProfit,currProfit);
    }
    cout<<"the maximum profit is:"<<maxProfit;
}
int main(){
    int arr[]={7,6,5,4,3,2};
    int n=sizeof(arr)/sizeof(int);
    maxProfit(arr,n);
    return 0;
}