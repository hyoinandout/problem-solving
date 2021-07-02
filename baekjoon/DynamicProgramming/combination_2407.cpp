// #include <cstdio>
// #include <algorithm>
// int n,m;
// long long int dp[101][101]={0};
// int main(){
//     scanf("%d %d",&n,&m);
//     dp[1][0]=1;
//     dp[1][1]=1;
//     for(int i=2;i<=n;i++){
//         dp[i][0]=1;
//         for(int j=1;j<=m;j++){
//             dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
//         }
//     }
    
//     printf("%lld",dp[n][m]);
// }
// big integer 구현
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string dp[101][101]={};
string add(string a, string b){
    int sum=0;
    string result;
    while(!a.empty()||!b.empty()||sum){
        if(!a.empty()){
            sum+=a.back()-'0';
            a.pop_back();
        }
        if(!b.empty()){
            sum+=b.back()-'0';
            b.pop_back();
        }
        result.push_back((sum%10)+'0');
        sum/=10;
    }
    reverse(result.begin(),result.end());
    return result;
}

string combination(int n, int m){
    if(n==m||m==0) return "1";
    if(dp[n][m]!="") return dp[n][m];
    return dp[n][m]=add(combination(n-1,m-1),combination(n-1,m));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    cout<<combination(n,m);
}