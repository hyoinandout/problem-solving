//발표문제
#include <bits/stdc++.h>

using namespace std;
int main(){
    string s;
    cin>>s;
    int result = s[0]-'0';
    // int i=0;
    // int n=1;
    // while(1){
    //     scanf("%1d",&arr[i]);        
    //     if(!isdigit(arr[i])){
    //         n=i;
    //         break;
    //     } 
    //     i++;
    // }
    
    for(int i=1;i<s.length();i++){
        int k = s[i]-'0';
        if(k==0||k==1||result==0){
            result+=k;
        }
        else{
            result*=k;
        }
    }
    printf("%d",result);
    return 0;
}