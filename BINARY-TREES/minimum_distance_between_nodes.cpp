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
Node* LCA(Node* root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftLCA= LCA(root->left,n1,n2);
    Node* rightLCA= LCA(root->right,n1,n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }
    return leftLCA==NULL? rightLCA : leftLCA;
}

int Dist(Node* root, int n){
    if(root==NULL){
        return -1;
    }
    if(root->data == n){
        return 0;
    }
    int leftDist=Dist(root->left,n);
    if(leftDist != -1){
        return leftDist +1;
    }
    int rightDist=Dist(root->right,n);
    if(rightDist != -1){
        return rightDist + 1;
    }
    return -1;

}

int minDist(Node* root, int n1 , int n2){
    Node* lca= LCA(root,n1,n2);

    int dist1= Dist(lca,n1);
    int dist2= Dist(lca,n2);
    return dist1 + dist2;
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTrees(nodes);
    int n1=2, n2=3;
    cout<<"minimum distance: "<<minDist(root,n1,n2)<<endl;
    return 0;
}