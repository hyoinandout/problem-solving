#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,M;
	cin>>N>>M;
	int lesson[N];
	long long ltsum=0;
	for(int i=0;i<N;i++)
	{
		cin>>lesson[i];
		ltsum+=lesson[i];
	}

	long long low=*max_element(lesson,lesson+N), high=ltsum;
	while(low<=high)
	{
		long long mid = (low+high)/2;
		long long cnt=0, sum=0;
		for(int i=0;i<N;i++)
		{
			if(sum+lesson[i]>mid)
			{
				sum=0;
				cnt++;
			}
			sum+=lesson[i];
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