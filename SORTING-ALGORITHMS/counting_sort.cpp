#include<iostream>
#include<climits>
using namespace std;
void printArr(int *arr,int n){
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void countingSort(int *arr,int n)
{
    int frequency[10000];
    int minVal=INT_MAX,maxVal=INT_MIN;
    // RANGE
    for(int i=0;i<n;i++ )
    {
        minVal=min(minVal,arr[i]);
        maxVal=max(maxVal,arr[i]);
    }
    // 1ST STEP
    for(int i=0;i<n-1;i++)
    {
        frequency[arr[i]]++;
    }
    for(int i=minVal,j=0;i<=maxVal;i++)
    {
        while(frequency[i]>0)
        {
            arr[j++]=i;
            frequency[i]--;
        }
    }

}
int main(){
    int arr[]={1,4,1,3,2,4,3,7};
    int n=sizeof(arr)/sizeof(int);
    countingSort(arr,n);
    printArr(arr,n);
    return 0;
}