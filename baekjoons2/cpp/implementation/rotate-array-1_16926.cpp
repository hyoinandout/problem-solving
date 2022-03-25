#include <iostream>
#include <vector>
#include <algorithm>

void rotate(std::vector<std::vector<int>>& arr, int r)
{
    int n = arr.size();
    int m = arr[0].size();
    int x = std::min(n,m);
    std::vector<std::vector<int>> arrCopy(n,std::vector<int> (m,0));
    if(r == 0)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                std::cout<<arr[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        return;
    }
    int k = 0;
    while(k < (n - k) && k < (m - k))
    {
        // for(int i = 0; i < n-1; i++)
        // {
        //     arrCopy[i+1][0] = arr[i][0];
        // }
        // for(int i = 0; i < m-1; i++)
        // {
        //     arrCopy[n-1][i+1] = arr[n-1][i];
        // }
        // for(int i = n-1; i > 0; i--)
        // {
        //     arrCopy[i-1][m-1] = arr[i][m-1];
        // }
        // for(int i = m-1; i > 0; i--)
        // {
        //     arrCopy[0][i-1] = arr[0][i];
        // }
        for(int i = k; i < n-1-k; i++)
        {
            arrCopy[i+1][k] = arr[i][k];
        }
        for(int i = k; i < m-1-k; i++)
        {
            arrCopy[n-1-k][i+1] = arr[n-1-k][i];
        }
        for(int i = n-1-k; i > k; i--)
        {
            arrCopy[i-1][m-1-k] = arr[i][m-1-k];
        }
        for(int i = m-1-k; i > k; i--)
        {
            arrCopy[k][i-1] = arr[k][i];
        }
        k += 1;
    }
    rotate(arrCopy,r-1);
}

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
    rotate(arr,r);
}