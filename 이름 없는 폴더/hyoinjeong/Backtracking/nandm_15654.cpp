#include <cstdio>
#include <algorithm>
int n,m;
int arr[8]={0};
int arr2[8]={0};
bool used[8];
void bt(int x, int y){
    arr2[y]=arr[x];
    used[x]=true;
    for(int j=0;j<n;j++){
        if(j==x) continue;
        if(y>m)break;
        if(!used[j])    bt(j,y+1);
    }
    used[x]=false;  
    if(y==m-1){
        for(int i=0;i<m;i++){
            printf("%d ",arr2[i]);
        }
        printf("\n");
        return;
    }
      
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    std::sort(arr,arr+n);
    for(int i=0;i<n;i++){
        bt(i,0);
    }
    return 0;
}