#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void slidingWindow(vector<int>arr, int K){
    priority_queue<pair<int,int>>pq ;//(arr[],idx)

    for(int i=0; i<K ;i++ ){
        pq.push(make_pair(arr[i],i));
    }

    cout<<"output: "<<pq.top().first<<" ";

    for(int i=K ;i<arr.size() ; i++){
        while(!pq.empty() && pq.top().second <= (i-K)){
            pq.pop();
        }
        pq.push(make_pair(arr[i],i));
        cout<<pq.top().first<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>arr={1,3,-1,-3,5,3,6,7};
    slidingWindow(arr,3);
    return 0;
}