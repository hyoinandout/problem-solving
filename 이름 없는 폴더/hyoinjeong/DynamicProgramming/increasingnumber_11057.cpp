#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int arr[N+1][10]={0};
	for(int i=0;i<10;i++)
	{
		arr[1][i]=1;
	}
	for(int i=2;i<=N;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int k=j;k<10;k++)
			{
				//cout<<"i : "<<i<<" j : "<<j<<" k : "<<k<<endl;
				arr[i][j]=(arr[i][j]+arr[i-1][k])%10007;
				//cout<<arr[i][j]<<endl;
			}
		}
	}
	int sum=0;
	for(int i=0;i<10;i++)
	{
		sum = (sum+arr[N][i])%10007;
	}
	cout<<sum;
}