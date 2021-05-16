#include <cstdio>

int main(){
    int n,m;
    scanf("%d",&n);
    int arr[n],ps[n+1]={0};
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
        ps[i+1]=ps[i]+arr[i];
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int s,e;
        scanf("%d %d",&s,&e);
        printf("%d\n",ps[e]-ps[s-1]);
    }
    return 0;
}