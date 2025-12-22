#include<iostream>
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

Node* buildBalancedBST(int arr[],int start,int end){
    if (start > end){
        return NULL;
    }
    int mid = start + (end-start)/2;

    Node* currNode= new Node(arr[mid]);

    currNode->left=buildBalancedBST(arr,start,mid-1);
    currNode->right=buildBalancedBST(arr,mid+1,end);

    return currNode;
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
    int arr[7]={3,4,5,6,7,8,9};
    Node* root=buildBalancedBST(arr,0,6);
    preOrder(root);
    return 0;
}