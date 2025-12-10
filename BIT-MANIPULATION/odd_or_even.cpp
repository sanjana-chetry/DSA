#include<iostream>
using namespace std;
void oddEven(int num){
    if(!(num&1)){
        cout<<"even";
    }
    else
        cout<<"odd";
}
int main(){
    int num;
    cout<<"enter the number:";
    cin>>num;
    oddEven(num);
    return 0;
}