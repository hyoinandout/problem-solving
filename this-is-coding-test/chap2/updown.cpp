#include <cstdio>
#include <algorithm>
bool compare(int i,int j){
    return i>j;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    std::sort(arr,arr+n,compare);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}