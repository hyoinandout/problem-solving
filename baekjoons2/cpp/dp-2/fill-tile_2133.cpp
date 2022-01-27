// ������ �帧�� �¾����� (dp[i-2]���� ����) ������ ���� (�ߺ� �� �ִٰ� �ؼ� ���ư��� �ƴ϶�, ���� �� �ĺþ��)
// ���� Ǯ��� ���� ����ٴϱ�.. ����
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