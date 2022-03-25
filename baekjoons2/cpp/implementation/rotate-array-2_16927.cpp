// 모든 레이어의 회전이 딱 들어맞게 나머지를 구할 필요는 없다 (반례: 300 300 1e9 -> lcm 구할 때 시간초과. 오버플로우 등 위험요소가 너무 많음)
// 따라서 각 layer별로 r에 layer에 회전횟수를 나눠준 나머지로 돌려주는 것이 현명하다. 따라서 함수의 분리가 필요하다.
#include <iostream>
#include <vector>
#include <algorithm>

// int f(int a, int b)
// {
//     int c = std::min(a,b);
//     int gcd = 1;

// 번외 : gcd 구하기 (유클리드 호제법)

// int gcd(int a, int b)
// {
//     if(b == 0)
//     {
//         return a;
//     }
//     if(a%b == 0)
//     {
//         return b;
//     }
//     else
//     {
//         return gcd(b,a%b);
//     }
// }



//     for(int i = c; i > 0; i--)
//     {
//         if(a % i == 0 && b % i == 0)
//         {
//             gcd = i;
//             break;
//         }
//     }
//     return (a * b / gcd);
// }

int main()
{
    int n,m,r;
    std::cin>>n>>m>>r;
    std::vector<std::vector<int>> arr(n,std::vector<int> (m,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            std::cin>>arr[i][j];
        }
    }

    int rSize = std::min(n,m)/2;

    // int kSum = 1;
    // int lcm = 2*(n+m-2);
    // for(int k=1;k<=rSize;k++)
    // {
    //     int a = 2*(n+m - 2*kSum);
    //     lcm = f(lcm,a);
    //     kSum += 2;
    // }
    // std::cout<<lcm<<std::endl;
    // r%=lcm;
    for(int k=0;k<rSize;k++)
    {
        int rLeft = r%(2*(n+m-(4*k+2)));
        while(rLeft>0)
        {
            int temp1 = arr[n-1-k][k];
            // 아래로
            for(int i = n-k-1; i > k; i--)
            {
                arr[i][k] = arr[i-1][k];
            }
            // 왼쪽으로
            for(int i = k; i < m-k-1; i++)
            {
                arr[k][i] = arr[k][i+1];
            }
            // 위로
            for(int i = k; i < n-k-1; i++)
            {
                arr[i][m-1-k] = arr[i+1][m-1-k];
            }
            // 오른쪽으로
            for(int i = m-k-1; i > k; i--)
            {
                arr[n-1-k][i] = arr[n-1-k][i-1];
            }
            arr[n-1-k][k+1] = temp1;
            rLeft -= 1;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}