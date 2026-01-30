//Find the shortest unique prefix for each word (no word is prefix of another)
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
class Node{
public:
    unordered_map<char,Node*>children;
    bool endOfWord;
    int freq;
    Node(){
        endOfWord=false;
    }
};
class Trie {
    Node* root;
public:
    Trie(){
        root=new Node();
        root->freq=-1;
    }

    void insert(string key){//O(L)
        Node* temp = root;

        for(int i=0; i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node();
                temp->children[key[i]]->freq=1;
            }else{
                temp->children[key[i]]->freq++;
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
    
string getPrefix(string key){
    Node* temp=root;
    string prefix="";

    for(int i=0;i<key.size();i++){
        prefix+=key[i];
        if(temp->children[key[i]]->freq==1){
            break;
        }
        temp= temp->children[key[i]];
    }
    return prefix;
}
};
 

void prefixProblem(vector<string>words){
    Trie trie;
    for(int i=0;i<words.size();i++){
        trie.insert(words[i]);
    }
    for(int i=0;i<words.size();i++){
        cout<<trie.getPrefix(words[i])<<endl;
    }
}

int main(){
    vector<string>words={"zebra","dog","duck","dove"};
    prefixProblem(words);
    return 0;
}