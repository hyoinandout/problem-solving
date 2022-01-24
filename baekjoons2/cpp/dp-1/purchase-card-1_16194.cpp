#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin>>n;

    std::vector<int> cardCost(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int x;
        std::cin>>x;
        cardCost[i] = x;
    }

    std::vector<std::vector<int>> dp(n+1,std::vector<int>(n+1,0));

    for(int j = 1; j <= n; j++)
    {
        dp[1][j] = cardCost[1] *j;
    }

    for(int i=2; i<=n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = std::min(dp[i-1][j],dp[i][j-i] + cardCost[i]);
            }
        }
    }

    int minResult = 1e9;
    for(int i = 1; i <= n; i++)
    {
        minResult = std::min(minResult, dp[i][n]);
    }

    std::cout<<minResult;
}