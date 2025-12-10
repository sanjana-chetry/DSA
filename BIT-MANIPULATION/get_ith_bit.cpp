#include<iostream>
using namespace std;
// int getIthBit(int num,int i){
//     int bitMask=1<<i;
//     if(!(num & bitMask)){
//         return 0;
//     }
//     else{
//         return 1;
//     }

// }

// int setBit(int num,int i){
//     int bitMask=1<<i;
//     return (num|bitMask);
// }

int clearBit(int num, int i){
    int bitMask=~(1<<i);
    return (num&bitMask);
}
int main(){
    int num;
    cout<<"enter the number:";
    cin>>num;
    int i;
    cout<<"enter the ith position:";
    cin>>i;
    // cout<<getIthBit(num,i);
    // cout<<setBit(num,i);
    cout<<clearBit(num,i);
    return 0;
}