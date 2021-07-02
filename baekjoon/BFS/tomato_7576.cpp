//0아닌 모든 정수는 if문에서 참
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int main(){
    int m,n;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    scanf("%d %d",&n,&m);
    int arr[m][n];
    bool visited[m][n];
    queue<pair<int,int>> Q;
    memset(visited,0,sizeof(visited));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==1) Q.push({i,j});
        }
    }   
    int cnt=0;
    while(!Q.empty()){
        int size = Q.size();
        for(int i=0;i<size;i++){
            int x=Q.front().first;
            int y=Q.front().second;
            visited[x][y]=true;
            Q.pop();
            for(int j=0;j<4;j++){
                int nx=x+dx[j];
                int ny=y+dy[j];
                if(nx<0||ny<0||nx>=m||ny>=n||arr[nx][ny]==-1||arr[nx][ny]==1) continue;
                if(!visited[nx][ny]){
                    visited[nx][ny]=true;
                    arr[nx][ny]=1;
                    Q.push({nx,ny});
                }
            }
        }
        cnt++;   
    }
    int ret=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ret*=arr[i][j];
           // printf("%d ",arr[i][j]);
        }
        //printf("\n");
    }
    int ar[m][n];
    memset(ar,-1,sizeof(ar));
    bool pandog =true;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(ar[i][j]!=arr[i][j]) pandog=false;
        }
    }
    if(pandog)
    {
        printf("%d",0);
    }
    else{
        cnt = (ret!=0? --cnt:-1);
        printf("%d",cnt);
    }
    return 0;
}