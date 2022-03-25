#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> arr(n+2,std::vector<int> (m+2,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            std::cin>>arr[i][j];
        }
    }
    // 밑면 + 윗면    
    int result = 2 * n * m;

    //인접 칸에 대하여, 현재칸 높이 < 인접 칸 높이 라면 현재칸 높이 겉넓이 무시, 아니면 현재칸 높이 - 인접칸 높이 만큼 더해주기
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<4;k++)
            {
                int ni = i + dy[k];
                int nj = j + dx[k];
                if(arr[ni][nj] < arr[i][j])
                {
                    result += arr[i][j] - arr[ni][nj];
                }
            }
        }
    }


    // 이렇게 생각하면 경우의 수가 너무 많다.
    // // 행/열별 max 구하기
    // std::vector<int> rowMax(n,0);
    // std::vector<int> colMax(m,0);
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         rowMax[i] = std::max(rowMax[i],arr[i][j]);
    //     }
    // }

    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         colMax[i] = std::max(colMax[i],arr[j][i]);
    //     }
    // }

    // // row에서 본 방향 옆면구하기
    // for(int i=0;i<n;i++)
    // {
    //     result += 2 * rowMax[i];
    // }

    // //column에서 본 방향 옆면 구하기
    // for(int i=0;i<m;i++)
    // {
    //     result += 2 * colMax[i];
    // }

    // //사각지역 겉넓이 구하기 : x>y<z 꼴

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         if(arr[i][j] > arr[i][j+1] && arr[i][j+1] < arr[i][j+2])
    //         {
    //             result += 2*(std::min(arr[i][j],arr[i][j+2])-arr[i][j+1]);
    //         }
    //     }
    // }

    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         if(arr[j][i] > arr[j+1][i] && arr[j+1][i] < arr[j+2][i])
    //         {
    //             result += 2*(std::min(arr[j][i],arr[j+2][i])-arr[j+1][i]);
    //         }
    //     }
    // }


    std::cout<<result<<std::endl;

    return 0;
}