//++i is more better
#include <iostream>
#include <queue>

using namespace std;

int N, K;
int dx[2]={-1,1};
bool visited[100001];

void bfs(int n){
    visited[n]=true;
    queue<int> Q;
    Q.push(n);
    int level = 0;
    while(!Q.empty()){
        int qsize= Q.size();
        if(visited[K]){
            cout<<level<<endl;
            return;
        }
        level++;
        for(int j=0;j<qsize;j++){
            int curr = Q.front();
            Q.pop();
            for(int i=0;i<2;i++){
                int nx = curr+dx[i];
                if(nx<0||nx>100000) continue;
                if(!visited[nx]){
                    visited[nx]=1;
                    Q.push(nx);
                }
            }
            int mx = curr*2;
            if(mx<0||mx>100000) continue;
            if(!visited[mx]){
                visited[mx]=1;
                Q.push(mx);
            }
        }
    }
}

int main(){
    cin>>N>>K;
    bfs(N);
    return 0;
}