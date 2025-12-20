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
int KthAncest(Node* root, int node, int k ){
    if(root==NULL){
        return -1;
    }
    if(root->data==node){
        return 0;
    }
    int leftDist=KthAncest(root->left,node,k);
    int rightDist=KthAncest(root->right,node,k);
    if(leftDist == -1 && rightDist == -1){
        return -1;
    }
    int valDist=leftDist==-1? rightDist : leftDist;
    if (valDist + 1 == k){
        cout<<"kth ancestor is :"<<root->data<<endl;
    }
    return valDist + 1; 
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTrees(nodes);
    int node= 5 , k= 2;
    KthAncest(root, node, k);
    return 0;
}