#include <stdio.h>
#include <stdlib.h>

using namespace std;

int N, in, total=0;
int arr[20][20];
int x[20] = {0};
int mini = 2000;

void dfs(int idx, int cnt, int res){
    if( cnt==N/2 ){
        if( mini>abs(res) ) mini = abs(res);
        return;
    }
    if( idx<N-1 ){
        dfs(idx+1, cnt+1, res-x[idx]);
        dfs(idx+1, cnt, res);
    }
}

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &in);
            total += in;
            x[i] += in;
            x[j] += in;
        }
    }
    printf("%d",total);
    for(int i=0; i<N; i++){
        printf("%d ",x[i]);
    }

    dfs(0, 0, total);
    printf("%d\n", mini);
    return 0;
}