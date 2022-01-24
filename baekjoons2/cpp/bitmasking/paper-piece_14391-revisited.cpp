// 비트마스킹 이용한 풀이
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

int n,m;
int maxSum = 0;
bool visited[5][5];
int caseSum = 0;
std::vector<std::vector<int>> array(5,std::vector<int> (5,0));

int main()
{
    std::cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j = 0; j<m; j++)
        {
            int a;
            scanf("%1d",&a);
            array[i][j] = a;
        }
    }

// 가로 0, 세로 1
    for(int k = 0; k < (1<<n*m); k++)
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            int prev = 0;
            for(int j = 0; j < m; j++)
            {
                int s = i * m + j;
                if((k & (1<<s)) == 0)
                {
                    prev = prev * 10 + array[i][j];
                }
                else
                {
                    sum += prev;
                    prev = 0;
                }
            }
            sum += prev;
        }

        for(int j = 0; j < m; j++)
        {
            int prev = 0;
            for(int i = 0; i < n; i++)
            {
                int s = i * m + j;
                if((k & (1<<s)) != 0)
                {
                    prev = prev * 10 + array[i][j];
                }
                else
                {
                    sum += prev;
                    prev = 0;
                }
            }
            sum += prev;
        }
        maxSum = std::max(maxSum, sum);
    }
    std::cout<<maxSum;
}