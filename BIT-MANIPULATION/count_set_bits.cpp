#include<iostream>
using namespace std;
void setBits(int num){
    int count=0;
    while(num>0){
        int lastDigit=num & 1;
        count+=lastDigit;
        num=num>>1;
    }
    cout<<count;
}
int main(){
    int num;
    cout<<"enter the num:";
    cin>>num;
    setBits(num);
    return 0;
}