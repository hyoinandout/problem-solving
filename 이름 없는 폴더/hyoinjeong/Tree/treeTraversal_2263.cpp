#include <cstdio>
int in[100001],post[100001],idx[100001];
void pre(int inbegin, int inend, int postbegin, int postend){
    if(inbegin>inend||postbegin>postend) return;
    int root = post[postend];
    printf("%d ",root);
    pre(inbegin,idx[root]-1,postbegin,postbegin+idx[root]-inbegin-1);
    pre(idx[root]+1,inend,postbegin+idx[root]-inbegin,postend-1);
}
int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&post[i]);
    }
    for(int i=0;i<n;i++){
        idx[in[i]]=i;
    }
    pre(0,n-1,0,n-1);
    printf("\n");
    return 0;
}