//Based on car locations (Cx, Cy), find the nearest K cars;
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Car{
public:
    int idx;
    int distSQ;
    Car(int idx, int distSQ){
        this->idx=idx;
        this->distSQ=distSQ;
    }
    bool operator < (const Car &obj)const{
        return this->distSQ > obj.distSQ;
    }
};

void nearbyCar(vector<pair<int,int>>pos,int K){
    vector<Car>cars;

    for(int i=0; i<pos.size(); i++){ //O(n)
        int distsq= (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second);
        cars.push_back(Car(i,distsq));
    }

    priority_queue<Car>pq(cars.begin(),cars.end());//O(n)

    for(int i=0 ;i<K ;i++ ){//O(K * logn + n)
        cout<<"car:"<<pq.top().idx<<endl;
        pq.pop();//O(logn)
    }
}

int main(){
    vector<pair<int,int>>pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));
    int K=2;
    nearbyCar(pos,K);
    return 0;
}