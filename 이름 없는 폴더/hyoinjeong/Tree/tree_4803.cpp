#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
class Graph{
public:
    int N; // 정점의 개수
    vector<vector<int>> adj; // 인접 리스트
    vector<bool> visited; // 방문 여부를 저장하는 배열
    queue<int> Q;
    
    // 생성자
    Graph(): N(0){}
    Graph(int n): N(n){
        adj.resize(N);
        visited.resize(N,false);
    }
 
    // 간선 추가 함수
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int testTree(int root){
        if(visited[root]) return 0;
        int cnt=0;
        int totalLine=0;
        visited[root] = true;
        Q.push(root);
        while(!Q.empty()){
            int curr = Q.front();
            Q.pop();
            for(int next: adj[curr]){
                totalLine+=1;
                if(!visited[next]){
                    visited[next] = true;
                    Q.push(next);
                    ++cnt;
                }
            }
        }
        if(cnt==(totalLine/2)) return 1;
        else return 0;
    }
};

int main(){
    int n=1,m=1,u,v,t=0;
    while(1){
        int total = 0;
        scanf("%d %d",&n,&m);
        if(n==0&&m==0) break;
        Graph G(n+1);
        for(int i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            G.addEdge(u,v);
        }
        // G.sortList();
        for(int i=1;i<=n;i++){
            total+=G.testTree(i);
        }
        if(total>1){
            cout<<"Case "<<++t<<": A forest of "<<total<<" trees.\n";
        }
        else if(total==1){
            cout<<"Case "<<++t<<": There is one tree.\n";
        }
        else{
            cout<<"Case "<<++t<<": No trees.\n";
        }
    }
    return 0;
}