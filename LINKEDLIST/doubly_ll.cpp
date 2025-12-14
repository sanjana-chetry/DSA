#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=prev=NULL;
    }
};
class DoublyList{
public:
    Node* head;
    Node* tail;
    DoublyList(){
        head=NULL;
        tail=NULL;
    }
    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;

        }
    }
    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;

        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    void pop_front(){
        Node* temp=head;
        head=head->next;
        if(head!=NULL){
            temp->next=head;
            head->prev=NULL;
        }
        temp->next=NULL;
        delete temp;
    }
    void pop_back(){
        Node* temp=tail;
        tail=temp->prev;
        while(tail!=NULL){
            tail->next=NULL;
        }
        temp->prev=NULL;
        delete temp;
    }
    void printList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main(){
    DoublyList dll;
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);
    dll.push_back(4);
    dll.push_back(5);
    dll.printList();
    dll.pop_front();
    dll.printList();
    dll.pop_back();
    dll.printList();
    return 0;
}