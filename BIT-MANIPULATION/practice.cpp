#include<iostream>
using namespace std;
void updateIthBit(int num,int i,int val){
    num= num& ~(1<<i);
    num=num|(val<<i);
    cout<<num;
}
int main(){
    updateIthBit(7,2,0);
    return 0;
}