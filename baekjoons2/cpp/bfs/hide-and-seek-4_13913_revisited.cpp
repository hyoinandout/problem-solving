#include <iostream>
#include <vector>
#include <queue>
#include <deque>

int n,k;
std::vector<int> parent(100001,100001);

int bfs(int n)
{
    parent[n] = n;
    std::queue<int> q;
    q.push(n);
    int cnt = 0;
    while(!q.empty())
    {
        int qSize = q.size();
        for(int i = 0; i < qSize; i++)
        {
            int now = q.front();
            if(now == k)
            {
                return cnt;
            }
            q.pop();
            int sNow = now - 1;
            int aNow = now + 1;
            int mNow = now * 2;
            if(sNow >= 0 && sNow <= 100000 && parent[sNow] == 100001)
            {
                parent[sNow] = now;
                q.push(sNow);
            }
            if(aNow >= 0 && aNow <= 100000 && parent[aNow] == 100001)
            {
                parent[aNow] = now;
                q.push(aNow);
            }
            if(mNow >= 0 && mNow <= 100000 && parent[mNow] == 100001)
            {
                parent[mNow] = now;
                q.push(mNow);
            }
        }
        cnt += 1;
    }
    return 1;
}

int main()
{
    std::cin>>n>>k;
    int seconds = bfs(n);
    std::cout<<seconds<<std::endl;
    std::deque<int> dq;
    dq.push_front(k);
    while(parent[k] != n)
    {
        dq.push_front(parent[k]);
        k = parent[k];
    }
    if(n!=k)
    {
        dq.push_front(n);
    }
    for(auto element:dq)
    {
        std::cout<<element<<" ";
    }
    return 0;
}