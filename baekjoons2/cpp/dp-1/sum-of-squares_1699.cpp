// 반례가 있을지도 모르는 의심이 드면 확신을 얻으려 시도해보자.
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    long long n;
    std::cin>>n;
    std::vector<long long> dp(n+1,100000);

    long long criteria = 2;
    long long prev = 1;
    dp[1] = 1;
    for(long long i = 2; i  <= n; i++)
    {
        long long k = criteria * criteria;
        if(i == k)
        {
            prev = k;
            criteria += 1;
            dp[i] = 1;
            continue;
        }
        for(long long j = 1; j*j <= prev; j++)
        {
            dp[i] = std::min(dp[i],dp[i-j*j] + dp[j*j]);
        }
    }
    std::cout<<dp[n]<<"\n";
    return 0;
}