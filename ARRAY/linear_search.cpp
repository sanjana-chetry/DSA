#include<iostream>
using namespace std;
int linearSearch(int *arr,int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,2,4,5,7,8,9};
    int n= sizeof(arr)/sizeof(int);
    cout<<linearSearch(arr,n,8);
    return 0;
}