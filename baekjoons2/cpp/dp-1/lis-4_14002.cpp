// 기억했으니 됐다. (가장 끝 index가 어디일 것이냐?)
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin>>n;
    std::vector<int> array;
    std::vector<int> dp(n,1);
    for(int i = 0; i < n; i++)
    {
        int x;
        std::cin>>x;
        array.push_back(x);
    }
    for(int i = 1; i< n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(array[i] > array[j])
            {
                dp[i] = std::max(dp[i],dp[j] + 1);
            }
        }
    }
    int index = std::max_element(dp.begin(),dp.end()) - dp.begin();
    int result = *std::max_element(dp.begin(),dp.end());
    std::cout<<result<<"\n";

    std::vector<int> answer;
    answer.push_back(index);
    for(int i = index; i >= 0; i--)
    {
        if(dp[i] == result -1)
        {
            answer.push_back(i);
            result -= 1;
        }
    }

    std::reverse(answer.begin(),answer.end());
    for(auto element:answer)
    {
        std::cout<<array[element]<<" ";
    }
    return 0;
}