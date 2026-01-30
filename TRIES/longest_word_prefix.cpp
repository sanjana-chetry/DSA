//Longest word such that all of its prefixes exist in array
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
class Node{
public:
    unordered_map<char,Node*>children;
    bool endOfWord;
    Node(){
        endOfWord=false;
    }
};
class Trie {
    Node* root;
public:
    Trie(){
        root=new Node();
    }

    void insert(string key){//O(L)
        Node* temp = root;

        for(int i=0; i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node();
            }
            temp=temp->children[key[i]];
        }
        temp->endOfWord=true;
    }

    bool search(string key){ //O(L)
        Node* temp = root;

        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])){
                temp = temp->children[key[i]];
            }else{
                return false;
            }
        }
        return temp->endOfWord;
    }
    void longestHelper(Node* root,string &ans, string temp){
        for(pair<char,Node*>child : root->children){
            if(child.second->endOfWord){
                temp+= child.first;
            if((temp.size()==ans.size() && temp < ans) || (temp.size()>ans.size())){
                ans= temp;
            }
            longestHelper(child.second,ans, temp);
            temp = temp.substr(0,temp.size()-1);
            }
        }
    }
    string longestStrWithEOW(){
        string ans="";
        longestHelper(root,ans,"");
        return ans;
    }
};

string longestString(vector<string>dict){
    Trie trie;
    for(int i=0;i<dict.size();i++){
        trie.insert(dict[i]);
    }
    return trie.longestStrWithEOW();
}
int main(){
    vector<string>dict={"a","banana","app","appl","ap","apple","apply"};
    cout<<longestString(dict);
    return 0;
}