#include <cstdio>
int n,m;
int arr[8]={0};
void bt(int x, int y){
    arr[y]=x;
    for(int j=x+1;j<=n;j++){
        bt(j,y+1);
    }
    if(y==m-1){
        for(int i=0;i<m;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }

    
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        bt(i,0);
    }
    return 0;
}