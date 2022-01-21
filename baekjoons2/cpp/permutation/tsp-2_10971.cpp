#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> array(n,std::vector<int>(n,0));
    std::vector<int> permutation_array;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int x;
            std::cin>>x;
            array[i][j] = x;
        }
    }

    for(int i = 0; i < n; i++){
        permutation_array.push_back(i);
    }

    long long minSum = 20000001;
    do
    {
        long long sum = 0;
        permutation_array.push_back(permutation_array[0]);
        for(int i = 0; i < n; i++)
        {
            if(array[permutation_array[i]][permutation_array[i+1]] == 0)
            {
                sum = 20000001;
                break;
            }
            sum += array[permutation_array[i]][permutation_array[i+1]];
        }
        minSum = std::min(minSum,sum);
        permutation_array.pop_back();
    }while(std::next_permutation(permutation_array.begin(),permutation_array.end()));
    std::cout<<minSum;
}