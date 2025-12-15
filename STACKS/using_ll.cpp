#include<iostream>
#include<list>
#include<vector>
using namespace std;
// template<class T>
// class Stack{
//     list<T>ll;
// public:
//     void push(T val){
//         ll.push_front(val);
//     }
//     void pop(){
//         ll.pop_front();
//     }
//     T top(){
//         return ll.front();
//     }
//     bool isEmpty(){
//         return ll.size()==0;
//     }
// };


// WITHOUT USING STL
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
};
int main(){
    Stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }  
    return 0;
}