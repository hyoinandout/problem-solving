//안풀리면 그냥 조금 무식하게 해도 괜찮아
#include <cstdio>
#include <cstring>
#include <algorithm>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n+1][n+1];
    int dp[n+1][n+1];
    memset(arr,0,sizeof(arr));
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1) arr[i][j]+=arr[i-1][j];
            else if(i==j) arr[i][j]+=arr[i-1][j-1];
            else arr[i][j]+=std::max(arr[i-1][j-1],arr[i-1][j]);
        }
    }
    int ret=0;
    for(int i=1;i<=n;i++){
        ret=std::max(ret,arr[n][i]);
    }
    printf("%d",ret);
    return 0;
}
