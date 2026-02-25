#include<iostream>
#include<vector>
#include<list>
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
        if(isUndir)
            l[v].push_back(u);
    }
    //FOR UNDIRECTED GRAPH
    bool undirCycleHelper(int src, int par, vector<bool>&vis){
        vis[src]=true;
        list<int>neighbors=l[src];
        for(int v : neighbors){
            if(!vis[v]){
                if(undirCycleHelper(v,src,vis)){
                    return true;
                }
            }
            else{
                if(v!=par){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycleUndir(){
        vector<bool>vis(V,false);
        return undirCycleHelper(0,-1,vis);
    }
    //FOR DIRECTED GRAPH

    bool dirCycleHelper(int src,vector<bool>&vis,vector<bool>&recPath){
        vis[src]=true;
        recPath[src]=true;
        list<int>neighbors=l[src];
        for(int v:neighbors){
            if(!vis[v]){
                if(dirCycleHelper(v,vis,recPath)){
                    return true;
                }
            }
            else{
                if(recPath[v]){
                    return true;
                }
                }
        }
        recPath[src]=false;
        return false;
    }
    bool isCycleDir(){
        vector<bool>vis(V,false);
        vector<bool>recPath(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dirCycleHelper(i,vis,recPath)){
                    return true;
                }
            }
        }
        return false;
    }

};
int main(){
    Graph g(5,false);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    cout<<g.isCycleDir()<<endl;
    return 0;
}