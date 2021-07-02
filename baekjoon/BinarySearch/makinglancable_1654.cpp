#include <bits/stdc++.h>
using namespace std;

int main()
{
	int K,N;
	cin>>K>>N;
	long long wire[K];
	long long wiresum=0;
	for(int i=0;i<K;i++)
	{
		cin>>wire[i];
		wiresum+=wire[i];
	}

	long long low=1, high=*max_element(wire,wire+K);
	
	while(low<=high)
	{
		long long mid = (low+high)/2;
		long long cnt=0;
		for(int i=0;i<K;i++)
		{
			if(wire[i]/mid)
			{
				cnt+=wire[i]/mid;
			}
		}
		if(cnt<N)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	cout<<high;
	return 0;
}