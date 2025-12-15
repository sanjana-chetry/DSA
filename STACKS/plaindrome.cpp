#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;
template<class T>
class Node{
public:
    T data;
    Node<T>* next;
    Node(T val){
        data=val;
        next=NULL;
    }
};
template <class T>
class Stack{
    Node<T>* head;
public:
    Stack(){
        head=NULL;
    }
    void push(T val){
        Node<T>* newNode=new Node<T>(val);
        if(head==NULL){
            head=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }
    void pop(){
        Node<T>* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;

    }
    T top(){
        return head->data;
    }
     bool isEmpty(){
        return head==NULL;
    }
//push at bottom
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
//reverse the linkedlist
void reverseStack(stack<int>s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s,temp);
}
};
int main(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(2);
    s.push(1);
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }  
    return 0;
}