#include<iostream>
using namespace std;
int largest(int a,int b,int c)
{
    if(a>b && a>c){
        cout<< "a is the largest";
    }
    else if(b>a && b>c){
        cout<< "b is the largest";
    }
    else{
        cout <<"c is gthe largest";
    }
}
int main(){
    largest(2,5,1);
    
    return 0;
}