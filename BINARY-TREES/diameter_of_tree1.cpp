// Approach 1 : O(n^2) 
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
        right=left=NULL;
    }
};
static int idx=-1;
Node* buildTrees(vector<int>nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    Node* currNode= new Node(nodes[idx]);
    currNode->left=buildTrees(nodes);
    currNode->right=buildTrees(nodes);
    return currNode;
}
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHt= height(root->left);
    int rightHt=height(root->right);
    int currHeight= max(leftHt,rightHt)+1;
    return currHeight;
}
int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int currDiam= height(root->left)+ height(root->right) + 1;
    int leftDiam= diameter(root->left);
    int rightDiam=diameter(root->right);
    return max(currDiam,max(leftDiam,rightDiam));
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTrees(nodes);
    cout<<"the diameter of a tree: "<< diameter(root);
    return 0;
}