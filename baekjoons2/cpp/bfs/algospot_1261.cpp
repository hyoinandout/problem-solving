#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

int bfs(std::vector<std::vector<int>>& maze,int n, int m)
{
    std::vector<std::vector<int>> mazecopy(n,std::vector<int> (m,10001));
    std::queue<std::pair<int,int>> q;
    q.push(std::pair<int,int> (0,0));
    mazecopy[0][0] = 0;
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)
            {
                continue;
            }
            int cp;
            if(maze[ny][nx] == 1)
            {
                cp = mazecopy[y][x] + 1;
            }
            else
            {
                cp = mazecopy[y][x];
            }
            if(mazecopy[ny][nx] > cp)
            {
                mazecopy[ny][nx] = cp;
                q.push(std::pair<int,int> (ny,nx));
            }
        }
    }
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++)
    //     {
    //         std::cout<<mazecopy[i][j]<<" ";
    //     }
    //     std::cout<<std::endl;
    // }
    return mazecopy[n-1][m-1];
}

int main()
{
    int n,m;
    std::cin>>m>>n;
    std::vector<std::vector<int>> maze(n,std::vector<int> (m,0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%1d",&maze[i][j]);
        }
    }
    std::cout<<bfs(maze,n,m)<<std::endl;
    return 0;
}