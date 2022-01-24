#include <iostream>
#include <vector>

int main()
{
    int t;
    std::cin>>t;
    std::vector<long long> dp(1000001,0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < 1000001; i++)
    {
        dp[i] = ((dp[i-1] % 1000000009 + dp[i-2] % 1000000009) % 1000000009 + dp[i-3] % 1000000009) % 1000000009;
    }
    for(int i=0;i<t;i++)
    {
        int x;
        std::cin>>x;
        std::cout<<dp[x]<<"\n";
    }
    return 0;
}