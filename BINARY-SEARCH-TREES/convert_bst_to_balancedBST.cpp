#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

Node* BSTfromvec(vector<int>arr,int start,int end){
    if (start > end){
        return NULL;
    }
    int mid = start + (end-start)/2;

    Node* currNode= new Node(arr[mid]);

    currNode->left=BSTfromvec(arr,start,mid-1);
    currNode->right=BSTfromvec(arr,mid+1,end);

    return currNode;
}

void getInorder(Node* root,vector<int>&nodes){
    if(root==NULL){
        return ;
    }
    getInorder(root->left,nodes);
    nodes.push_back(root->data);
    getInorder(root->right,nodes);
}

Node* balancedBST(Node* root){
    vector<int>nodes;
    getInorder(root,nodes);
    return BSTfromvec(nodes,0,nodes.size()-1);
}

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    Node* root= new Node(6);
    root->left=new Node(5);
    root->left->left=new Node(4);
    root->left->left->left=new Node(3);

    root->right=new Node(7);
    root->right->right=new Node(8);
    root->right->right->right=new Node(9);
    root = balancedBST(root);
    preOrder(root);
    cout<<endl;
    return 0;
}