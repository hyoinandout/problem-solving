#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1],dp[i-2]+arr[i]); 
    }
    printf("%d",dp[n-1]);
    return 0;
}