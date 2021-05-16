#include <cstdio>
#include <algorithm>
int n;
int main(){
    scanf("%d",&n);
    int arr[n+1];
    int dp[n+1];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i+1]);
    }
    dp[0]=0;
    dp[1]=arr[1];
    dp[2]=arr[1]+arr[2];
    for(int i=3;i<=n;i++){
        dp[i]=std::max(dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i]);
    }
    printf("%d",dp[n]);
}