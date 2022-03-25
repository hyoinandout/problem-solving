#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n,m,r;
    std::cin>>n>>m>>r;
    std::vector<std::vector<int>> arr(n,std::vector<int> (m,0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cin>>arr[i][j];
        }
    }
    for(int i = 0; i < r; i++)
    {
        int cmd;
        std::cin>>cmd;
        int y = arr.size();
        int x = arr[0].size();
        std::vector<std::vector<int>> arrCopy(x,std::vector<int> (y,0));
        std::vector<std::vector<int>> arrHalfCopy1(y/2,std::vector<int> (x/2,0));
        std::vector<std::vector<int>> arrHalfCopy2(y/2,std::vector<int> (x/2,0));

        switch (cmd)
        {
            case 1:
                for(int j = 0; j < y/2; j++)
                {
                    arr[j].swap(arr[y-j-1]);
                    // std::vector<int> temp = arr[j];
                    // arr[j] = arr[n-j-1];
                    // arr[n-j-1] = temp;
                }
                break;
            case 2:
                for(int j = 0; j < y; j++)
                {
                    for(int k = 0; k < x/2; k++)
                    {
                        std::swap(arr[j][k],arr[j][x-1-k]);
                    }
                }
                break;
            case 3:
                for(int j = 0; j < x; j++)
                {
                    for(int k = 0; k < y; k++)
                    {
                        arrCopy[j][k] = arr[y-k-1][j];
                    }
                }
                arr = arrCopy;
                break;
            case 4:
                for(int j = 0; j < x; j++)
                {
                    for(int k = 0; k < y; k++)
                    {
                        arrCopy[j][k] = arr[k][x-j-1];
                    }
                }
                arr = arrCopy;
                break;
            case 5:
                // 1 copy
                for(int j = 0; j < y/2; j++)
                {
                    for(int k = 0; k < x/2; k++)
                    {
                        arrHalfCopy1[j][k] = arr[j][k];
                    }
                }
                // 4-> 1
                for(int j = 0; j < y/2; j++)
                {
                    for(int k = 0; k < x/2; k++)
                    {
                        arr[j][k] = arr[j+(y/2)][k];
                    }
                }
                // 2 copy
                for(int j = 0; j < y/2; j++)
                {
                    for(int k = 0; k < x/2; k++)
                    {
                        arrHalfCopy2[j][k] = arr[j][k+(x/2)];
                    }
                }
                // 1 -> 2
                for(int j = 0; j < y/2; j++)
                {
                    for(int k = x/2; k < x; k++)
                    {
                        arr[j][k] = arrHalfCopy1[j][k-x/2];
                    }
                }
                //3copy
                for(int j = 0; j < y/2; j++)
                {
                    for(int k = 0; k < x/2; k++)
                    {
                        arrHalfCopy1[j][k] = arr[j+(y/2)][k+(x/2)];
                    }
                }
                // 2 -> 3
                for(int j = y/2; j < y; j++)
                {
                    for(int k = x/2; k < x; k++)
                    {
                        arr[j][k] = arrHalfCopy2[j-(y/2)][k-(x/2)];
                    }
                }
                
                // 3 -> 4
                for(int j = y/2; j < y; j++)
                {
                    for(int k = 0; k < x/2; k++)
                    {
                        arr[j][k] = arrHalfCopy1[j-(y/2)][k];
                    }
                }
                break;
            case 6:
                // 1 copy
                for(int j = 0; j < y/2; j++)
                {
                    for(int k = 0; k < x/2; k++)
                    {
                        arrHalfCopy1[j][k] = arr[j][k];
                    }
                }
                // 2 -> 1
                for(int j = 0; j < y/2; j++)
                {
                    for(int k = 0; k < x/2; k++)
                    {
                        arr[j][k] = arr[j][k+(x/2)];
                    }
                }
                // 4 copy
                for(int j = 0; j < y/2; j++)
                {
                    for(int k = 0; k < x/2; k++)
                    {
                        arrHalfCopy2[j][k] = arr[j+(y/2)][k];
                    }
                }
                // 1 -> 4
                for(int j = y/2; j < y; j++)
                {
                    for(int k = 0; k < x/2; k++)
                    {
                        arr[j][k] = arrHalfCopy1[j-(y/2)][k];
                    }
                }
                //3copy
                for(int j = 0; j < y/2; j++)
                {
                    for(int k = 0; k < x/2; k++)
                    {
                        arrHalfCopy1[j][k] = arr[j+(y/2)][k+(x/2)];
                    }
                }
                // 4 -> 3
                for(int j = y/2; j < y; j++)
                {
                    for(int k = x/2; k < x; k++)
                    {
                        arr[j][k] = arrHalfCopy2[j-(y/2)][k-(x/2)];
                    }
                }
                
                // 3 -> 2
                for(int j = 0; j < y/2; j++)
                {
                    for(int k = x/2; k < x; k++)
                    {
                        arr[j][k] = arrHalfCopy1[j][k-(x/2)];
                    }
                }
                break;
            default:
                break;
        }
    }

    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
        {
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}