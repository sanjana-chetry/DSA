#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<string>
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

    void pathHelper(int src,int dest, vector<bool>vis,string path){
        if(src==dest){
            cout<<path<<dest<<endl;
            return;
        }
        vis[src]=true;
        path+=to_string(src);
        list<int>neighbors=l[src];

        for(int v: neighbors){
            if(!vis[v]){
                pathHelper(v,dest,vis,path);
            }
        }
        path=path.substr(0,path.size()-1);
        vis[src]=false;
    }

    void allPath(int src,int dest){
        vector<bool>vis(V,false);
        string path="";
        pathHelper(src,dest,vis,path);
    }

};
int main(){
    Graph g(6,false);
    g.addEdge(5,0);
    g.addEdge(5,2);
    g.addEdge(0,3);
    g.addEdge(2,3);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(3,1);

    g.allPath(5,1);
    return 0;
}