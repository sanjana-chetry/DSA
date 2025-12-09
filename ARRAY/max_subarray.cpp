#include<iostream>
#include<climits>
using namespace std;
void subArray(int *arr,int n){
    int maxSum=INT_MIN;
    for(int start=0;start<n;start++)
    {
        for(int end=start;end<n;end++)
        {
            int sum=0;
            // cout<<"( "<<start<<","<<end<<")";
            for(int i=start;i<=end;i++)
            {
                sum=sum+arr[i];
            }
            cout<<sum<<", ";
            maxSum=max(sum,maxSum);
        }
        cout<<endl;
    }
    cout<<"the maximum sum is :"<<maxSum;
}
int main(){
    int arr[6]={2,-3,6,-5,4,2};
    int n=6;
    subArray(arr,n);
    return 0;
}