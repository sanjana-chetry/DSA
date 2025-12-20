#include<iostream>
using namespace std;
int main(){
for(int i=1;i<=4;i++)
{
    for(int sp=1;sp<=4-i;sp++){
        cout<<" ";
    }
    for(int j=1;j<=(2*i-1);j++)
    {
        cout<<"*";
    }
    cout<<" "<<endl;

}
for(int i=4;i>=1;i--)
{
    for(int j=1;j<=4-i;j++){
        cout<<" ";
    }
    for(int j=1;j<=(2*i-1);j++)
    {
        cout<<"*";
    }
    cout<<endl;

}
}