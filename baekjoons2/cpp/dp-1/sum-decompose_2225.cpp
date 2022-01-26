#include <iostream>
#include <vector>

int main()
{
    int n,k;
    std::cin>>n>>k;
    std::vector<std::vector<int>> dp(k+1,std::vector<int> (n+1,0));

    for(int i = 0; i <= n; i++)
    {
        dp[1][i] = 1;
    }

    for(int i=2; i<=k; i++)
    {
        for(int j = 0; j<=n; j++)
        {
            for(int k = 0; k <= j; k++)
            {
                dp[i][j] += dp[i-1][j-k]%1000000000;
                dp[i][j] %= 1000000000;
            }
        }
    }

    std::cout<<dp[k][n]%1000000000;
    return 0;
}