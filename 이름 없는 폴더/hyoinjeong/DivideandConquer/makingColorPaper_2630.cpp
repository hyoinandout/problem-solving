#include <cstdio>
int n,cnt[2];
int arr[128][128]={0};
bool ck(int x, int y, int size){
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(arr[i][j]!=arr[x][y]) return false;
        }
    }
    return true;
}
void dc(int x, int y, int size){
    if(ck(x,y,size)){
        cnt[arr[x][y]]++;
        return;
    }
    int div = size/2;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            dc(x+div*i,y+div*j,div);
        }
    }
}


int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    dc(0,0,n);
    printf("%d\n%d",cnt[0],cnt[1]);
    return 0;
}