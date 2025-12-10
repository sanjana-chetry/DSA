#include<iostream>
using namespace std;
void printArr(int *arr,int n){
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void bubbleSort(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        bool isSwap=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                isSwap=true;
            }
        }
        if(!isSwap){
            return;
            }
    }
}
int main(){
    int arr[]={5,4,1,3,2};
    int n=sizeof(arr)/sizeof(int);
    bubbleSort(arr,n);
    printArr(arr,n);

    return 0;
}