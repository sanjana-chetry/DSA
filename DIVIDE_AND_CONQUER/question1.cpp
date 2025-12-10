// Apply Merge sort to sort an array of Strings.(Assume that all the characters in all the Strings are in lowercase).
// (EASY)Sample Input1:arr = {"sun","earth","mars","mercury"}
// Sample Output1:arr={"earth","mars","mercury","sun"}

#include<iostream>
#include<vector>
#include<string>
using namespace std;
void merge(string arr[],int si,int mid,int ei){
    vector<string>temp;
    int i=si;
    int j=mid+1;
    while(i<=mid && j<=ei){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=ei){
        temp.push_back(arr[j++]);
    }
    for(int idx=si,x=0;idx<=ei;idx++){
        arr[idx]=temp[x++];
    }
}
void mergeSort(string arr[],int si,int ei){
    if(si>=ei){
        return;
    }
    int mid=si+(ei-si)/2;
    mergeSort(arr,si,mid);//left part
    mergeSort(arr,mid+1,ei);//right part
    merge(arr,si,mid,ei);
}
void printArr(string arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    string arr[4]={"sun","earth","mars","mercury"};
    int n=4;
    mergeSort(arr,0,n-1);
    printArr(arr,n);
    return 0;
}