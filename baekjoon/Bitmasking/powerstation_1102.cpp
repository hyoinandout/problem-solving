#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int impossible = 1000000000;
int n,p,cnt;
int arr[16][16];
int dp[1<<16];
char onoff[16];

// int count(int n){
//     int i;
//     for(i=0;n!=0;i++){
//         n&=(n-1);
//     }
//     return i;
// }

int tsp(int opened){
    int& ret=dp[opened];
    if(ret!=-1) return ret;
    if(cnt>=p) return ret=0;
    ret=impossible;
    cnt++;
    for(int i=0;i<n;i++){
        if(opened & (1<<i)){
            for(int j=0;j<n;j++){
                if(!(opened & (1<<j)))
                    ret = min(ret,tsp(opened|(1<<j))+arr[i][j]);
            }
        }
    }
    cnt--;
    return ret;
}

int main(){
    int opened=0;
    char c;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    getchar();
    for(int i=0;i<n;i++){
        c=getchar();
        if(c=='Y'){
            cnt++;
            opened |= 1<<i;
        }
    }
    scanf("%d",&p);
    memset(dp,-1,sizeof(dp));
    int result=tsp(opened);
    if(result==1000000000) result=-1;
    printf("%d\n",result);    
    return 0;
}
