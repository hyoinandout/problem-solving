#include <cstdio>

int main(){
    int n,k,cnt=0;
    scanf("%d %d",&n,&k);
    while(1){
        if(n%k==0){
            n/=k;
        }
        else{
            --n;
        }
        ++cnt;
        if(n==1)
        break;
    }
    printf("%d",cnt);
    return 0;
}