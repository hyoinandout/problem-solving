#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> arr(n,std::vector<int> (n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cin>>arr[i][j];
        }
    }
    int result = 30001;
    for(int i=0;i<n*n-1;i++)
    {
        for(int j=i+1;j<n*n-1;j++)
        {
            for(int k=j+1;k<n*n-1;k++)
            {
                int iy = i / n;
                int ix = i % n;
                int jy = j / n;
                int jx = j % n;
                int ky = k / n;
                int kx = k % n;

                if(iy < 1 || jy < 1 || ky < 1 || ix < 1 || jx < 1 || kx < 1|| 
                iy >= n - 1 || jy >= n - 1 || ky >= n - 1 || ix >= n - 1 || jx >= n - 1 || kx >= n - 1)
                {
                    continue;
                }
                else if((abs(ix-jx)<= 1 && abs(iy-jy) <= 1) || (abs(jx-kx) <= 1 && abs(jy-ky) <= 1) || 
                (abs(ix-kx) <= 1 && abs(iy-ky) <= 1)||
                (abs(ix-jx) + abs(iy-jy) == 2) || (abs(jx-kx) + abs(jy-ky) == 2) || 
                (abs(ix-kx) + abs(iy-ky) == 2))
                {
                    continue;
                }
                else
                {
                    int dx[5] = {-1,1,0,0,0};
                    int dy[5] = {0,0,-1,1,0};

                    int sum = 0;
                    for(int m=0;m<5;m++)
                    {
                        int ny = iy + dy[m];
                        int nx = ix + dx[m];
                        sum += arr[ny][nx];
                    }
                    for(int m=0;m<5;m++)
                    {
                        int ny = jy + dy[m];
                        int nx = jx + dx[m];
                        sum += arr[ny][nx];
                    }
                    for(int m=0;m<5;m++)
                    {
                        int ny = ky + dy[m];
                        int nx = kx + dx[m];
                        sum += arr[ny][nx];
                    }
                    if(sum < result)
                    {
                        //std::cout<<i<<" "<<j<<" "<<k<<std::endl;
                        result = sum;
                    }
                }
            }
        }
    }
    std::cout<<result<<std::endl;
}