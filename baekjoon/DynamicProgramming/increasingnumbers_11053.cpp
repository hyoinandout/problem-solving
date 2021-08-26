#include <bits/stdc++.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int dp[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        dp[i] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = dp[i] > dp[j]+1 ? dp[i] : dp[j]+1;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     printf("%d",dp[i]);
    // }
    // printf("\n");
    printf("%d",*(std::max_element(dp,dp+n)));
    return 0;
}