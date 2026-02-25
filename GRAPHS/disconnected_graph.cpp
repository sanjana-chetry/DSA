#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;
class Graph{
    int V;
    list<int>*l;
public:
    Graph(int V){
        this->V=V;
        l= new list<int>[V];
    }
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void dfsHelper(int u, vector<bool>&vis){
        vis[u]=true;
        cout<<u<<" ";
        list<int>neighbors=l[u];
        for(int v: neighbors){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }
    void dfs(){
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsHelper(i,vis);
                cout<<endl;
            }
        }
        cout<<endl;   
    }
};
int main(){
    Graph g(10);
    g.addEdge(0,2);
    g.addEdge(0,5);
    g.addEdge(1,6);
    g.addEdge(6,4);
    g.addEdge(4,9);
    g.addEdge(4,3);
    g.addEdge(3,8);    
    g.addEdge(3,7); 
    
    g.dfs();
    return 0;
}