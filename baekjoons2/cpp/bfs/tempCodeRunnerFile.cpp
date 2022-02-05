#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

int n,k;
std::vector<int> answer;
bool visited[100001];
bool dvisited[100001];
int answerTime;
bool answerFlag= false;

int bfs()
{
    std::queue<int> q;
    std::fill(visited,visited+100001,false);
    q.push(n);
    int cnt = 0;
    bool flag = false;
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            int x = q.front();
            if(x == k)
            {
                flag = true;
            }
            q.pop();
            int sx = x-1;
            int ax = x+1;
            int mx = x*2;
            if(sx >= 0 && sx <= 100000 && !visited[sx])
            {
                visited[sx]=true;
                q.push(sx);
            }
            if(ax >= 0 && ax <= 100000 && !visited[ax])
            {
                visited[ax]=true;
                q.push(ax);
            }
            if(mx >= 0 && mx <= 100000 && !visited[mx])
            {
                visited[mx]=true;
                q.push(mx);
            }
        }
        if(flag)
        {
            if(n==k)
            {
                return 2;
            }
            break;
        }
        cnt += 1;
    }
    return cnt;
}

void dfs(int x, int nowTime)
{
    if(nowTime > answerTime)
    {
        return;
    }
    if(nowTime == answerTime && x == k && !answerFlag)
    {
        for(auto element:answer)
        {
            std::cout<<element<<" ";
        }
        std::cout<<std::endl;
        answerFlag = true;
        return;
    }
    int sx = x-1;
    int ax = x+1;
    int mx = x*2;
    if(sx >= 0 && sx <= 100000 && !dvisited[sx])
    {
        dvisited[sx]=true;
        answer.push_back(sx);
        dfs(sx,nowTime+1);
        dvisited[sx]=false;
        answer.pop_back();
    }
    if(ax >= 0 && ax <= 100000 && !dvisited[ax])
    {
        dvisited[ax]=true;
        answer.push_back(ax);
        dfs(ax,nowTime+1);
        dvisited[ax]=false;
        answer.pop_back();
    }
    if(mx >= 0 && mx <= 100000 && !dvisited[mx])
    {
        dvisited[mx]=true;
        answer.push_back(mx);
        dfs(mx,nowTime+1);
        dvisited[mx]=false;
        answer.pop_back();
    }
}


int main()
{
    std::cin>>n>>k;
    answerTime = bfs();
    std::cout<<answerTime<<std::endl;
    dfs(n,0);
}