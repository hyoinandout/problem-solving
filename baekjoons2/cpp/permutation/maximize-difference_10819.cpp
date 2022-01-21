#include <iostream>
#include <vector>

int n;
std::vector<int> inputArray;
std::vector<int> array;
int maxResult = 0;
bool visited[9];

void f(int cnt)
{
    if(cnt == n)
    {
        int sum = 0;
        for(int i = 0; i < n-1; i++)
        {   
            sum += std::abs(array[i] - array[i+1]);
        }
        maxResult = std::max(maxResult,sum);
    }
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            array.push_back(inputArray[i]);
            f(cnt+1);
            visited[i] = false;
            array.pop_back();
        }
    }
}

int main()
{
    std::cin>>n;
    for(int i = 0; i < n; i++)
    {
        int x;
        std::cin>>x;
        inputArray.push_back(x);
    }
    f(0);
    std::cout<<maxResult;
}