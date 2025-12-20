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

bool rootToNode(Node* root,int n, vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==n){
        return true;
    }
    int isLeft=rootToNode(root->left, n, path);
    int isRight=rootToNode(root->right, n, path);
    if(isLeft || isRight){
        return true;
    }
    path.pop_back();
    return false;
}

int LCA(Node* root, int n1,int n2){ // TC: 0(N) AND SC: O(N)
    vector<int>path1;
    vector<int>path2;

    rootToNode(root,n1,path1);
    rootToNode(root,n2,path2);
    int lca=-1;
    for(int i=0,j=0;i<path1.size() && j<path2.size();i++,j++){
        if(path1[i] != path2[j]){
            return lca;
        }
        lca=path1[i];
        
    }
    return lca;
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTrees(nodes);
    int n1=5, n2=3;
    cout<<"LCA: "<<LCA(root,n1,n2)<<endl;
    return 0;
}