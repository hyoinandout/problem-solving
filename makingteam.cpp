#include <cstdio>
int parent[100001];
int find_parent(int a){
    if(parent[a]!=a){
        parent[a] = find_parent(parent[a]);
    }
    return parent[a];
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    while(m--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a){
            if(parent[b]==parent[c]){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
        else{
            parent[b]<parent[c]? parent[c]=parent[b]:parent[b]=parent[c];
            for(int i=0;i<=n;i++){
                parent[i] = find_parent(i);
            }
        }
    }
    return 0;
}