#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int  distinctCount(vector<int>arr){
    int n=arr.size();

    unordered_set<int>s;

    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }

    for(int el : s){
        cout<<el<<" ";
    }
    cout<<endl;
    return s.size();
}
int main(){
    vector<int>arr={4,3,2,5,6,7,3,4,2,1};
    cout<<"count: "<<distinctCount(arr)<<endl;
    return 0;
}