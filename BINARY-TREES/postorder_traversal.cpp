#include<iostream>
#include<algorithm>
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
void postOrder(Node* root){
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root= buildTrees(nodes);
    postOrder(root);
    return 0;
}