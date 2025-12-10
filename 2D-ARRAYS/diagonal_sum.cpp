#include<iostream>
using namespace std;
int diagonalSum(int mat[][3],int n,int m){
   int sum=0;
    for(int i=0;i<n;i++){
        sum+=mat[i][i];
        if(i!=n-i-1){
            sum+=mat[i][n-i-1];
        }
    }
    cout<<sum;
    return sum;
}
int main(){
    // int arr[4][4]={
    //     {1,2,3,4},
    //     {5,6,7,8},
    //     {9,10,11,12},
    //     {13,14,15,16}
    // };
    // diagonalSum(arr,4,4);
    int arr2[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    diagonalSum(arr2,3,3);
    return 0;
}