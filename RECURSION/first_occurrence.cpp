// Find first Occurance of a element in vector
#include<iostream>
#include<vector>
using namespace std;
int firstOcuurrence(vector<int>arr,int i,int target){
    if(i==arr.size()){
        return -1;
    }
    if(arr[i]==target){
        return i;
    }
    return firstOcuurrence(arr,i+1,target);
    
}
int main(){
    vector<int>arr={1,2,3,3,3,4,5};
    cout<<firstOcuurrence(arr,0,3);
    return 0;
}