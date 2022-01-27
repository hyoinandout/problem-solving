// 또 아이디어는 맞았는데 디테일에서 너무 어려움을 겪음
// 계속 풀어가자.(중복경우 생각해주고, 이번거는 연속합 1 알고리즘도 이해한 줄 알았는데 아니여서 그런 것 같다)
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin>>n;
    std::vector<int> arr(n,0);
    std::vector<std::vector<int>> dp(2,std::vector<int> (n,0));
    for(int i=0;i<n;i++)   
    {
        int x;
        std::cin>>x;
        arr[i] = x;
        dp[0][i] = x;
        dp[1][i] = x;
    }
    int answer = arr[0];
    for(int i=1;i<n;i++)
    {
        dp[0][i] = std::max(dp[0][i-1]+arr[i],arr[i]);
        dp[1][i] = std::max(dp[0][i-1],dp[1][i-1] + arr[i]);
        answer = std::max(answer,std::max(dp[0][i],dp[1][i]));
    }

    std::cout<<answer<<std::endl;
    
    return 0;
}