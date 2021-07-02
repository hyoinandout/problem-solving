#include <cstdio>
#include <vector>
#include <cstring>
std::vector<std::vector<int>> adj(1001);
bool visited[1001];
int cnt,n;
void dfs(int x){
    visited[x]=true;
    for(int next:adj[x]){
        if(!visited[next]){
            dfs(next);
        }
    }
}
int dfsAll(){
    int components=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            components++;
        }
    }
    return components;
}

int main(){
    int m,u,v;
    scanf("%d %d",&n,&m);
    memset(visited,false,sizeof(visited));
    while(m--){
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    printf("%d",dfsAll());
}