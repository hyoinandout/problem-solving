#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    int k,x;
    scanf("%d %d",&n,&m);
    int arr[n+1][n+1];
    for(int i=0;i<=n;i++){
        fill_n(arr[i],n+1,1000000000);
    }
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        arr[a][b]=1;
        arr[b][a]=1;
    }
    for(int i=1;i<=n;i++){
        arr[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
            }
        }
    }
    scanf("%d %d",&x,&k);
    if((arr[1][k]+arr[k][x])>=1000000000) printf("-1");
    else printf("%d",arr[1][k]+arr[k][x]);
}