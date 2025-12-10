// Given an N×N chessboard, place N knights such that no two knights attack each other.
// Print all valid configurations and return the total number of possible arrangements
#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<char>> board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-------------------"<<endl;
}

bool isSafe(vector<vector<char>> board,int row,int col){
    if(row-2>=0 && col-1>=0 && board[row-2][col-1]=='K') return false;
    if(row-2>=0 && col+1<board.size() && board[row-2][col+1]=='K') return false;
    if(row-1>=0 && col-2>=0 && board[row-1][col-2]=='K') return false;
    if(row-1>=0 && col+2<board.size() && board[row-1][col+2]=='K') return false;
    return true;
}

int nKnights(vector<vector<char>> board,int row){
    if(row==board.size()){
        printBoard(board);
        return 1;
    }
    int count=0;
    for(int j=0;j<board.size();j++){
        if(isSafe(board,row,j)){
            board[row][j]='K';
            count+=nKnights(board,row+1);
            board[row][j]='.';
        }
    }
    return count;
}

int main(){
    int n=4;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    int count=nKnights(board,0);
    cout<<count<<endl;
    return 0;
}
