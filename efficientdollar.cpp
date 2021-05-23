#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    int dp[m+1];
    fill(dp,dp+m+1,100001);
    dp[0]=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i>arr[j]){
                dp[i] = min(dp[i],dp[i-arr[j]]+1);
            }
            else if(i==arr[j]){
                dp[i]=1;
            }
        }
    }
    if(dp[m]==100001)
    {
        printf("%d",-1);
    }
    else
    printf("%d",dp[m]);
    return 0;
}