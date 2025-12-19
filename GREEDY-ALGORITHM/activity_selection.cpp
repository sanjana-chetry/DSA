// Select the maximum number of activities that can be performed 
// by a single person.(a person can work on one activity at a time)
#include<iostream>
#include<vector>
using namespace std;
int maxActivityNo(vector<int>start, vector<int> end){
    cout<<"selecting A0"<<endl;
    int count=1;
    int currEnd=end[0];
    for(int i=1;i<start.size();i++){
        if(start[i]>=currEnd){
            cout<<"selecting A"<<i<<endl;
            count++;
            currEnd=end[i];
        }
    }
    return count;
}
int main(){
    vector<int>start={1,3,0,5,8,5};
    vector<int>end={2,4,6,7,9,9};
    cout<<maxActivityNo(start,end);
    return 0;
}