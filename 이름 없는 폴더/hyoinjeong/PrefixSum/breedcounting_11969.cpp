#include <cstdio>

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int f[n+1]={0},s[n+1]={0},t[n+1]={0};
    int num;
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        if(num==1){
            f[i]=f[i-1]+1;
            s[i]=s[i-1];
            t[i]=t[i-1];
        }
        else if(num==2){
            s[i]=s[i-1]+1;
            f[i]=f[i-1];
            t[i]=t[i-1];
        }
        else{
            t[i]=t[i-1]+1;
            f[i]=f[i-1];
            s[i]=s[i-1];
        }
    }
    for(int i=0;i<q;i++){
        int st,en;
        scanf("%d %d",&st,&en);
        printf("%d %d %d\n",f[en]-f[st-1],s[en]-s[st-1],t[en]-t[st-1]);
    }
    return 0;
}