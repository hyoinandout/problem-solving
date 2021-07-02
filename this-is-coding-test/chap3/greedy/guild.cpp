#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    queue<int> q;
    int cnt=0;
    for(int i=0;i<n;i++){
        q.push(arr[i]);
        if(arr[i]<=q.size()){
            while(!q.empty()){
                q.pop();
            }
            cnt++;
        }
    }
    printf("%d",cnt);
}