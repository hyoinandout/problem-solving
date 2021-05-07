#include <cstdio>

int main(){
    int r; char c;
    scanf("%c%d",&c,&r);
    int dx[8] = {2,1,-1,-2,-2,-1,1,2};
    int dy[8] = {1,2,2,1,-1,-2,-2,-1};
    int cnt=0;
    for(int i=0;i<8;i++){
        int nx = (int)(c-'a') + dx[i];
        int ny = r-1 + dy[i];
        if(nx<0||ny<0||nx>7||ny>7) continue;
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}