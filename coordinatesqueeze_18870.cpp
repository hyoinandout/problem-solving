#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    // set<int> s;
    int arr[n];
    map<int,int> m;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        // s.insert(arr[i]);
        m[arr[i]] = 0;
    }
    int cnt=0;
    for(map<int,int>::iterator iter=m.begin();iter!=m.end();iter++){
        iter->second = cnt;
        cnt++;
    }
    for(int i=0;i<n;i++){
        int k = arr[i];
        printf("%d ", m[k]);
    }
    return 0;
}