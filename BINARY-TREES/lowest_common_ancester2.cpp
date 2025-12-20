// APPROACH 2 OF SOLVING THE LCA QUESTIONS THIS APPROACH SOLVES 
// BY THE TIME_COMPLEXITY OF : O(N) AND SPACE_COMPLEXITY OF: O(1)
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
Node* LCA2(Node* root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftLCA= LCA2(root->left,n1,n2);
    Node* rightLCA= LCA2(root->right,n1,n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }
    return leftLCA==NULL? rightLCA : leftLCA;
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTrees(nodes);
    int n1=5, n2=3;
    cout<<"lca2: "<<LCA2(root,n1,n2)->data<<endl;
    return 0;
}