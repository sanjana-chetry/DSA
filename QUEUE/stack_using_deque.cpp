#include<iostream>
#include<deque>
using namespace std;
class Stack{
    deque<int>deq;
public:
    void push(int data){
        deq.push_back(data);
    }
    void pop(){
        deq.pop_back();
    }
    int top(){
        return deq.back();
    }
    
};
int main(){
    Stack s;
    for(int i=0;i<5;i++){
        s.push(i);
    }
    for(int i=0;i<5;i++){
        cout<<s.top()<<endl;
        s.pop();
    }
}