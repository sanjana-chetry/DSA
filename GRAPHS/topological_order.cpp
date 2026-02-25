#include<iostream>
#include<vector>
#include<list>
#include<stack>
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

    void topologicalHelper(int src, vector<bool>&vis,stack<int>&s){

        vis[src]=true;
        list<int>neighbors=l[src];
        for(int v : neighbors){
            if(!vis[v]){
                topologicalHelper(v,vis,s);
            }
        }
        s.push(src);
    }

    void topologicalSort(){
        vector<bool>vis(V,false);
        stack<int>s;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                topologicalHelper(i,vis,s);
            }  
        }
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
};
int main(){
    Graph g(6,false);
    g.addEdge(5,0);
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,0);
    g.addEdge(4,1);

    g.topologicalSort();
    return 0;
}