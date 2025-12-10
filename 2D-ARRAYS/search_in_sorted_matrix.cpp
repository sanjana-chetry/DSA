#include<iostream>
#include<climits>
using namespace std;
int sortedMatrix(int mat[][4],int n,int m,int key){

// BRUTE FORCE APPROACH

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(key==mat[i][j]){
    //             cout<<"("<<i<<","<<j<<")";
    //         }
    //     }
    // }

// ROW-WISE/COL-WISE BINARY SEARCH

    // int mid;
    // for(int i=0;i<n;i++){
    //     int start=0,end=n-1;
    // while(start<=end){
    //     mid=(start+end)/2;
    //     if(mat[i][mid]==key){
    //         cout<<"element found at:"<<"("<<i<<","<<mid<<")";
    //         return 1;
    //     }
    //     else if(mat[i][mid]>key){
    //         end=mid-1;
    //     }
    //     else{
    //         start=mid+1;
    //     }
    // }

    //  }

    // STAIRECASE APPROACH

    int i=0 , j=m-1;
    while(i<n && j>=0){
        if(mat[i][j]==key){
            cout<<"the key is found at:"<<"("<<i<<","<<j<<")";
            return 1;
        }
        else if(mat[i][j]<key){
            i++; //downwars
        }
        else{
            j--; //left
        }
    }
     cout<<"could not find the element";
    return -1;
}
int main(){
    int arr[4][4]={
                   {10,20,30,40},
                   {15,25,35,45},
                   {27,29,37,48},
                   {32,33,39,50}
    };
    int key;
    cout<<"enter the number you want to search for:";
    cin>>key;
    sortedMatrix(arr,4,4,key);
    return 0;
}