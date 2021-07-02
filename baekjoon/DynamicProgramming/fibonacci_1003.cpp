#include <cstdio>

int dp[41][2];
int fibonacci(int n,bool k) {
    if(dp[n][k]!=0) return dp[n][k];
    if(k){
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            return dp[n][1]=fibonacci(n-1,k) + fibonacci(n-2,k);
        }
    }else{
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return 0;
        } else {
            return dp[n][0]=fibonacci(n-1,0) + fibonacci(n-2,0);
        }
    }
}

int main(){
    int n,num;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        if(num==0){
            printf("1 0\n");
        }
        else if(num==1){
            printf("0 1\n");
        }
        else{
            printf("%d %d\n",fibonacci(num,0),fibonacci(num,1));
        }
    }
    return 0;
}