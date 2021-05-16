#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int impossible=1000000000;
int n;
int arr[16][16];
int dp[16][1<<16];

int tsp(int current, int visited){
    int& ret = dp[current][visited];
    if(ret != -1) return ret;
    if(visited==(1<<n)-1){
        if(arr[current][0]!=0) return arr[current][0];
        return impossible;
    }

    ret = impossible;
    for(int i=0;i<n;i++){
        if(visited & (1<<i) || arr[current][i] == 0){
            continue;
        }
        ret = min(ret, tsp(i,visited | (1<<i)) + arr[current][i]);
    }
    return ret;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %d",&arr[i][j]);
        }
    }
    memset(dp,-1,sizeof(dp));
    printf("%d",tsp(0,1));
    return 0;
}