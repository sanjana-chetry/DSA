#include<iostream>
using namespace std;
void spiralMatrix(int mat[][4],int n,int m){
    int srow=0,scol=0;
    int erow=n-1,ecol=m-1;
    while(srow<=erow && scol<=ecol){
        //TOP
        for(int j=scol;j<=ecol;j++){
            cout<<mat[srow][j]<<" ";
        } 
        // RIGHT
        for(int i=srow+1; i<=erow;i++){
            cout<<mat[i][ecol]<<" ";
        }
        // BOTTOM
        for(int j=ecol-1;j>=scol;j--){
            if(srow==erow){
                break;
            }
            cout<<mat[erow][j]<<" ";
        }
        // LEFT
        for(int i=erow-1;i>=srow+1;i--){
            if(scol==ecol){
                break;
            }
            cout<<mat[i][scol]<<" ";
        }
        srow++;scol++;
    erow--;ecol--;
    }
    
}
int main(){
    int arr[3][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    spiralMatrix(arr,3,4);
    return 0;
}