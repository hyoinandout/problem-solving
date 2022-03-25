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
    // �ظ� + ����    
    int result = 2 * n * m;

    //���� ĭ�� ���Ͽ�, ����ĭ ���� < ���� ĭ ���� ��� ����ĭ ���� �ѳ��� ����, �ƴϸ� ����ĭ ���� - ����ĭ ���� ��ŭ �����ֱ�
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


    // �̷��� �����ϸ� ����� ���� �ʹ� ����.
    // // ��/���� max ���ϱ�
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

    // // row���� �� ���� ���鱸�ϱ�
    // for(int i=0;i<n;i++)
    // {
    //     result += 2 * rowMax[i];
    // }

    // //column���� �� ���� ���� ���ϱ�
    // for(int i=0;i<m;i++)
    // {
    //     result += 2 * colMax[i];
    // }

    // //�簢���� �ѳ��� ���ϱ� : x>y<z ��

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