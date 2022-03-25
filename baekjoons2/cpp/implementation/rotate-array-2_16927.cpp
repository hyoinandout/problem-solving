// ��� ���̾��� ȸ���� �� ���°� �������� ���� �ʿ�� ���� (�ݷ�: 300 300 1e9 -> lcm ���� �� �ð��ʰ�. �����÷ο� �� �����Ұ� �ʹ� ����)
// ���� �� layer���� r�� layer�� ȸ��Ƚ���� ������ �������� �����ִ� ���� �����ϴ�. ���� �Լ��� �и��� �ʿ��ϴ�.
#include <iostream>
#include <vector>
#include <algorithm>

// int f(int a, int b)
// {
//     int c = std::min(a,b);
//     int gcd = 1;

// ���� : gcd ���ϱ� (��Ŭ���� ȣ����)

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
            // �Ʒ���
            for(int i = n-k-1; i > k; i--)
            {
                arr[i][k] = arr[i-1][k];
            }
            // ��������
            for(int i = k; i < m-k-1; i++)
            {
                arr[k][i] = arr[k][i+1];
            }
            // ����
            for(int i = k; i < n-k-1; i++)
            {
                arr[i][m-1-k] = arr[i+1][m-1-k];
            }
            // ����������
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