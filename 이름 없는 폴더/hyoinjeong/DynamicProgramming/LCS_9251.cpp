//1차 : 재귀
//2차 : 이런 알고리즘이 있답니다.. LCS
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    string a, b;    
    cin>>a>>b;
    int dp[a.length()+1][b.length()+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=a.length();i++){
        for(int j=1;j<=b.length();j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
        }
    }
    cout<<dp[a.length()][b.length()];
    return 0;
}