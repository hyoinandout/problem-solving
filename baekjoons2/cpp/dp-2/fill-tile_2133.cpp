// 생각의 흐름은 맞았지만 (dp[i-2]와의 연계) 디테일 부족 (중복 수 있다고 해서 돌아갈게 아니라, 조금 더 파봤어야)
// 많이 풀어보면 감이 생긴다니까.. 정진
#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin>>n;
    std::vector<int> dp(n+1,0);
    if(n%2 != 0)
    {
       std::cout<<dp[n]<<std::endl; 
    }
    else
    {
        dp[2] = 3;
        for(int i=4; i<=n; i+=2)
        {
            int sum = 0;
            for(int j = 4; i - j > 0; j+=2)
            {
                sum += dp[i-j];
            }
            sum *= 2;
            dp[i] = 3 * dp[i-2] + sum +2; 
        }
        std::cout<<dp[n]<<std::endl;
    }
    return 0;
}