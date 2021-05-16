#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k,d;
	cin>>n>>k>>d;
	int start[k],end[k],rule[k];
	for(int i=0;i<k;i++)
	{
		cin>>start[i]>>end[i]>>rule[i];
	}
	
	
	int low=1;
	int high=n;
	
	while(low<=high)
	{
		//cout<<"low : "<<low<<" high : "<<high<<endl;
		long long cnt=0;
		int mid = (low+high)/2;
		//cout<<"mid : "<<mid<<endl;
		for(int i=0;i<k;i++)
		{
			// if(start[i]>mid)
			// 	continue;
			if(mid>=start[i])
			{
				cnt+=(min(mid,end[i])-start[i])/rule[i]+1;
			}
		}
		//cout<<"cnt : "<<cnt<<endl;
		if(cnt<d)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	cout<<low;
}