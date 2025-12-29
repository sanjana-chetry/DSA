#include<iostream>
#include<queue>
#include<string>
using namespace std;

// class Student{
// public:
//     string name;
//     int marks;
//     Student(string name, int marks){
//         this->name=name;
//         this->marks= marks;
//     }
//     bool operator < (const Student &obj)const{
//         return this->marks < obj.marks;
//     }
// };

struct ComparePair{
    bool operator () (pair<string,int>&p1,pair<string,int>&p2){
        return p1.second < p2.second;
    }
};
int main(){
    // priority_queue<Student>pq;
    // pq.push(Student("sanjana",95));
    // pq.push(Student("koushik",90));
    // pq.push(Student("shraddha",85));

    priority_queue<pair<string,int>,vector<pair<string,int>>,ComparePair>pq;
    pq.push(make_pair("sanjana",90));
    pq.push(make_pair("koushik",95));
    pq.push(make_pair("shraddhda",100));
    
    while(!pq.empty()){
        cout<<"top : "<<pq.top().first<<","<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}