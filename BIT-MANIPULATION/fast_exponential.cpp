#include<iostream>
using namespace std;
void fastExponential(int x,int n){
    int ans=1;
    while(n>0){
        int lastBit=n & 1;
        if(lastBit){
        ans=ans*x;
        }
        x=x*x;
        n=n>>1;
    }
    cout<<ans;
}
int main(){
    int x;
    cout<<"enter the number:";
    cin>>x;
    int n;
    cout<<"enter the power:";
    cin>>n;
    fastExponential(x,n);
    return 0;
}