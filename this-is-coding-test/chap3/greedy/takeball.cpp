#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int cnt=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]!=arr[j]){
                cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}