#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> dp(2,std::vector<int> (n+1,0));
    std::vector<int> result(n+1,0);

    dp[0][1] = 1;
    dp[1][1] = 1;
    dp[0][2] = 2;
    dp[1][2] = 2;
    result[0] = 1;
    result[1] = 3;
    result[2] = 7;

    for(int i = 3; i <= n; i++)
    {
        dp[0][i] = dp[1][i-1] + result[i-2];
        dp[1][i] = dp[0][i-1] + result[i-2];
        result[i] = dp[0][i] + dp[1][i] + result[i-1];
        result[i] %= 9901;
    }

    std::cout<<result[n]%9901<<std::endl;
    
    return 0;
}