// ��� + �� ������ ���� ��� �����ؼ� ��� -> �翬�� �亸�� ū ���� ���� (dp[j][j+i] = 2*dp[j][l] + 2*dp[l][j+i] , ó�� �����϶��� ����� 1�� �ؼ� ������� : ���� �� ���� ũ���� ���� ��)
// ����: �� ���� ������ ��ĥ �� �ʿ��� ���(�ð� ��)�� �� ���� ũ���� ���̶�� ������ ��, �������� �� ���� ������ �ϼ��ϴµ� �ʿ��� ����� �� ���� ����Ͻÿ�.
// �� dp[j][j+i] = min(dp[j][j+i],dp[j][l]+dp[l][j+i]+arr[j+i]-arr[j])��, ����� �ּҸ� �����ϸ� �� ���� ũ���� ���� ���������� �������̴� �����ش�. (�� = �� ������ ��ĥ�� �ʿ��� �ּҺ��(�� �������� ���⿡ �ּ��� ���) + �� ���� ũ���� ��)
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