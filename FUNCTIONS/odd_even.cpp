#include<iostream>
using namespace std;
void oddEven(int num){
    if(num%2==0){
    cout<<"the number is even";
    }
    else{
        cout<<"the number is odd";
    }

}
int main(){
    oddEven(5);
    return 0;
}