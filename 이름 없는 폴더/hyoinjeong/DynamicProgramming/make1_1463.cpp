#include <bits/stdc++.h>

using namespace std;

int dp[1000000];

int make1(int n)
{
	if(n==1)
	{
		return 0;
	}
	if(dp[n]!=-1)
	{
		return dp[n];
	}
	int result = make1(n-1)+1;
	if(n%3==0)
	{
		result=min(result, make1(n/3)+1);
	}
	if(n%2==0)
	{
		result=min(result, make1(n/2)+1);
	}
	dp[n]=result;
	return result;
}



int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		dp[i]=-1;
	}
	cout<<make1(n)<<endl;
}