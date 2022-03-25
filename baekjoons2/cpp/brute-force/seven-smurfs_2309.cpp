#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> answerArr;
bool visited[9];

void dfs(int i, int arr[], int cnt, int sum)
{
    if(cnt == 7 && (sum == 100))
    {
        for(auto answer:answerArr)
        {
            std::cout<<answer<<std::endl;
        }
        exit(0);
    }
    for(int j=i;j<9;j++)
    {
        if(!visited[j])
        {
            visited[j] = true;
            answerArr.push_back(arr[j]);
            dfs(j,arr,cnt+1,sum+arr[j]);
            visited[j] = false;
            answerArr.pop_back();
        }
    }
}

int main()
{
    int arr[9];
    for(int i=0;i<9;i++)
    {
        std::cin>>arr[i];
    }
    
    std::sort(arr,arr+9);
    dfs(0,arr,0,0);
}