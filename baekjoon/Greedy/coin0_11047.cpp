#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N,K;
	cin>>N>>K;
	int coin[N];
	for(int i=0;i<N;i++)
	{
		cin>>coin[i];
	}
	int count=0;
	for(int j=N-1;j>=0;j--)
	{
		if(K%coin[j]==K)
			continue;
		else
		{
			count+=K/coin[j];
			K=K%coin[j];
		}
		if(K==0)
			break;
	}
	cout<<count<<endl;
}