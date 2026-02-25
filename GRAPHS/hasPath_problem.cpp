#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;
class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool helperhasPath(int src, int dest, vector<bool>&vis){
        if(src==dest){
            return true;
        }
        vis[src]=true;
        list<int>neighbors=l[src];
        for(int v : neighbors){
            if(!vis[v]){
                if(helperhasPath(v,dest,vis)){
                    return true;
                }
            }
        }
        return false;
    }
    bool hasPath(int src,int dest){
        vector<bool>vis(V,false);
        return helperhasPath(src,dest,vis);
    }

    // bool hasPath(int src,int dest){
    //     queue<int>q;
    //     vector<bool>vis(V,false);
    //     q.push(src);
    //     vis[src]=true;
    //     while(!q.empty()){
    //         int u= q.front();
    //         q.pop();
    //         list<int>neighbors=l[u];
    //         for(int v : neighbors){
    //             if(!vis[v]){
    //                 if(v==dest){
    //                 return true;
    //             }
    //             vis[v]=true;
    //             q.push(v);
    //         }
    //         }
    //     }
    //     return false;

    // }
};
int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(5,6);
    cout<<g.hasPath(0,8);
    return 0;
}