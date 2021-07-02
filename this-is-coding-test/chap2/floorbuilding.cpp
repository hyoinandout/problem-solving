//틀렸다.
#include <cstdio>

int main(){
    int n;
    scanf("%d",&n);
    int dp[n+1];
    dp[1]=1;
    dp[2]=3;
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1]+2*dp[i-2];
    }
    printf("%d",dp[n]);
    return 0;
}