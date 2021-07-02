#include <cstdio>
#include <algorithm>
#include <functional>
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    int b[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }

    std::sort(a,a+n);
    std::sort(b,b+n,std::greater<>());

    for(int i=0;i<n;i++){
        if(a[i]<b[i]){
            a[i]=b[i];
            --k;
        }
        if(k==0) break;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    printf("%d",sum);
    return 0;
}