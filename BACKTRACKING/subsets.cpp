// FIND AND PRINT ALL THE SUBSETS OF A GIVEN ARRAY 
#include<iostream>
#include<string>
using namespace std;
void subsets(string str,string subset){
    char ch=str[0];
    if(str.size()==0){
        cout<<subset<<" ";
        return;
    }
    // YESS
    subsets(str.substr(1,str.size()-1),subset+ch);
    // NOO
    subsets(str.substr(1,str.size()-1),subset);

}
int main(){
    string str="abc";
    string subset="";
    subsets(str,subset);
    return 0;
}