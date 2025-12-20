// A binary tree is uni-valued if every node in the tree has the same value.
// Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int data;
    Node* right;
    Node* left;
    Node(int data){
        this->data=data;
        right=left=NULL;
    }
};
static int idx=-1;
Node* buildTrees(vector<int>nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    Node* currNode=new Node(nodes[idx]);
    currNode->left=buildTrees(nodes);
    currNode->right=buildTrees(nodes);
    return currNode;
}

bool isUniversal(Node* root){
    if(root==NULL){
        return true;
    }
    if(!isUniversal(root->left) || !isUniversal(root->right)){
        return false;
    }

    if(root->left != NULL){
        if(root->data != root->left->data){
            return false;
        }
    }
    if(root->right != NULL){
        if(root->data != root->right->data){
            return false;
        }
    }
    return true;
}
int main(){
    vector<int>nodes={1,1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1};
    Node* root=buildTrees(nodes);
    cout<<isUniversal(root)<<endl;
    return 0;
}