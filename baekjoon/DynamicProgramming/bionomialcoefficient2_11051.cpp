#include <bits/stdc++.h>

using namespace std;


//nCk=n-1Ck+n-1Ck-1
int main()
{
	int N,K;
	cin>>N>>K;
	int arr[N+1][N+1];
	arr[1][0]=1;
	arr[1][1]=1;
	for(int i=2;i<=N;i++)
	{
		arr[i][0]=1;
		arr[i][i]=1;
		for(int j=1;j<i;j++)
		{
			//cout<<"i : "<<i<<" j : "<<j<<endl;
			arr[i][j]=(arr[i-1][j]+arr[i-1][j-1])%10007;
			//cout<<arr[i][j]<<endl;
		}
	}
	cout<<arr[N][K];
}