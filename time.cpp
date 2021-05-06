#include <cstdio>

int main(){
    int n;
    scanf("%d",&n);
    int cnt=0;
    for(int i=0;i<=n;i++){
        if(i%10==3||i/10==3) continue;
        for(int j=0;j<60;j++){
            if(j%10==3||j/10==3)  continue;
            for(int k=0;k<60;k++){
                if(k%10==3||k/10==3) continue;
                cnt++;
            }
        }
    }
    int k = (n+1)*3600-cnt;
    printf("%d",k);
    return 0;
}