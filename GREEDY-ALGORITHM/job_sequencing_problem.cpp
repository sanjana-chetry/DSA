//Maximize the total profit if only one job can be scheduled at a time
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second>p2.second;
}
int maxTotalProfit(vector<pair<int,int>>jobs){
    int n=jobs.size();
    sort(jobs.begin(),jobs.end(),compare);
    int profit=jobs[0].second;
    int safeDeadline=2; // we start from 2 because we have already selected one job which takes one day 
    
    for(int i=1;i<n;i++){
        if(jobs[i].first>=safeDeadline){
            profit+=jobs[i].second;
            safeDeadline++;
        }
    }
    cout<<"Maximum total profit:"<<profit<<endl;
    return profit;

}
int main(){
    int n=4;
    vector<pair<int,int>>jobs(n,make_pair(0,0));
    jobs[0]=make_pair(4,20);
    jobs[1]=make_pair(1,10);
    jobs[2]=make_pair(1,40);
    jobs[3]=make_pair(1,30);
    maxTotalProfit(jobs);
    return 0;
}