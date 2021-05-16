#include <cstdio>
//dp[1]=1
//dp[2]=2
//dp[3]=4
//dp[4]=7;
int cnt;
void sum(int n){
    if(n==0) 
    {
        cnt++;
        return;
    }
    else if(n<0) return;
    sum(n-3);
    sum(n-2);
    sum(n-1);    
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        cnt=0;
        scanf("%d",&n);
        sum(n);
        printf("%d\n",cnt);
    }
}