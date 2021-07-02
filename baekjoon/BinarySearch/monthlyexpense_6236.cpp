#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,M;
	cin>>N>>M;
	int expense[N];
	long long moneysum=0;
	for(int i=0;i<N;i++)
	{
		cin>>expense[i];
		moneysum+=expense[i];
	}

	long long low=*max_element(expense,expense+N), high=moneysum;
	while(low<=high)
	{
		long long mid = (low+high)/2;
		long long cnt=0, sum=0;
		for(int i=0;i<N;i++)
		{
			if(sum+expense[i]>mid)
			{
				sum=0;
				cnt++;
			}
			sum+=expense[i];
		}
		if(sum!=0)
		{
			cnt++;
		}
		if(cnt<=M)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	cout<<low;
	return 0;
}