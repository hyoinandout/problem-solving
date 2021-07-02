//트리의 지름 알고리즘
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
class Graph{
    int N;
    vector<vector<pair<int,int>>> adj;
    vector<bool> visited;
    int ret=0;
    int distance=0;
    int i=0;
    public:
    Graph():N(0){}
    Graph(int n):N(n){
        adj.resize(N);
        visited.resize(N,false);
    }
    void addEdge(int x, int y, int r){
        adj[x].push_back({y,r});
    }
    void dfs(int x){
        visited[x]=true;
        for(pair<int,int> next:adj[x]){
            if(!visited[next.first]){
                visited[next.first]=true;
                ret+=next.second;
                if(distance<ret) i=next.first;
                distance=max(distance,ret);
                dfs(next.first);
                ret-=next.second;
            }
        }
    }
    void reset(){
        fill(visited.begin(),visited.end(),false);
        ret=0;
        distance=0;
    }
    int getDistance(){
        return distance;
    }
     int geti(){
        return i;
    }
};

int main(){
    int v,x,y,r;
    scanf("%d",&v);
    Graph G(v+1);
    for(int i=1;i<v;i++){
        scanf("%d %d %d",&x,&y,&r);
        G.addEdge(x,y,r);
        G.addEdge(y,x,r);
    }
    G.dfs(1);
    G.reset();
    G.dfs(G.geti());
    printf("%d",G.getDistance());
    return 0;
}