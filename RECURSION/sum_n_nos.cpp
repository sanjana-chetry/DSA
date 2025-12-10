// Calculate the sum of n natural numbers
#include<iostream>
using namespace std;
int sum(int n){
    if(n==1){
        return 1;
    }
    return n+sum(n-1);

}
int main(){
    int n;
    cout<<"enter the number:";
    cin>>n;
    int ans=sum(n);
    cout<<ans;
    return 0;
}