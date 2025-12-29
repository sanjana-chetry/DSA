#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Heap{
    vector<int>vec; //max heap
public: 


    void push(int val){ //O(nlogn)
        //step 1
        vec.push_back(val);

        //step 2: fix heap
        int x= vec.size()-1;//childIdx
        int parI= (x-1)/2;

        while(parI >= 0 && vec[x] > vec[parI]){
            swap(vec[parI], vec[x]);
            x = parI;
            parI = (x-1)/2; 
        }
    }

    void heapify(int i){//parIdx
        if(i > vec.size()){
            return;
        }

        int l= 2*i+1;
        int r= 2*i+2;

        int maxIdx=i;

        if(l<vec.size() && vec[l] >vec[maxIdx]){
            maxIdx = l;
        }

        if(r < vec.size() && vec[r] > vec[maxIdx]){
            maxIdx = r;
        }

        swap(vec[maxIdx],vec[i]);
        if(maxIdx != i){ //swapping with child
            heapify(maxIdx);
        }
    }

    void pop(){
        //step1 
        swap(vec[0], vec[vec.size()-1]);

        //step 2
        vec.pop_back();

        //step 3
        heapify(0);
    }

    int top(){
        return vec[0]; //highest priority element
    }

    bool empty(){ //O(nlogn)
        return vec.size() == 0;
    }
};
int main(){
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);

    while(!heap.empty()){
    cout<<"top : "<<heap.top()<<endl;
    heap.pop();
    }
    return 0;
}