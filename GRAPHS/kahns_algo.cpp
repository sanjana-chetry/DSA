#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    bool isUndir;
public:
    Graph(int V,bool isUndir){
        this->V=V;
        l=new list<int>[V];
        this->isUndir=isUndir;
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        if(isUndir){
            l[v].push_back(u);
        }
    }
    void calcIndegree(vector<int>&indeg){
        for(int i=0;i<V;i++){
            list<int>neighbors=l[i];
            for(int v: neighbors){
                indeg[v]++;
            }
        }
    }

    void topSort(){
        vector<int>indeg(V,0);
        calcIndegree(indeg);
        queue<int>q;
        
        //0 indeg nodes --->starting point
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            cout<<curr<<" ";
            list<int>neighbors=l[curr];

            for(int v:neighbors){ //no pending dependencies
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }
};
int main(){
    Graph g(6,false);
    g.addEdge(5,0);
    g.addEdge(5,2);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(2,3);
    g.addEdge(3,1);

    g.topSort();
    return 0;
}