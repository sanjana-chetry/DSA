#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
public:
    Node* head;
    Node* tail;
    List(){
        head = NULL;
        tail = NULL;
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList(Node* head){
        Node* temp = head;
        while(temp){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

Node* splitAtMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev) prev->next = NULL;
    return slow;
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* zigZag(Node* head){
    if(!head || !head->next) return head;

    Node* rightHead = splitAtMid(head);
    Node* right = reverse(rightHead);
    Node* left = head;

    Node* nextLeft;
    Node* nextRight;
    Node* tail = nullptr;

    while(left && right){
        nextLeft = left->next;
        nextRight = right->next;

        left->next = right;
        tail = right;             // keep track of last merged node

        right->next = nextLeft;

        left = nextLeft;
        right = nextRight;
    }

    // Connect any remaining node
    if(left) tail->next = left;

    return head;
}

int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    cout << "Original: ";
    ll.printList(ll.head);

    ll.head = zigZag(ll.head);

    cout << "ZigZag:   ";
    ll.printList(ll.head);

    return 0;
}
