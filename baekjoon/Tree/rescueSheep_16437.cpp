#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int arr[123457]={0};
class Graph{
    int N;
    vector<vector<int>> adj;
    vector<bool> visited;
public:
    Graph():N(0){};
    Graph(int n):N(n){
        adj.resize(n);
        visited.resize(n);
        fill(visited.begin(),visited.end(),false);
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long long dfs(int curr){
        long long sum=arr[curr];
        visited[curr]=true;
        for(int next:adj[curr]){
            if(!visited[next]){
                sum+=dfs(next);
            }
        }
        if(sum<0) sum=0;
        return sum;
    }
};

int main(){
    int n;
    scanf("%d",&n);
    char sw;
    int num, con;   
    Graph G(n+1);
    for(int i=2;i<=n;i++){
        scanf(" %c %d %d",&sw,&num,&con);
        if(sw=='W') arr[i]=-num;
        else if(sw=='S') arr[i]=num;
        G.addEdge(i,con);
    }
    printf("%lld\n",G.dfs(1));
}