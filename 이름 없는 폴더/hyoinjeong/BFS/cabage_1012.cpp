//array x y 기준 정하기 : 그냥 뭐 뒤집어도 상관 없으니 m n x y 순으로 하자 귀찮다
#include <cstdio>
#include <cstring>

using namespace std;

int n,m,k;
bool visited[50][50];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void fs(int x, int y){
    visited[x][y]=false;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0||ny<0||nx>=m||ny>=n) continue;
        if(visited[nx][ny]) fs(nx,ny);
    }
}

int main(){
    int t,x,y;
    scanf("%d",&t);
    while(t--){
        int cnt=0;
        scanf("%d %d %d",&m,&n,&k);
        memset(visited,false,sizeof(visited));
        for(int i=0;i<k;i++){
            scanf("%d %d",&x,&y);
            visited[x][y]=true;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]){
                    fs(i,j);
                    // printf("%d %d\n",i,j);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    
}