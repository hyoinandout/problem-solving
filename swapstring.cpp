#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s[0]-'0';
    int arr[2];
    arr[0]=0;
    arr[1]=0;
    arr[n]=1;
    for(int i=0;i<s.length();i++){
        int d  = s[i]-'0';
        if(d!=n){
            if(d==0){
                arr[0]+=1;
            }
            else{
                arr[1]+=1;
            }
            n=d;
        }
    }
    int result;
    if(arr[0]>arr[1]){
        printf("%d",arr[1]);
    }
    else{
        printf("%d",arr[0]);
    }
    
    return 0;
}