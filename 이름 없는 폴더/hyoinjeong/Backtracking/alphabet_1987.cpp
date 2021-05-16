#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int r, c, answer;
char a[20][20];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool visit[20][20],arr[26];


void dfs(int x, int y, int cnt){
    answer = max(answer, cnt);
    arr[a[x][y]-'A']=true;
    visit[x][y]=true;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0||ny<0||nx>=r||ny>=c||visit[nx][ny]) continue;
        if(!arr[a[nx][ny]-'A']){
            dfs(nx,ny,cnt+1);
        }
    }
    visit[x][y]=false;
    arr[a[x][y]-'A']=false;
}

int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        getchar();
        for(int j=0;j<c;j++){
            //scanf(" %c",&a[i][j]);
            a[i][j] = getchar();
        }
    }
    dfs(0,0,1);
    cout<<answer<<endl;;
    return 0;
}