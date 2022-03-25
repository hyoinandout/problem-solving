// 비용 + 두 파일의 합을 계속 누적해서 계산 -> 당연히 답보다 큰 값이 나옴 (dp[j][j+i] = 2*dp[j][l] + 2*dp[l][j+i] , 처음 파일일때는 계수를 1로 해서 계산했음 : 비용과 두 파일 크기의 누적 합)
// 문제: 두 개의 파일을 합칠 때 필요한 비용(시간 등)이 두 파일 크기의 합이라고 가정할 때, 최종적인 한 개의 파일을 완성하는데 필요한 비용의 총 합을 계산하시오.
// 즉 dp[j][j+i] = min(dp[j][j+i],dp[j][l]+dp[l][j+i]+arr[j+i]-arr[j])로, 비용의 최소를 저장하며 두 파일 크기의 합은 누적합으로 고정값이니 더해준다. (답 = 두 파일을 합칠때 필요한 최소비용(그 범위까지 가기에 최소의 비용) + 두 파일 크기의 합)
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int k;
        cin>>k;
        vector<vector<int>> dp(k+1,vector<int> (k+1,0));
        vector<int> arr(k+1,0);
        for(int j=0;j<k;j++)
        {
            int page;
            cin>>page;
            arr[j+1] = arr[j] + page;
        }

        for(int i=2;i<k+1;i++)
        {
            for(int j=0;j<k-i+1;j++)
            {
                int sum = 987564321;
                for(int l=j+1;l<j+i;l++) 
                {
                    //int cmp = 2*dp[j][l] + 2*dp[l][j+i];
                    int cmp = dp[j][l] + dp[l][j+i];
                    // if(l == j+1)
                    // {
                    //     cmp -= dp[j][l];
                    // }
                    // if(l == j+i-1)
                    // {
                    //     cmp -= dp[l][j+i];
                    // }
                    if(cmp < sum)
                    {
                        sum = cmp;
                    }
                }
                dp[j][j+i] = sum + arr[j+i] - arr[j];
            }
        }
        // for(int i=0;i<k+1;i++)
        // {
        //     for(int j=0;j<k+1;j++)
        //     {
        //         cout<<dp[i][j]<<"   ";
        //     }
        //     cout<<endl;
        // }
        cout<<dp[0][k]<<endl;
    }
}