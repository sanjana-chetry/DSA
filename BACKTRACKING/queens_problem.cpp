// Place n queens on a NxN on a chessboard such that no two queens can attack each other 
#include<iostream>
#include<vector>
using namespace std;
void printBoard(vector<vector<char>>board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<" ----------------------------"<<endl;
}
bool isSafe(vector<vector<char>>board,int row,int col){
    // HORIZONTAL
    for(int j=0;j<board.size();j++){
    if(board[row][j]=='Q'){
        return false;
    }
    }
    // VERTICAL
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    // DIAGONAL LEFT
    for(int i=row,j=col;i>=0 && j>=0 ; i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    // DIAGONAL RIGHT
    for(int i=row,j=col;i>=0 && j<=board.size();i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
int nQueens(vector<vector<char>>board,int row){
    if(row==board.size()){
        printBoard(board);
        return 1;
    }
    int count=0;
    for(int j=0;j<board.size();j++){
        if(isSafe(board,row,j)){
       board[row][j]='Q';
       count+=nQueens(board,row+1);
       board[row][j]='.';
       }
    }
    return count ;//no. of possible solutions at each levels~
}

int main(){
    vector<vector<char>>board;
    int n=4;
    for(int i=0;i<n;i++){
        vector<char>newRow;
        for(int j=0;j<n;j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    int count=nQueens(board,0);
    cout<<count<<endl;
    return 0;
}