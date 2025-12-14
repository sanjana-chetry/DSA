#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class List{
    
public:
    Node* head;
    Node* tail;
    List(){
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
            tail=newNode;
        }
    }
    void printList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

void removeCycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    bool isCycle=false;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            cout<<"cycle exists"<<endl;
            isCycle=true;
            break;
        }
    }
    if(!isCycle){
    cout<<"cycle doesnot exists "<<endl;
    return ;
    }

    // removal
    slow=head;
    if(slow==fast){
        while(fast->next!=slow){
            fast=fast->next;
         }
         fast->next=NULL;
    }
    else{
        Node* prev=fast;
        while(slow!=NULL){
        slow=slow->next;
        prev=fast;
        fast=fast->next;
        }
        prev->next=NULL;
    }

}
int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();
    ll.push_back(4);
    ll.push_back(5);
    ll.printList();
    ll.tail->next=ll.head;
    removeCycle(ll.head);
    ll.printList();
    return 0;
}