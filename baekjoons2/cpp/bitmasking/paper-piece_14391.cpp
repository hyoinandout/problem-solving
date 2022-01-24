// 함수 콜스택을 고려할때, 이런 식의 호출은 무조건 시간초과
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

int n,m;
int maxSum = 0;
bool visited[5][5];
int caseSum = 0;
std::vector<std::vector<int>> array(5,std::vector<int> (5,0));

void rightAppend(int y, int x, int prev)
{
    if(x<m-1)
    {
        rightAppend(y, x+1, prev*10 + array[y][x]);
        separate(y,x+1,prev*10 + array[y][x]);
    }
    else
    {
        separate(y,x,prev*10 + array[y][x]);
    }
}

void downAppend(int y, int x, int prev)
{
    if(y<n-1)
    {   
        separate(y+1,x,prev*10 + array[y][x]);
        downAppend(y+1, x, prev*10 + array[y][x]);
    }
    else
    {
        separate(y,x,prev*10 + array[y][x]);
    }
}

void separate(int y, int x, int prev)
{
    caseSum += prev;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j])
            {
                start(i,j);
                return;
            }
        }
    }  
    caseSum -= prev;
}

void start(int y, int x)
{
    visited[y][x] = true;
    rightAppend(y,x,array[y][x]);
    separate(y,x,array[y][x]);
    downAppend(y,x,array[y][x]);
    visited[y][x] = false;;
}

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
    start(0,0);
    std::cout<<maxSum;
}