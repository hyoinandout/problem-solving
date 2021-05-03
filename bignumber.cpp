#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    sort(arr,arr+n);
    int a = m/(k+1);
    int b = m%(k+1);
    printf("%d",arr[n-1]*(a*k+b)+arr[n-2]*a);
    return 0;
}