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

bool validateHelper(Node* root,Node* min, Node* max){
    if(root==NULL){
        return true;
    }
    if(min !=NULL && root->data <= min->data){
        return false;
    }
    if(max != NULL && root->data >= max->data){
        return false;
    }
    return validateHelper(root->left,min,root) 
        && validateHelper(root->right,root,max);
}

bool validateBST(Node* root){
    return validateHelper(root,NULL,NULL);
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(3);
    root->right->right = new Node(6);

    cout << validateBST(root);
    return 0;
}

