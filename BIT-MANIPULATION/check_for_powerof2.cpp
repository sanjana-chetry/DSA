#include<iostream>
using namespace std;
bool powerOfTwo(int num){
    if(!(num & (num-1))){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int num;
    cout<<"enter the number:";
    cin>>num;
    cout<<powerOfTwo(num);
    return 0;
}