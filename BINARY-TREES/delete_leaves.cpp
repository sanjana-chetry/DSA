// Given a binary tree root and an integer target, delete all the leaf nodes with value target.
#include<iostream>
#include<vector>
#include<queue>
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


void leverOrder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        Node* curr=Q.front();
        Q.pop();
        if(curr==NULL){
            cout<<endl;
            if(Q.empty()){
                break;
            }
            Q.push(NULL);//to track nextLine
        }
        else{
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            Q.push(curr->left);
        }
        if(curr->right!=NULL){
            Q.push(curr->right);
        }
    }
    }
}

Node* deleteLeaves(Node* root, int target){
    if(root==NULL){
        return NULL;
    }
    root->left=deleteLeaves(root->left,target);
    root->right=deleteLeaves(root->right,target);
    if(root->left==NULL && root->right==NULL){
        if(root->data==target){
            return NULL;
        }
    }
    return root;
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,2,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTrees(nodes);
    int target=2;
    deleteLeaves(root,target);
    leverOrder(root);
    return 0;
}