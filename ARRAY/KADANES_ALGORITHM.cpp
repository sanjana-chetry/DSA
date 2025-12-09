#include<iostream>
#include<climits>
using namespace std;
void maxSubArray(int *arr,int n){
    int maxSum=INT_MIN;
    int currSum=0;
    for(int i=0;i<n;i++)
    {
        currSum+=arr[i];
        maxSum=max(currSum,maxSum);
        if(currSum<0)
        currSum=0;
    }
    cout<<"the maximum subarray number is:"<<maxSum;
}
int main(){
    int arr[6]={1,2,-3,5,-6,7};
    int n=6;
    maxSubArray(arr,n);
    
    return 0;
}