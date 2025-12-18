#include<iostream>
#include<string>
#include<queue>
using namespace std;
void firstRepeating(string str){
    queue<char>Q;
    int freq[26]={0};
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        freq[ch-'a']++;
        Q.push(ch);
        while(!Q.empty() && freq[Q.front()-'a']>1){
            Q.pop();
        }
        if(Q.empty()){
            cout<<"-1\n";
        }
        else{
            cout<<Q.front()<<"\n";
        }
    }
};
int main(){
    string str="aabccxb";
    firstRepeating(str);
    return 0;
}