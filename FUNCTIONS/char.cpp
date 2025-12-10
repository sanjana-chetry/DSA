#include<iostream>
using namespace std;
char getChar(char ch)
{
    if(ch=='z'){
        return 'a';
    }
    else{
        return ch+1;
    }
}
int main(){
    cout<<getChar('s');
    return 0;
}