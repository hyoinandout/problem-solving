#include <cstdio>

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int b[n];
    int db[n+1]={0};
    int sdb[n+1]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=1;i<n;i++){
       if(b[i]>b[i-1]){
           db[i] = db[i-1]+(b[i]-b[i-1]);
       }
       else{
           db[i] = db[i-1]+(b[i-1]-b[i]);
        }
    }
    for(int i=0;i<q;i++){
        int s,e;
        scanf("%d %d",&s,&e);
        if(s>e){
            printf("0");
            continue;
        }
        printf("%d\n",db[e-1]-db[s-1]);
    }
    return 0;
}