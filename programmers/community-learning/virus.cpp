#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void bfs(int r, int c, int max_virus, vector<vector<int>>& grid)
{
    int maxRow = grid.size();
    int maxColumn = grid[0].size();
    bool visited[maxRow][maxColumn];
    memset(visited,0,sizeof(visited));
    queue<pair<int,int>> q;
    visited[r][c] = true;
    q.push({r,c});
    while(!q.empty())
    {
        int row = q.front().first;
        int column = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nrow = row + dy[i];
            int ncolumn = column + dx[i];
            if(nrow<0 || ncolumn<0 || nrow>=maxRow || ncolumn>=maxColumn)
                continue;
            if(!visited[nrow][ncolumn])
            {
                visited[nrow][ncolumn] = true;
                if(grid[nrow][ncolumn] < max_virus)
                    grid[nrow][ncolumn]+=1;    
                else
                    q.push({nrow,ncolumn});
            }
        }
    }
}

vector<vector<int>> solution(int rows, int columns, int max_virus, vector<vector<int>> queries) {
    vector<vector<int>> answer(rows,vector<int>(columns,0));
    for(auto query: queries)
    {
        int row = query[0]-1;
        int column = query[1]-1;
        if(answer[row][column] == max_virus)
        {
            bfs(row,column,max_virus,answer);
            continue;
        }
        answer[row][column] += 1;
    }
    return answer;
}

int main()
{
    vector<vector<int>> a = solution(3,4,2,{{3,2},{3,2},{2,2},{3,2},{1,4},{3,2},{2,3},{3,1}});
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    // vector<vector<int>> a = solution(1,1,1,{{1,1}});
    // for(int i=0;i<1;i++)
    // {
    //     for(int j=0;j<1;j++)
    //     {
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}