#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int dp[1000005][2];
int sns(int root,bool isPicked){
        if(dp[root][isPicked]!=0) return dp[root][isPicked];
        int cnt;
        if(isPicked) cnt=1;
        else cnt=0;
        visited[root]=true;
        for(int next:adj[root]){
            if(!visited[next]){
                if(!isPicked){
                    cnt+=sns(next,true);
                }
                else{
                    cnt+=min(sns(next,false),sns(next,true));
                }
                dp[root][isPicked]=cnt;
            }
        }
        visited[root]=false;
        return cnt;
    };

int main(){
    int n,u,v;
    scanf("%d",&n);
    adj.resize(n+1);
    visited.resize(n+1,false);
    for(int i=1;i<n;i++){
        scanf(" %d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    printf("%d\n",min(sns(1,false),sns(1,true)));
    return 0;
}