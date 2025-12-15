#include<iostream>
#include<stack>
#include<string>
using namespace std;
void pushAtBottom(stack<int> &s,int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int temp=s.top();
    s.pop();
    pushAtBottom(s,val);
    s.push(temp);
}
void reverseStack(stack<int>s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s,temp);
}
int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    reverseStack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}