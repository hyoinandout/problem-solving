// 이차원 동적 배열 : vector<int> [n];
// 01 12 23 30 14 -> 41 12 23 30
// 
// 0-1-2-3
//   |
//   4 
// 17 37 47 34 46 35 04 27 -> 04 47 73 34
// 그래프로 치환하면, 거리가 4인 vertex 묶음이 있는가? (사이클 제외)
//   2
//   |
// 1-7-3-5
//   |/
// 0-4-6
// 각 visited 되지 않은 출발점들에 대해 for문 돌면서 bfs 탐색 수행해주고 dist == 4 인순간 탈출.

// 큐라는 것에 너무 매몰되어 bfs라고 생각했었는데.. 반례 생각하니까 아니였고 dfs 였음 (문제 테마가 큐와 그래프임)
// 깊이가 4가 될 때 탈출하자.

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

// int bfs(std::vector<std::vector<int>>& arr,int n)
// {
//     bool visited[n];
//     memset(visited,false,sizeof(visited));
//     // for(int i=0;i<n;i++)
    // {
    //     std::queue<int> q;
    //     int cnt = 0;
    //     // if(!visited[i])
    //     // {
    //         visited[i] = true;
    //         q.push(i);
    //         while(!q.empty())
    //         {
    //             for(int j = 0; j < q.size(); j++)
    //             {
    //                 int now = q.front();
    //                 std::cout<<now<<std::endl;
    //                 q.pop();
    //                 for(int k = 0; k < n; k++)
    //                 {
    //                     if(arr[now][k] == 1 && !visited[k])
    //                     {
    //                         visited[k] = true;
    //                         q.push(k);
    //                     }
    //                 }
    //             }
    //             cnt += 1;
    //             if(cnt == 4)
    //             {
            //         return 1;
            //     }
            // }
        //}
//     }
//     return 0;
// }

bool visited[2000];

void dfs(std::vector<std::vector<int>>& arr,int start, int depth, int n)
{
    if(depth == 4)
    {
        std::cout<<1<<std::endl;
        exit(0);
    }
    for(auto element:arr[start])
    {
        if(!visited[element])
        {
            visited[element]=true;
            dfs(arr,element,depth+1,n);
            visited[element]=false;
        }
    }
    // for(int i = 0; i < n; i++)
    // {
    //     if(arr[start][i] == 1 && !visited[i])
    //     {
    //         visited[i] = true;
    //         dfs(arr,i,depth+1,n);
    //         visited[i] = false;
    //     }
    // }

}

int main()
{
    int n,m;
    std::cin>>n>>m;
    //std::vector<std::vector<int>> adj(n,std::vector<int> (n,0));
    std::vector<std::vector<int>> adj;

    for(int i=0;i<n;i++)
    {
        std::vector<int> a;
        adj.push_back(a);
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        std::cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        // adj[x][y] = 1;
        // adj[y][x] = 1;
    }

    // for(int i=0;i<n;i++)
    // {
    //     for(auto element:adj[i])
    //     {
    //         std::cout<<element<<" ";
    //     }
    //     std::cout<<std::endl;
    // }

    for(int i=0;i<n;i++)
    {
        visited[i] = true;
        dfs(adj,i,0,n);
        visited[i]= false;
    }

    std::cout<<0<<std::endl;
    return 0;
}