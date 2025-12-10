#include<iostream>
using namespace std;
int search(int arr[],int si,int ei,int tar){
    if(si>ei){
        return -1;
    }
    int mid=si+(ei-si)/2;
    if(arr[mid]==tar)
      return mid;
    // LINE 1
    if(arr[si]<=arr[mid] && tar<=arr[mid]){
        if(arr[si]<=tar && tar<=arr[mid]){
            // LEFT_HALF CALL
            return search(arr,si,mid-1,tar);
        }
        else{
            // RIGHT CALL
            return search(arr,mid+1,ei,tar);
        }
    }
    // LINE 2
    else{
        if(arr[mid<=tar && tar<=arr[ei]]){
            // RIGHT CALL
            return search(arr,mid+1,ei,tar);
        }
        else{
           return search(arr,si,mid-1,tar);
        }
    }
}
int main(){
    int arr[7]={4,5,6,7,0,1,2};
    int n=7;
    cout<<"index="<<search(arr,0,n-1,0);
    return 0;
}