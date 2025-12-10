#include<iostream>
using namespace std;
int assignment(int a,int b){
    return a^2+b^2+2*a*b;

}
int main(){
    cout<<assignment(2,3);
    return 0;
}