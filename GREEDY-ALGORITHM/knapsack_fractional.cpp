//Put items in knapsack to get the maximum total value in the knapsack
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(pair<double,int>p1,pair<double,int>p2){
    return p1.first>p2.first;
}
int fractionalKnapsack(vector<int>val,vector<int>wt,int w){
    int n=val.size();
    vector<pair<double,int>>ratio(n,make_pair(0.0,0));//pair(ratio,index) 
    for(int i=0;i<val.size();i++){
        double r= val[i]/(double)wt[i]; //finding the ratio
        ratio[i]=make_pair(r,i);

    }
    sort(ratio.begin(),ratio.end(),compare);
    int ans=0;
    for(int i=0;i<n;i++){
        int idx=ratio[i].second;
        if(wt[idx]<=w){
            ans+=val[idx];
            w-=wt[idx];
        }
        else{
            ans+=ratio[i].first * w;
            w=0;
            break;
        }
    }
    cout<<"max value= "<<ans<<endl;
    return ans;
}
int main(){
    vector<int>val={60,100,120};
    vector<int>wt={10,20,30};
    int w=50;
    fractionalKnapsack(val,wt,w);
    return 0;
}