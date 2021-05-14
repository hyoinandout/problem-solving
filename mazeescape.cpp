#include <cstdio>
#include <queue>
using namespace std;
int n,m;
int arr[200][200];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int cnt=0;

void bfs(){
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        
        
        
        int size = q.size();
        for(int i=0;i<size;i++){
            int y =q.front().first;
            int x =q.front().second;
            if(y==n-1&&x==m-1) return;
            arr[y][x]=0;
            q.pop();
            for(int j=0;j<4;j++){
                int ny = y+dy[j];
                int nx = x+dx[j];
                if(nx<0||ny<0||nx>=m||ny>=n||arr[ny][nx]==0) continue;
                q.push({ny,nx});
            }
        }
        cnt++;
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    bfs();
    printf("%d",++cnt);
    return 0;
}