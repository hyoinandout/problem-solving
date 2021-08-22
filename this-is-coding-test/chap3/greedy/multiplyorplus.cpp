//발표문제
#include <bits/stdc++.h>

using namespace std;
int main(){
    string s;
    cin>>s;
    int result = s[0]-'0';
    // int i=0;
    // int n=1;
    // char arr[1024];
    // memset(arr,0,sizeof(arr));
    // while(1){
    //     scanf("%c",&arr[i]);
    //     printf("%c",arr[i])       ;
    //     if(isdigit(arr[i])==0){
    //         n=i;
    //         break;
    //     } 
    //     i++;
    // }
    // printf("%d\n",n);
    // for(int i=0;i<10;i++){
    //     printf("%c ",arr[i]);
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