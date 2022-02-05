// dfs에서 길이 체크하는 거 보고 bfs 인거 눈치 챘어야 한다. (odd cycle의 길이로 판별하려고 하면 너무 많은 케이스를 고려해야 하기 때문에, 홀수(0아니면 1 아니면 무언가가 나오면 안됨)면 바로 리턴해줘야하는 bfs 응용이다)
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
// bool answer = false;
// void dfs(std::vector<int> graph[], int start, bool visited[], int depth[], int level)
// {
//     for(int i=0;i<graph[start].size();i++)
//     {
//         if(!visited[graph[start][i]])
//         {
//             visited[graph[start][i]] = true;
//             depth[graph[start][i]] = level+1;
//             dfs(graph,graph[start][i],visited,depth,level+1);
//             visited[graph[start][i]] = false;
//         }
//         else
//         {
//             if(((level - depth[graph[start][i]]) % 2) == 0)
//             {
//                 answer = true;
//                 return;
//             }
//         }
//         if(answer)
//             return;
//     }
// }

bool bfs(std::vector<int> graph[], int start, int n, int colored[])
{
    std::queue<int> q;

    q.push(start);
    colored[start] = 1;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i = 0; i < graph[now].size(); i++)
        {
            if(colored[graph[now][i]] == 0)
            {
                colored[graph[now][i]] = colored[now] * -1;
                q.push(graph[now][i]);
            }
            else if(colored[graph[now][i]] == colored[now])
            {
                return true;
            }
        }
    }
    return false;
}



int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int k;
    std::cin>>k;
    for(int i = 0; i < k; i++)
    {
        int v, e;
        std::cin>>v>>e;
        std::vector<int> graph[v+1];
        for(int j = 0; j < e; j++)
        {
            int x,y;
            std::cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        bool answer = false;
        int colored[v+1];
        memset(colored,0,sizeof(colored));
        for(int j = 1; j < v+1; j++)
        {
            if(colored[j] == 0)
            {
                answer |= bfs(graph,j,v,colored);
            }
        }
        if(answer)
        {
           std::cout<<"NO"<<std::endl;
        }
        else
        {
            std::cout<<"YES"<<std::endl;
        }
        // std::vector<int> graph[v+1];
        // bool visited[v+1];
        // int depth[v+1];
        // memset(visited,false,sizeof(visited));
        // memset(depth,0,sizeof(depth));
        // answer = false;
        // for(int j = 0; j < e; j++)
        // {
        //     int x, y;
        //     std::cin>>x>>y;
        //     graph[x].push_back(y);
        //     graph[y].push_back(x);
        // }
        // for(int j = 1; j < v+1; j++)
        // {
        //     memset(depth,0,sizeof(depth));
        //     visited[j] = true;
        //     dfs(graph, j, visited, depth, 0);
        //     visited[j] = false;
        //     if(answer)
        //         break;
        // }
        // if(answer)
        // {
        //     std::cout<<"NO"<<std::endl;
        // }
        // else
        // {
        //     std::cout<<"YES"<<std::endl;
        // }
    }
    return 0;
}