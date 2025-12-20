#include<iostream>
#include<vector>
#include<algorithm>
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
//(diameter,height)
pair<int,int>diameter(Node* root){
    if(root==NULL){
        return make_pair(0,0);
    }
    pair<int,int> leftInfo= diameter(root->left);
    pair<int,int>rightInfo=diameter(root->right);

    int currDiam=leftInfo.second + rightInfo.second+1;
    int finalDiam= max(currDiam,max(leftInfo.first,rightInfo.first));
    int finalHeight=max(leftInfo.second,rightInfo.second)+1;
    return make_pair(finalDiam,finalHeight);
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTrees(nodes);
    cout<<"the diameter of the tree is : "<<diameter(root).first<<endl;
    return 0;
}