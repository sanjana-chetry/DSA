#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        right=left=NULL ;
    }
};

Node* insert(Node* root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }else{
        root->right=insert(root->right,val);
    }
    return root;
}

Node* buildBST(int arr[],int n){
    Node* root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}


bool searchBST(Node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(root->data < key){
        return searchBST(root->right,key);
    }
    if(root->data > key){
        return searchBST(root->left,key);
    }
  
}

int main(){
    int arr[9]={8,5,3,1,4,6,10,11,14};
    Node* root=buildBST(arr,9);
    int key=15;
    cout<<searchBST(root,key);
    return 0;
}