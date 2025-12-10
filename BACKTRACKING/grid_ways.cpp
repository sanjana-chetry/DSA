// FIND NO. OF WAYS TO REACH FROM (0,0) TO (N-1,M-1) IN A NxM GRID
// ALLOWED MOVES = RIGHT OR DOWN
#include<iostream>
#include<string>
using namespace std;
int ways(int r,int c,int n,int m,string ans){
    if(r==n-1 && c==m-1){
        cout<<ans<<endl;
        return 1;
    }
    if(r>=n || c>=m){
        return 0;
    }
    // right
    int value1=ways(r,c+1,n,m,ans+"R");
    // down
    int value2=ways(r+1,c,n,m,ans+"D");
    return value1+value2;
}
int main(){
    int n=3;
    int m=3;
    string ans="";
    cout<<"ways="<<ways(0,0,n,m,ans);
    return 0;
}