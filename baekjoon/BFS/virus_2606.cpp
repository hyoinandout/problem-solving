//array x y 기준 정하기 : 그냥 뭐 뒤집어도 상관 없으니 m n x y 순으로 하자 귀찮다
#include <cstdio>
#include <vector>

using namespace std;

int cnt=0;
bool visited[101];
vector<vector<int>> adj;

void fs(int x){
    visited[x]=true;
    for(int next:adj[x]){
        if(!visited[next]){
            fs(next);
            cnt++;
        }
    }
    
}

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int t,n,x,y;
    scanf("%d",&t);
    scanf("%d",&n);
    adj.resize(t+1);
    while(n--){
        scanf("%d %d",&x,&y);
        addEdge(x,y);
    }
    fs(1);
    printf("%d\n",cnt);
}   
