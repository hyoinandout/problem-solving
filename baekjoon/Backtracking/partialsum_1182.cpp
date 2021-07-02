#include <iostream>

using namespace std;

int n, s, sum, arr[20];
int cnt;

void dfs(int i){
    if(i==n) return;

    if(sum+arr[i]==s) cnt++;

    dfs(i+1);
    sum+=arr[i];
    dfs(i+1);
    sum-=arr[i];
}

int main(){
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dfs(0);
    cout<<cnt<<endl;
}