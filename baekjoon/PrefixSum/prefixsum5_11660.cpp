#include <cstdio>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int val;
    int sum[n+1][n+1]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&val);
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+val;
        }
    }

    for(int i=0;i<m;i++){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("%d\n",sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]);
    }
    return 0;
}