//%1d
#include <cstdio>
// #include <algorithm>
// #include <cstring>
// char arr[1000][1000];
// bool visited[1000][1000];
int arr[1000][1000];
int n,m,cnt;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void dfs(int y, int x){
    // visited[y][x]=true;
    if(y<0||x<0||y>=n||x>=m) return;
    arr[y][x]=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!arr[ny][nx]){
            dfs(ny,nx);
        }
    }    
}


int main(){
    
    scanf("%d %d",&n,&m);
    // std::fill(&arr[0][0],&arr[0][0]+1000*1000,'1');
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    // memset(visited,false,sizeof(visited));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!arr[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}