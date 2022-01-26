// ÃÊ±ê°ª¿¡ ´ëÇÑ °í¹Î
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin>>n;
    std::vector<int> arr;
    for(int i = 0; i< n; i++)
    {
        int x;
        std::cin>>x;
        arr.push_back(x);
    }

    std::vector<int> dp(n,0);

    for(int i = 0; i < n; i++)
    {
        dp[i] = arr[i];
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j])
            {
                dp[i] = std::max(dp[i],dp[j] + arr[i]);
            }
        }
    }

    std::cout<<*std::max_element(dp.begin(),dp.end())<<std::endl;
    return 0;
}