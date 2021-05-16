#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n][m];
    int result=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %d",&arr[i][j]);
        }
        sort(arr[i],arr[i]+m);
        result = max(result,arr[i][0]);
    }
    printf("%d",result);
    return 0;
}