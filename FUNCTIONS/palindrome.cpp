#include<iostream>
using namespace std;
int reverse(int n){
    int rev=0;
    while(n>0)
    {
        int last=n%10;
        rev=rev*10+last;
        n=n/10;
    }
    return rev;
}

bool isPlaidrome(int num){
    int revNum=reverse(num);
    return num==revNum;
}
int main(){

    cout<<isPlaidrome(121);
    return 0;
}