// visited 배열을 전역으로 빼주는 이유 : stack
// bool이 1바이트인 이유 : 주소포함
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
bool visited[2001][2001];

int bfs(int s)
{
    // memset(visited,0,sizeof(visited));
    std::queue<std::pair<int,int>> q;
    q.push(std::pair<int,int> (1,0));
    visited[1][0] = true;
    bool flag = false;
    int cnt = 0;
    while(!q.empty())
    {
        int qSize = q.size();
        for(int i = 0; i < qSize; i++)
        {
            int monitor = q.front().first;
            int clipboard = q.front().second;
            q.pop();
            if(monitor == s)
            {
                flag = true;
            }
            int clipboard_overlapped = monitor;
            int monitor_appended = monitor + clipboard;
            int monitor_sub1 = monitor - 1;
            if(monitor < 2001 || clipboard_overlapped < 2001)
            {
                if(!visited[monitor][clipboard_overlapped])
                {
                    visited[monitor][clipboard_overlapped] = true;
                    q.push(std::pair<int,int> (monitor, clipboard_overlapped));
                }
            }
            if(monitor_appended < 2001 && clipboard < 2001)
            {
                if(!visited[monitor_appended][clipboard] && clipboard != 0)
                {
                    visited[monitor_appended][clipboard] = true;
                    q.push(std::pair<int,int> (monitor_appended, clipboard));
                }
            }
            if(monitor_sub1 >= 0)
            {
                if(!visited[monitor_sub1][clipboard])
                {
                    visited[monitor_sub1][clipboard] = true;
                    q.push(std::pair<int,int> (monitor_sub1, clipboard));
                }
            }
        }
        if(flag)
        {
            break;
        }
        cnt += 1;
    }
    return cnt;
}

int main()
{
    int s;
    std::cin>>s;
    std::fill(&visited[0][0],&visited[2000][2001],false);
    std::cout<<bfs(s)<<std::endl;
    return 0;
}